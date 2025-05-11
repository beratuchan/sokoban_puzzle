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

bool Sandik::getHedefteMi(){
    return hedefteMi;
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
        if(renk == kesisimKontrolcu->HucredekiHedefiDondur(cizimPozisyonu)->getRenk()){
            hedefteMi = true;
            return "resources/" + renk + "sandikyildizli.png";
        }
    }
    hedefteMi = false;
    return "resources/" + renk + "sandik.png";
}