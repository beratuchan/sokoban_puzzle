#include "Karakter.hpp"
#include "cmath"

Karakter::Karakter(Vector2 cizim_pozisyonu, ObjeYonetici* objeYonetici, DurumYonetici* durumYonetici) {
    this->objeYonetici = objeYonetici;
    this->cizimPozisyonu = cizim_pozisyonu;
    this->durumYonetici = durumYonetici;
    objeDokusu = DokuYonetici::DokuYukle("resources/adam.png");
    frameGenisligi = objeDokusu.width / 6;
    frameYuksekligi = objeDokusu.height / 2;
    kare = {0, 0, (float)frameGenisligi, (float)frameYuksekligi};
}

Karakter::~Karakter() {
    UnloadTexture(objeDokusu);
}

void Karakter::HareketTetikle(Vector2 gidilecekPozisyon){
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
            break;
        }
        
        cizimPozisyonu.x += yonVektoru.x * adim;
        cizimPozisyonu.y += yonVektoru.y * adim;
        break;
    }
}

void Karakter::Guncelle() {
    if (buzdaKayiyor) {
        BuzdaKay();
        AnimasyonuGuncelle();
        return;
    }

    if (hareketEdiyor) {
        HareketEttir();
        AnimasyonuGuncelle();
        return;
    }

    mevcutYon = GirdiKontrolcu::mevcutYon;
    
    if (mevcutYon != Yon::HAREKETSIZ) {
        Tetikle();
        GirdiKontrolcu::hareketSayaci++;
        DurumKaydet();
    }
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

void Karakter::Tetikle(){
    Vector2 ileriHucre = IleriHucrePozisyonu(mevcutYon, cizimPozisyonu);
    if(objeYonetici->getKesisimKontolcu()->HucreBos(ileriHucre)){
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
                sandik->Tetikle(mevcutYon);
                HareketTetikle(ileriHucre);
            }
        }
    }
}

void Karakter::Ciz() {
    DokuYonetici::DokuCiz(objeDokusu, kare, cizimPozisyonu);
}

void Karakter::DurumKaydet(){
    if(cizimPozisyonu.x != oncekiPozisyon.x || cizimPozisyonu.y != oncekiPozisyon.y) {
        Durum durum;
        durum.karakterPozisyon = cizimPozisyonu;
        for(const auto& sandik : objeYonetici->getSandiklar()) {
            durum.sandikPozisyonlar.push_back(sandik.getPozisyon());
        }
        durum.hareketSayaci = GirdiKontrolcu::hareketSayaci;
        durumYonetici->Kaydet(durum);
    }
};

void Karakter::AnimasyonuGuncelle() {
    if(buzdaKayiyor){
            switch(mevcutYon) {
            case Yon::ASAGI:
                kare.y = 0;
                kare.x = 0;
                break;
                
            case Yon::YUKARI:
                kare.x = 3*64;
                kare.y = 0;
                break;
                
            case Yon::SAGA:
                kare.x = 0;
                kare.y = 64;

                break;
                
            case Yon::SOLA:
                kare.y = 64;
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
                kare.y = 0;
                if(mevcutFrame >= 3) mevcutFrame = 0;
                kare.x = floorf(mevcutFrame) * frameGenisligi;
                break;
                
            case Yon::YUKARI:
                kare.y = 0;
                if(mevcutFrame >= 3) mevcutFrame = 0;
                kare.x = (floorf(mevcutFrame)+3) * frameGenisligi;
                break;
                
            case Yon::SAGA:
                kare.y = frameYuksekligi;
                if(mevcutFrame >= 2) mevcutFrame = 0;
                kare.x = floorf(mevcutFrame) * frameGenisligi;
                break;
                
            case Yon::SOLA:
                kare.y = frameYuksekligi;
                if(mevcutFrame >= 2) mevcutFrame = 0;
                kare.x = (floorf(mevcutFrame) + 3) * frameGenisligi;
                break;
                
            case Yon::HAREKETSIZ:
                mevcutFrame = 0; 
                break;
        }
    }
}