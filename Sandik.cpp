#include "Sandik.hpp"
#include "cmath"

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
    
    if (hareketEdiyor){
        HareketEttir();
    }

    std::string yeniDokuYolu = GorselSec();
    if(yeniDokuYolu!=dokuYolu){
        dokuYolu = yeniDokuYolu;
        objeDokusu = DokuYonetici::DokuYukle(dokuYolu);
    }
}

void Sandik::HareketTetikle(Vector2 gidilecekPozisyon, Yon mevcutYon){
    hareketEdiyor = true;
    this->mevcutYon = mevcutYon;
    this->gidilecekPozisyon = gidilecekPozisyon;
}

void Sandik::HareketEttir(){
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
};


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