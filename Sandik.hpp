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
        
        void PozisyonAta(Vector2 yeniPozisyon);
        void Tetikle(Yon yon);
        void BuzdaKay();
        bool AksiyonaGecebilir(Yon yon);
        Vector2 IleriHucrePozisyonu(Yon yon, Vector2& baslangicPoz);
        void HareketEttir();
        bool getHedefteMi(){return hedefteMi;};
        Vector2 getPozisyon() const {return cizimPozisyonu;};
        Vector2 getCizimPozisyonu(){return cizimPozisyonu;};

    private:
        void HareketTetikle(Yon mevcutYon);
        void BuzdaKayTetikle(Yon yon);
        
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