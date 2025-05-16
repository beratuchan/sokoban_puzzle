#include "Kapan.hpp"

class KesisimKontrolcu;

Kapan::Kapan(Vector2 cizimPozisyonu, std::vector<Vector2> anahtarCizimPozisyonu, bool acikMi, KesisimKontrolcu* kesisimKontrolcu){
    this->cizimPozisyonu = cizimPozisyonu;
    this->anahtarCizimPozisyonlari = anahtarCizimPozisyonu;
    this->acikMi = acikMi;
    this->kesisimKontrolcu = kesisimKontrolcu;
    this->objedokusu = DokuYonetici::DokuYukle("resources/kapan.png");
    this->tumAnahtarlarBasiliMi = TumAnahtarlarBasili();
}
Kapan::~Kapan(){};

void Kapan::Ciz(){
    for(Vector2 anahtarCizimPozisyon: anahtarCizimPozisyonlari){
      DokuYonetici::DokuCiz(objedokusu,anahtar,anahtarCizimPozisyon);  
    }
    if(acikMi){
        DokuYonetici::DokuCiz(objedokusu,acik,cizimPozisyonu);
    }else{
        DokuYonetici::DokuCiz(objedokusu,kapali,cizimPozisyonu);
    }
}

void Kapan::Guncelle(){
    AcKapa();
}

void Kapan::AcKapa(){
    if(tumAnahtarlarBasiliMi){
        if(!TumAnahtarlarBasili()){
            if(acikMi) acikMi=false;
            else acikMi=true;
            tumAnahtarlarBasiliMi=false;
        }
    }else{
        if(TumAnahtarlarBasili()){
            if(acikMi) acikMi=false;
            else acikMi=true;
            tumAnahtarlarBasiliMi=false;
        }
    }

}

bool Kapan::TumAnahtarlarBasili(){
    for(Vector2 anahtarCizimPozisyon: anahtarCizimPozisyonlari){
        if(kesisimKontrolcu->HucreBos(anahtarCizimPozisyon)){
            return false;
        }
    }
    return true;
}


