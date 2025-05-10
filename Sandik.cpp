#include "Sandik.hpp"


Sandik::Sandik(Vector2 cizim_pozisyonu, std::string renk){
    this->renk = renk;
    cizimPozisyonu = cizim_pozisyonu;
    objeDokusu = DokuYonetici::DokuYukle(GorselSec());
};

Sandik::~Sandik(){
    UnloadTexture(objeDokusu);
};

void Sandik::Guncelle(){

};

void Sandik::Ciz(){
    DokuYonetici::DokuCiz(objeDokusu,{0,0,64,64},cizimPozisyonu);
};

std::string Sandik::GorselSec(){
    if(renk=="yesil") return "resources/yesilsandik.png";
    else return "resources/mavisandik.png";
}