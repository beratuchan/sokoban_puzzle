#include "raylib.h"
#include "Hedef.hpp"

Hedef::Hedef(Vector2 cizim_pozisyonu, std::string renk){
    this->renk = renk;
    this->cizimPozisyonu = cizim_pozisyonu;
    std::string dokuyolu = GorselSec();
    this->objeDokusu = DokuYonetici::DokuYukle(dokuyolu);
};

Hedef::~Hedef(){

};

Vector2 Hedef::getCizimPozisyonu(){
    return cizimPozisyonu;
}

std::string Hedef::getRenk(){
    return renk;
}

void Hedef::Guncelle(){
    
};

void Hedef::Ciz(){
    DokuYonetici::DokuCiz(objeDokusu,{0,0,64,64},cizimPozisyonu);
};

std::string Hedef::GorselSec(){
    if(renk=="yesil") return "resources/yesilhedef.png";
    else return "resources/mavihedef.png";
}
