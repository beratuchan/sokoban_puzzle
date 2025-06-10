#ifndef PORTAL_HPP
#define PORTAL_HPP

#include "raylib.h"
#include <DokuYonetici.hpp>
#include <GameObject.hpp>
#include "Renkler.hpp"
#include <vector>
#include "YonEnum.hpp"
#include "KesisimKontrolcu.hpp"

class Portal : public GameObject{
    public:
        Portal(std::vector<Vector2>& pozisyonlar, RenkEnum renk,KesisimKontrolcu* kesisimKontrolcu);
        ~Portal() override;
        void Guncelle() override;
        void Ciz() override;
        bool getSilinmeliMi() override{return silinmeliMi;};
        Yon IsinlamaSonrasiYon(Vector2 girisPortali, Yon yon);
        Vector2 CikisPortali(Vector2 girisPortali);
        Vector2 getCizimPozisyonu1(){return cizimPozisyonu1;};
        Vector2 getCizimPozisyonu2(){return cizimPozisyonu2;};
    private:
        void AnimasyonuGuncelle();
        Vector2 IleriHucrePozisyonu(Yon yon, Vector2& baslangicPoz);
        Texture2D objeDokusu = DokuYonetici::DokuYukle("resources/portal.png");
        Vector2 cizimPozisyonu1;
        Vector2 cizimPozisyonu2;
        Rectangle kare;
        float mevcutFrame = 0;
        RenkEnum renk;
        bool silinmeliMi = false;
        KesisimKontrolcu* kesisimKontrolcu;
};
#endif