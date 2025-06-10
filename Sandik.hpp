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
        bool getSilinmeliMi() override{return silinmeliMi;};
        std::string GorselSec();
        void Dus();
        void DusmeTetikle(Yon yon);
        bool RayUygunMu(int rayNo, Yon yon);

        void setPozisyon(Vector2 yeniPozisyon);
        void setRenk(std::string renk);
        void Tetikle(Yon yon);
        void BuzdaKay();
        bool AksiyonaGecebilir(Yon yon);
        Vector2 IleriHucrePozisyonu(Yon yon, Vector2& baslangicPoz);
        void HareketEttir();
        bool getHedefteMi(){return hedefteMi;};
        Vector2 getPozisyon() const {return cizimPozisyonu;};
        std::string getRenk(){return renk;};
        Vector2 getCizimPozisyonu(){return cizimPozisyonu;};
        void setCizilmeliMi(bool cizilmeliMi);
        bool getCizilmeliMi(){return cizilmeliMi;};
    private:
        void HareketTetikle(Yon mevcutYon);
        void BuzdaKayTetikle(Yon yon);
        void PortalTetikle(Yon yon);

        Rectangle kare;
        Rectangle hedefKare;
        
        KesisimKontrolcu* kesisimKontrolcu;
        bool cizilmeliMi;
        Vector2 cizimPozisyonu;
        std::string dokuYolu;
        Texture2D objeDokusu;
        std::string renk;
        bool hedefteMi;
        bool oncekiHedefDurumu = false;
        Yon mevcutYon;
        Vector2 gidilecekPozisyon;

        bool dusuyor = false;
        bool hareketEdiyor = false;  
        bool buzdaKayiyor = false;     
        float hareketHizi = 120;  
        bool silinmeliMi = false;
};

#endif