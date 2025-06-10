#ifndef KAPAN_HPP
#define KAPAN_HPP
#include "raylib.h"
#include "GameObject.hpp"
#include "DokuYonetici.hpp"
#include "KesisimKontrolcu.hpp"
#include "Renkler.hpp"

class Kapan : public GameObject{
    public:
        Kapan(Vector2 cizimPozisyonu, std::vector<Vector2> anahtarCizimPozisyonu, bool acik, RenkEnum kapanrenk, KesisimKontrolcu* kesisimKontrolcu);
        ~Kapan();
        void Ciz() override;
        void Guncelle() override;
        bool getSilinmeliMi() override{return silinmeliMi;};
        void AcKapa();
        bool TumAnahtarlarBasili();
        Vector2 getCizimPozisyonu(){return cizimPozisyonu;};
        bool getAcikMi(){return acikMi;};
    private:
        Vector2 cizimPozisyonu;
        std::vector<Vector2> anahtarCizimPozisyonlari;
        Texture2D objedokusu= DokuYonetici::DokuYukle("resources/kapanlar.png"); ;
        std::string renk;
        bool acikMi;
        bool tumAnahtarlarBasiliMi;
        KesisimKontrolcu* kesisimKontrolcu;
        RenkEnum kapanrenk;
        Rectangle acik;
        Rectangle kapali;
        Rectangle anahtar;
        bool silinmeliMi = false;
};

#endif