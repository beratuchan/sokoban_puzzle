#ifndef KAPAN_HPP
#define KAPAN_HPP
#include "raylib.h"
#include "GameObject.hpp"
#include "DokuYonetici.hpp"
#include "KesisimKontrolcu.hpp"

class Kapan : public GameObject{
    public:
        Kapan(Vector2 cizimPozisyonu, std::vector<Vector2> anahtarCizimPozisyonu, bool acik, KesisimKontrolcu* kesisimKontrolcu);
        ~Kapan();
        void Ciz() override;
        void Guncelle() override;
        void AcKapa();
        bool TumAnahtarlarBasili();

    private:
        Vector2 cizimPozisyonu;
        std::vector<Vector2> anahtarCizimPozisyonlari;
        Texture2D objedokusu;
        Rectangle acik = {0,0,64,64};
        Rectangle kapali = {64,0,64,64};
        Rectangle anahtar = {64*2,0,64,64};
        bool acikMi;
        bool tumAnahtarlarBasiliMi;
        KesisimKontrolcu* kesisimKontrolcu;
};

#endif