#include "Kapan.hpp"

class KesisimKontrolcu;

Kapan::Kapan(Vector2 cizimPozisyonu, std::vector<Vector2> anahtarCizimPozisyonu, bool acikMi, RenkEnum kapanrenk, KesisimKontrolcu* kesisimKontrolcu){
    this->cizimPozisyonu = cizimPozisyonu;
    this->kapanrenk = kapanrenk;
    this->anahtarCizimPozisyonlari = anahtarCizimPozisyonu;
    this->acikMi = acikMi;
    this->kesisimKontrolcu = kesisimKontrolcu;
    this->tumAnahtarlarBasiliMi = TumAnahtarlarBasili();
    this->acik = {0,static_cast<float>(kapanrenk)*64,64,64};
    this->kapali = {64,static_cast<float>(kapanrenk)*64,64,64};
    this->anahtar = {64*2,static_cast<float>(kapanrenk)*64,64,64};
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
    if(tumAnahtarlarBasiliMi!=TumAnahtarlarBasili()){
        tumAnahtarlarBasiliMi = TumAnahtarlarBasili();
        acikMi = !acikMi;
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


