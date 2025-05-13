#ifndef HEDEF_HPP
#define HEDEF_HPP

#include "GameObject.hpp"
#include "DokuYonetici.hpp"
#include "KesisimKontrolcu.hpp"

class KesisimKontrolcu;

class Hedef : public GameObject {
    public:
        Hedef(Vector2 cizim_pozisyonu, std::string renk, KesisimKontrolcu* kesisimKontrolcu);
        ~Hedef();
        void Guncelle() override;
        void Ciz() override;
        std::string GorselSec();
        Vector2 getCizimPozisyonu();
        std::string getRenk();
        bool DoluMu();

    private:
        Texture2D objeDokusu;
        std::string renk;
        Vector2 cizimPozisyonu;
        KesisimKontrolcu* kesisimKontrolcu;
};
#endif