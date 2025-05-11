#include "Sandik.hpp"

Sandik::Sandik(Vector2 cizim_pozisyonu, std::string renk){
    this->renk = renk;
    this->cizimPozisyonu = cizim_pozisyonu;
    this->dokuYolu = GorselSec();
    this->objeDokusu = DokuYonetici::DokuYukle(dokuYolu);
};

Sandik::~Sandik(){

};

Vector2 Sandik::getCizimPozisyonu(){
    return cizimPozisyonu;
}

void Sandik::Guncelle(){

};

void Sandik::Ciz(){
    DokuYonetici::DokuCiz(objeDokusu,{0,0,64,64},cizimPozisyonu);
};

std::string Sandik::GorselSec(){
    if(renk=="yesil") return "resources/yesilsandik.png";
    else return "resources/mavisandik.png";
}