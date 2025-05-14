#ifndef SANDIK_HPP
#define SANDIK_HPP

#include "raylib.h"
#include "GameObject.hpp"
#include <string>
#include "DokuYonetici.hpp"
#include "KesisimKontrolcu.hpp"
#include "YonEnum.hpp"
#include "GirdiKontrolcu.hpp"

class KesisimKontrolcu;

class Sandik: public GameObject{
    public:
        Sandik(Vector2 cizim_pozisyonu, std::string renk, KesisimKontrolcu* kesisimKontrolcu);
        ~Sandik();
        void Guncelle() override;
        void Ciz() override;
        std::string GorselSec();
        Vector2 getCizimPozisyonu();
        void PozisyonAta(Vector2 yeniPozisyon);
        void BuzdaKayTetikle(Yon yon);
        void BuzdaKay();
        void HareketTetikle(Vector2 yeniCizimPozisyonu, Yon mevcutYon);
        Vector2 IleriHucrePozisyonu(Yon yon, Vector2& baslangicPoz);
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
        bool buzdaKayiyor = false;     
        float hareketHizi = 120;  
};
#endif