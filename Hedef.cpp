#include "raylib.h"
#include "Hedef.hpp"

Hedef::Hedef(Vector2 cizim_pozisyonu, std::string renk, KesisimKontrolcu* kesisimKontrolcu){
    this->renk = renk;
    this->cizimPozisyonu = cizim_pozisyonu;
    this->kesisimKontrolcu = kesisimKontrolcu;
    std::string dokuyolu = GorselSec();
    this->objeDokusu = DokuYonetici::DokuYukle(dokuyolu);
};

Hedef::~Hedef(){

};

bool Hedef::DoluMu(){
    if(kesisimKontrolcu->HucreSandik(cizimPozisyonu))
        return kesisimKontrolcu->HucredekiSandigiDondur(cizimPozisyonu)->getHedefteMi();
    else return false;
}

void Hedef::Guncelle(){
    
};

void Hedef::Ciz(){
    DokuYonetici::DokuCiz(objeDokusu,{0,0,64,64},cizimPozisyonu);
};

std::string Hedef::GorselSec(){
    return "resources/"+renk+"hedef.png";
}
