#include "Sandik.hpp"
#include "cmath"

Sandik::Sandik(Vector2 cizim_pozisyonu, std::string renk, KesisimKontrolcu* kesisimKontrolcu)
{    
    this->kesisimKontrolcu = kesisimKontrolcu;
    this->renk = renk;
    this->cizimPozisyonu = cizim_pozisyonu;
    this->dokuYolu = GorselSec();
    this->objeDokusu = DokuYonetici::DokuYukle(dokuYolu);
    oncekiHedefDurumu = hedefteMi;
    this->kare = {0, 0, (float)64, (float)64};
    this->hedefKare = kare;
    this->cizilmeliMi = true;
};

Sandik::~Sandik(){

};

void Sandik::setCizilmeliMi(bool cizilmeliMi){
    this->cizilmeliMi = cizilmeliMi;
};

bool Sandik::RayUygunMu(int rayNo, Yon yon){
    int rayNoMevcut = kesisimKontrolcu->HucreRay(cizimPozisyonu);
    if(rayNoMevcut!=0){
        switch(yon){
            case Yon::SAGA:
                if(rayNoMevcut == 6 || rayNoMevcut == 8 || rayNoMevcut == 11 || rayNoMevcut == 13)
                    return false;
                break;
            case Yon::SOLA:
                if(rayNoMevcut == 6 || rayNoMevcut == 9 || rayNoMevcut == 10 || rayNoMevcut == 12)
                    return false;
                break;
            case Yon::ASAGI:
                if(rayNoMevcut==7 || rayNoMevcut==8 || rayNoMevcut == 9 || rayNoMevcut == 15)
                    return false;
                break;
            case Yon::YUKARI:
                if(rayNoMevcut==7 || rayNoMevcut==10 || rayNoMevcut == 11 || rayNoMevcut == 14)
                    return false;
                break;
            case Yon::HAREKETSIZ:
                break;
        }
    }
    switch(yon){
        case Yon::SAGA:
            if(rayNo == 6 || rayNo == 9 || rayNo == 10 || rayNo == 12)
                return false;
            break;
        case Yon::SOLA:
            if(rayNo == 6 || rayNo == 8 || rayNo== 11 || rayNo == 13)
                return false;
            break;
        case Yon::ASAGI:
            if(rayNo == 7 || rayNo == 10 || rayNo== 11 || rayNo == 14)
                return false;
            break;
        case Yon::YUKARI:
            if(rayNo == 7 || rayNo == 8 || rayNo== 9 || rayNo == 15)
                return false;
            break;
        case Yon::HAREKETSIZ:
            break;
    }
    return true;
};

bool Sandik::AksiyonaGecebilir(Yon yon){
    if(!kesisimKontrolcu->HucreBos(IleriHucrePozisyonu(yon,cizimPozisyonu)))
        return false;
    int rayNo = kesisimKontrolcu->HucreRay(IleriHucrePozisyonu(yon,cizimPozisyonu));
    return RayUygunMu(rayNo, yon);
}

void Sandik::setPozisyon(Vector2 yeniPozisyon){
    cizimPozisyonu = yeniPozisyon;
    hareketEdiyor = false;
}

void Sandik::setRenk(std::string renk){
    this->renk = renk;
}

void Sandik::Guncelle(){
    if(dusuyor && !hareketEdiyor){
        Dus();
    }
    if(buzdaKayiyor){
        BuzdaKay();
        return;
    }
    if (hareketEdiyor){
        HareketEttir();
        return;
    }
    std::string yeniDokuYolu = GorselSec();
    if(yeniDokuYolu!=dokuYolu){
        dokuYolu = yeniDokuYolu;
        objeDokusu = DokuYonetici::DokuYukle(dokuYolu);
    }
}

Vector2 Sandik::IleriHucrePozisyonu(Yon yon, Vector2& baslangicPoz){
    Vector2 ileriPoz = baslangicPoz;
    switch(yon) {
        case Yon::YUKARI: ileriPoz.y -= 64; break;
        case Yon::ASAGI: ileriPoz.y += 64; break;
        case Yon::SAGA: ileriPoz.x += 64; break;
        case Yon::SOLA: ileriPoz.x -= 64; break;
        default: break;
    }
    return ileriPoz;
}

void Sandik::Tetikle(Yon yon){
    Vector2 ileriHucre = IleriHucrePozisyonu(yon, cizimPozisyonu);
    if(kesisimKontrolcu->HucrePortal(ileriHucre)) {
        PortalTetikle(yon);
        return;
    }
    if(kesisimKontrolcu->HucreKaraDelik(ileriHucre)==4){
        DusmeTetikle(yon);
    }
    else if(kesisimKontrolcu->HucreBos(ileriHucre)){
        if(kesisimKontrolcu->HucreBuz(ileriHucre)){
            BuzdaKayTetikle(yon);
        }
        else HareketTetikle(yon);
    }
}

void Sandik::PortalTetikle(Yon yon){
    Vector2 ileriHucre = IleriHucrePozisyonu(yon, cizimPozisyonu);
    
    Portal* portal = kesisimKontrolcu->HucredekiPortaliDondur(ileriHucre);
    Yon yeniYon = portal->IsinlamaSonrasiYon(ileriHucre, yon);

    if(yeniYon == Yon::HAREKETSIZ) return;

    cizimPozisyonu = portal->CikisPortali(ileriHucre);
    ileriHucre = IleriHucrePozisyonu(yeniYon, cizimPozisyonu);
    HareketTetikle(yeniYon);
};

void Sandik::Dus(){
        Vector2 tempCizimPozisyonu = cizimPozisyonu;
        if ((kare.width != 0) && (kare.height != 0) && (cizimPozisyonu.x != tempCizimPozisyonu.x / 2) && (cizimPozisyonu.y != tempCizimPozisyonu.y / 2)) {
            hedefKare.width-=2.0f;
            hedefKare.height-=2.0f;
            if(hedefKare.width<=0 || hedefKare.height <= 0){
                hedefKare.height = 0;
                hedefKare.width = 0;
                kesisimKontrolcu->HucreyiSonrakiFazaGecir(cizimPozisyonu);
                silinmeliMi = true;
            }
        }
}

void Sandik::DusmeTetikle(Yon yon){
        HareketTetikle(yon);
        dusuyor=true;
}

void Sandik::BuzdaKay() {
    float adim = 8.0f;
    Vector2 yonVektoru = {0};
    switch (mevcutYon) {
        case Yon::YUKARI: yonVektoru.y = -1; break;
        case Yon::ASAGI: yonVektoru.y = 1; break;
        case Yon::SOLA: yonVektoru.x = -1; break;
        case Yon::SAGA: yonVektoru.x = 1; break;
        default: break;
    }

    cizimPozisyonu.x += yonVektoru.x * adim;
    cizimPozisyonu.y += yonVektoru.y * adim;

    float kalanXYolu = gidilecekPozisyon.x - cizimPozisyonu.x;
    float kalanYYolu = gidilecekPozisyon.y - cizimPozisyonu.y;
    
    if(abs(kalanXYolu) <= adim && abs(kalanYYolu) <= adim) {
        cizimPozisyonu = gidilecekPozisyon;
        buzdaKayiyor = false;
    }
}

void Sandik::BuzdaKayTetikle(Yon yon) {
    mevcutYon = yon;
    buzdaKayiyor = true;
    gidilecekPozisyon = IleriHucrePozisyonu(mevcutYon,cizimPozisyonu); 
    
    while(kesisimKontrolcu->HucreBuz(gidilecekPozisyon)) 
    {
        Vector2 siradaki = IleriHucrePozisyonu(mevcutYon, gidilecekPozisyon);
        if(kesisimKontrolcu->HucreBos(siradaki)){
            gidilecekPozisyon = siradaki;
        }
        else{
            break;
        }
    }
}

void Sandik::HareketTetikle(Yon mevcutYon){
    this->hareketEdiyor = true;
    this->mevcutYon = mevcutYon;
    this->gidilecekPozisyon = IleriHucrePozisyonu(mevcutYon,cizimPozisyonu);
}

void Sandik::HareketEttir(){
    Vector2 yonVektoru = {0};
    switch(mevcutYon) {
        case Yon::YUKARI: yonVektoru.y = -1; break;
        case Yon::ASAGI: yonVektoru.y = 1; break;
        case Yon::SOLA: yonVektoru.x = -1; break;
        case Yon::SAGA: yonVektoru.x = 1; break;
        default: break;
    }

    float adim = 4;
    while (hareketEdiyor) {
        
        float kalanXYolu = gidilecekPozisyon.x - cizimPozisyonu.x;
        float kalanYYolu = gidilecekPozisyon.y - cizimPozisyonu.y;

        if (fabs(kalanXYolu) <= adim && fabs(kalanYYolu) <= adim) {
            cizimPozisyonu = gidilecekPozisyon;
            hareketEdiyor = false;
            break;
        }
        cizimPozisyonu.x += yonVektoru.x * adim;
        cizimPozisyonu.y += yonVektoru.y * adim;
        break;
    }
};

void Sandik::Ciz(){
    if(!cizilmeliMi) return;
    if(dusuyor && !hareketEdiyor){
        Vector2 origin = {hedefKare.width/2, hedefKare.height/2};
        Rectangle destRec = {
            (2*cizimPozisyonu.x+64)/2,
            (2*cizimPozisyonu.y+64)/2,
            hedefKare.width,
            hedefKare.height
        };
        DrawTexturePro(objeDokusu, kare, destRec, origin, 0.0f, WHITE);
    }else
        DokuYonetici::DokuCiz(objeDokusu, kare, cizimPozisyonu);
};


std::string Sandik::GorselSec(){
    if(kesisimKontrolcu->HucreHedef(cizimPozisyonu)){
        if(renk == kesisimKontrolcu->HucredekiHedefiDondur(cizimPozisyonu)->getRenk()){
            hedefteMi = true;
            return "resources/" + renk + "sandikyildizli.png";
        }
    }
    hedefteMi = false;
    return "resources/" + renk + "sandik.png";
}