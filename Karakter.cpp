#include "Karakter.hpp"
#include "cmath"

Karakter::Karakter(Vector2 cizim_pozisyonu, bool aktifMi, int karakterNo, ObjeYonetici* objeYonetici, DurumYonetici* durumYonetici) {
    this->objeYonetici = objeYonetici;
    this->cizimPozisyonu = cizim_pozisyonu;
    this->durumYonetici = durumYonetici;
    this->karakterNo = karakterNo;
    this->aktifMi = aktifMi;
    objeDokusu = DokuYonetici::DokuYukle("resources/adam.png");
    frameGenisligi = objeDokusu.width / 6;
    frameYuksekligi = objeDokusu.height / 4;
    this->kare = {0, (float)(karakterNo*2*frameYuksekligi), (float)frameGenisligi, (float)frameYuksekligi};
    this->hedefKare = kare;
    this->cizilmeliMi = true;
}
Karakter::~Karakter() {

}

void Karakter::setAktifMi(bool aktifMi){
    this->aktifMi = aktifMi;
};

void Karakter::setKarakterNo(int karakterNo){
    this->karakterNo = karakterNo;
};
void Karakter::HareketTetikle(Vector2 gidilecekPozisyon){
    Vector2 ileriHucre = IleriHucrePozisyonu(mevcutYon,cizimPozisyonu);
    if(objeYonetici->getKesisimKontolcu()->HucreSandik(ileriHucre)){
            Sandik* sandik = objeYonetici->getKesisimKontolcu()->HucredekiSandigiDondur(ileriHucre);
            if(sandik->AksiyonaGecebilir(mevcutYon)){
                sandik->Tetikle(mevcutYon);
            }
        }
    this->gidilecekPozisyon = gidilecekPozisyon;
    hareketEdiyor = true;
}

void Karakter::HareketEttir(){
    
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
            Tetikle(cizimPozisyonu);
            break;
        }
        
        cizimPozisyonu.x += yonVektoru.x * adim;
        cizimPozisyonu.y += yonVektoru.y * adim;
        break;
    }
}

void Karakter::Guncelle() {
    if(!aktifMi){
        return;
    }
    if(dusuyor && !hareketEdiyor){
        Dus();
    }
    if (hareketEdiyor) {
        HareketEttir();
        AnimasyonuGuncelle();
        return;
    }

    if (buzdaKayiyor) {
        BuzdaKay();
        AnimasyonuGuncelle();
        return;
    }
    mevcutYon = GirdiKontrolcu::mevcutYon;
    Vector2 ileriHucre = IleriHucrePozisyonu(mevcutYon,cizimPozisyonu);

    if (mevcutYon != Yon::HAREKETSIZ) {
        Tetikle(ileriHucre);
        GirdiKontrolcu::hareketSayaci++;
        DurumKaydet();
    }
}

void Karakter::Dus(){
    Vector2 tempCizimPozisyonu = cizimPozisyonu;
    if ((kare.width != 0) && (kare.height != 0) && (cizimPozisyonu.x != tempCizimPozisyonu.x / 2) && (cizimPozisyonu.y != tempCizimPozisyonu.y / 2)) {
        hedefKare.width-=2.0f;
        hedefKare.height-=2.0f;

        donmeAcisi += 10.0f;

        if(hedefKare.width<=0 || hedefKare.height <= 0){
            hedefKare.height = 0;
            hedefKare.width = 0;
            silinmeliMi = true;
        }
    }
}

void Karakter::DusmeTetikle(Vector2 ileriHucre){
    HareketTetikle(ileriHucre);
    dusuyor = true;
}
void Karakter::BuzdaKayTetikle(){
    buzdaKayiyor = true;
    gidilecekPozisyon = IleriHucrePozisyonu(mevcutYon, cizimPozisyonu);
    
    while(objeYonetici->getKesisimKontolcu()->HucreBuz(gidilecekPozisyon)) 
    {
        Vector2 siradaki = IleriHucrePozisyonu(mevcutYon, gidilecekPozisyon);
        if(objeYonetici->getKesisimKontolcu()->HucreBos(siradaki)){
            gidilecekPozisyon = siradaki;
        }
        else{
            break;
        }
    }
}


void Karakter::BuzdaKay() {
    float adim = 8.0f;
    Vector2 yonVektoru = {0};
    switch(mevcutYon) {
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


void Karakter::PozisyonAta(Vector2 yeniPozisyon){
    cizimPozisyonu = yeniPozisyon;
}

Vector2 Karakter::IleriHucrePozisyonu(Yon yon, Vector2& baslangicPoz){
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
void Karakter::PortalTetikle(Vector2 ileriHucre){
    Portal* portal = objeYonetici->getKesisimKontolcu()->HucredekiPortaliDondur(ileriHucre);
    Yon yeniYon = portal->IsinlamaSonrasiYon(ileriHucre, mevcutYon);
    if(yeniYon == Yon::HAREKETSIZ) return;
    cizimPozisyonu = portal->CikisPortali(ileriHucre);
    mevcutYon = yeniYon;
    ileriHucre = IleriHucrePozisyonu(mevcutYon, cizimPozisyonu);
    HareketTetikle(ileriHucre); 
}

void Karakter::Tetikle(Vector2 ileriHucre){
    if(dusuyor){
        return;
    }
    Vector2 temp = cizimPozisyonu;
    if(objeYonetici->getKesisimKontolcu()->HucrePortal(ileriHucre)){
        PortalTetikle(ileriHucre);
        return;
    }
    if(objeYonetici->getKesisimKontolcu()->HucreKaraDelik(ileriHucre)==4){
        DusmeTetikle(ileriHucre);
    }
    else if(objeYonetici->getKesisimKontolcu()->HucreBos(ileriHucre)){
        if(objeYonetici->getKesisimKontolcu()->HucreBuz(ileriHucre)){
            BuzdaKayTetikle();
            return;
        }
        HareketTetikle(ileriHucre);
    }
    else{
        if(objeYonetici->getKesisimKontolcu()->HucreSandik(ileriHucre)){
            Sandik* sandik = objeYonetici->getKesisimKontolcu()->HucredekiSandigiDondur(ileriHucre);
            if(sandik->AksiyonaGecebilir(mevcutYon)){
                HareketTetikle(ileriHucre);
            }
        }
    }
    if(objeYonetici->getKesisimKontolcu()->HucreKaraDelik(temp)==3){
        objeYonetici->getKesisimKontolcu()->HucreyiSonrakiFazaGecir(temp);
    }
}

void Karakter::Ciz() {
    if(!cizilmeliMi) return;
    if(dusuyor && !hareketEdiyor){
        Vector2 origin = {hedefKare.width/2, hedefKare.height/2};
        Rectangle destRec = {
            (2*cizimPozisyonu.x+64)/2,
            (2*cizimPozisyonu.y+64)/2,
            hedefKare.width,
            hedefKare.height
        };
        DrawTexturePro(objeDokusu, kare, destRec, origin, donmeAcisi, WHITE);
    }else
        DokuYonetici::DokuCiz(objeDokusu, kare, cizimPozisyonu);
}

void Karakter::DurumKaydet(){
    if(cizimPozisyonu.x != oncekiPozisyon.x || cizimPozisyonu.y != oncekiPozisyon.y) {
        Durum durum;
        for(const auto& karakter : objeYonetici->getKarakterler()) {
            KarakterStruct karakterStruct;
            karakterStruct.AktifMi = karakter->getAktifMi();
            karakterStruct.karakterNo = karakter->getKarakterNo();
            karakterStruct.pozisyon = karakter->getCizimPozisyonu();
            durum.karakterStructlar.push_back(karakterStruct);
        }
        for(const auto& sandik : objeYonetici->getSandiklar()) {
            SandikStruct sandikstruct;
            sandikstruct.renk = sandik->getRenk();
            sandikstruct.pozisyon = sandik->getCizimPozisyonu();
            durum.sandikStructlar.push_back(sandikstruct);
        }
        durum.hareketSayaci = GirdiKontrolcu::hareketSayaci;
        durum.haritaIzgara = objeYonetici->getHarita()->getIzgara();
        durumYonetici->Kaydet(durum);
    }
};

void Karakter::AnimasyonuGuncelle() {
    if(buzdaKayiyor){
            switch(mevcutYon) {
            case Yon::ASAGI:
                kare.y = 0+(karakterNo*2)*64;
                kare.x = 0;
                break;
                
            case Yon::YUKARI:
                kare.x = 3*64;
                kare.y = 0+(karakterNo*2)*64;
                break;
                
            case Yon::SAGA:
                kare.x = 0;
                kare.y = 64+(karakterNo*2)*64;

                break;
                
            case Yon::SOLA:
                kare.y = 64+(karakterNo*2)*64;
                kare.x = 3*64;
                break;
                
            case Yon::HAREKETSIZ:
                mevcutFrame = 0; 
                break;
        }
    }else{
            mevcutFrame+=0.2;

    switch(mevcutYon) {
            case Yon::ASAGI:
                kare.y = 0+(karakterNo*2)*64;
                if(mevcutFrame >= 3) mevcutFrame = 0;
                kare.x = floorf(mevcutFrame) * frameGenisligi;
                break;
                
            case Yon::YUKARI:
                kare.y = 0+(karakterNo*2)*64;
                if(mevcutFrame >= 3) mevcutFrame = 0;
                kare.x = (floorf(mevcutFrame)+3) * frameGenisligi;
                break;
                
            case Yon::SAGA:
                kare.y = frameYuksekligi+(karakterNo*2)*64;
                if(mevcutFrame >= 2) mevcutFrame = 0;
                kare.x = floorf(mevcutFrame) * frameGenisligi;
                break;
                
            case Yon::SOLA:
                kare.y = frameYuksekligi+(karakterNo*2)*64;
                if(mevcutFrame >= 2) mevcutFrame = 0;
                kare.x = (floorf(mevcutFrame) + 3) * frameGenisligi;
                break;
                
            case Yon::HAREKETSIZ:
                mevcutFrame = 0; 
                break;
        }
    }
}