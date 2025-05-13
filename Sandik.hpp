#ifndef SANDIK_HPP
#define SANDIK_HPP

#include "raylib.h"
#include "GameObject.hpp"
#include <string>
#include "DokuYonetici.hpp"
#include "KesisimKontrolcu.hpp"
#include "YonEnum.hpp"

class KesisimKontrolcu;

class Sandik: public GameObject{
    public:
        Sandik(Vector2 cizim_pozisyonu, std::string renk, KesisimKontrolcu* kesisimKontrolcu);
        ~Sandik();
        void Guncelle() override;
        void Ciz() override;
        std::string GorselSec();
        Vector2 getCizimPozisyonu();
        void HareketTetikle(Vector2 yeniCizimPozisyonu, Yon mevcutYon);
        void HareketEttir();
        bool getHedefteMi();
        Vector2 getPozisyon() const {return cizimPozisyonu;};

    private:
        KesisimKontrolcu* kesisimKontrolcu;
        Vector2 cizimPozisyonu;
        std::string dokuYolu;
        Texture2D objeDokusu;
        std::string renk;
        bool hedefteMi;
        Yon mevcutYon;

        Vector2 gidilecekPozisyon;    
        bool hareketEdiyor = false;       
        float hareketHizi = 120;  
};
#endif