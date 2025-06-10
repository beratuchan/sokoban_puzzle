#include <Portal.hpp>
#include "cmath"
#include "iostream"
#include <algorithm>

Portal::Portal(std::vector<Vector2>& pozisyonlar, RenkEnum renk,KesisimKontrolcu* kesisimKontrolcu){
    this->cizimPozisyonu1 = pozisyonlar[0];
    this->cizimPozisyonu2 = pozisyonlar[1];
    this->kare = {0,0,64,64};
    this->renk = renk;
    this->kesisimKontrolcu = kesisimKontrolcu;
}
Portal::~Portal(){

}

void Portal::Guncelle(){
    AnimasyonuGuncelle();
}

void Portal::Ciz(){
    Vector2 boyut = {128.0,64.0};
    DokuYonetici dokuYonetici;
    dokuYonetici.DokuCiz(objeDokusu, kare, cizimPozisyonu1, boyut);
    dokuYonetici.DokuCiz(objeDokusu, kare, cizimPozisyonu2, boyut);
}

void Portal::AnimasyonuGuncelle(){
    int satir;
    switch (this->renk)
    {
    case RenkEnum::yesil:
        satir = 0;
        break;
    case RenkEnum::kirmizi:
        satir = 2;
        break;
    case RenkEnum::mavi:
        satir = 4;
        break;
    case RenkEnum::mor:
        satir = 6;
        break;
    case RenkEnum::pembe:
        satir = 8;
        break;
    default:
        break;
    }
    float adim = 0.2f;
    mevcutFrame += adim;
    
    if(mevcutFrame >= 6) mevcutFrame = 0;
    
    kare.x = floorf(mevcutFrame) * 64;
    kare.y = (mevcutFrame > 3) ? 64*(satir+1) : 64*satir;
}

Yon Portal::IsinlamaSonrasiYon(Vector2 girisPortali, Yon yon){
    Vector2 cikisPortali = cizimPozisyonu1;
    if((cizimPozisyonu1.x==girisPortali.x)&&(cizimPozisyonu1.y==girisPortali.y)){
        cikisPortali = cizimPozisyonu2;
    }
    

    auto it = std::find(SaatYonundeYonler.begin(), SaatYonundeYonler.end(), yon);
    size_t baslangicIndex = (it != SaatYonundeYonler.end()) ? std::distance(SaatYonundeYonler.begin(), it) : 0;


    for (size_t i = 0; i < SaatYonundeYonler.size(); ++i) {
        size_t index = (baslangicIndex + i) % SaatYonundeYonler.size();
        Yon suankiYon = SaatYonundeYonler[index];
        
        Vector2 ileriHucre = IleriHucrePozisyonu(suankiYon, cikisPortali);
        

        if (kesisimKontrolcu->HucreBos(ileriHucre)) {
            return suankiYon;
        }
        if(kesisimKontrolcu->HucreSandik(ileriHucre)){
            Sandik* sandik = kesisimKontrolcu->HucredekiSandigiDondur(ileriHucre);
            if(sandik->AksiyonaGecebilir(suankiYon)){
                return suankiYon;
            }
        }
    }
    return Yon::HAREKETSIZ;
}

Vector2 Portal::CikisPortali(Vector2 girisPortali){
    if((cizimPozisyonu1.x==girisPortali.x)&&(cizimPozisyonu1.y==girisPortali.y)){
        return cizimPozisyonu2;
    }
    return cizimPozisyonu1;
}

Vector2 Portal::IleriHucrePozisyonu(Yon yon, Vector2& baslangicPoz){
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
