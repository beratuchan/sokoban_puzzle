#include "Sandik.hpp"

Sandik::Sandik(Vector2 cizim_pozisyonu, std::string renk, KesisimKontrolcu* kesisimKontrolcu):kesisimKontrolcu(kesisimKontrolcu)
{    
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

    std::string yeniDokuYolu = GorselSec();
    if(yeniDokuYolu!=dokuYolu){
        dokuYolu = yeniDokuYolu;
        objeDokusu = DokuYonetici::DokuYukle(dokuYolu);
    }
}

void Sandik::HareketEttir(Vector2 yeniCizimPozisyonu){
    cizimPozisyonu = yeniCizimPozisyonu;
}

void Sandik::Ciz(){
    DokuYonetici::DokuCiz(objeDokusu,{0,0,64,64},cizimPozisyonu);
};

std::string Sandik::GorselSec(){
    if(kesisimKontrolcu->HucreHedef(cizimPozisyonu)){
        if(renk==kesisimKontrolcu->HucredekiSandigiDondur(cizimPozisyonu)->renk){
            return "resources/" + renk + "sandikyildizli.png";
        }
    }
    return "resources/" + renk + "sandik.png";
}