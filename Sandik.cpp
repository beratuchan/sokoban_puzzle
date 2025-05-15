#include "Sandik.hpp"
#include "cmath"

Sandik::Sandik(Vector2 cizim_pozisyonu, std::string renk, KesisimKontrolcu* kesisimKontrolcu)
{    
    this->kesisimKontrolcu = kesisimKontrolcu;
    this->renk = renk;
    this->cizimPozisyonu = cizim_pozisyonu;
    this->dokuYolu = GorselSec();
    this->objeDokusu = DokuYonetici::DokuYukle(dokuYolu);
};

Sandik::~Sandik(){
    
};

bool Sandik::AksiyonaGecebilir(Yon yon){
    return kesisimKontrolcu->HucreBos(IleriHucrePozisyonu(yon,cizimPozisyonu));
}

void Sandik::PozisyonAta(Vector2 yeniPozisyon){
    cizimPozisyonu = yeniPozisyon;
    hareketEdiyor = false;
}

Vector2 Sandik::getCizimPozisyonu(){
    return cizimPozisyonu;
}

bool Sandik::getHedefteMi(){
    return hedefteMi;
}


void Sandik::Guncelle(){
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
    if(kesisimKontrolcu->HucreBos(ileriHucre)){
        if(kesisimKontrolcu->HucreBuz(ileriHucre)){
            BuzdaKayTetikle(yon);
        }
        else HareketTetikle(yon);
    }
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
    DokuYonetici::DokuCiz(objeDokusu,{0,0,64,64},cizimPozisyonu);
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