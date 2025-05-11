#ifndef HEDEF_HPP
#define HEDEF_HPP

#include "GameObject.hpp"
#include "DokuYonetici.hpp"

class Hedef : public GameObject {
    public:
        Hedef(Vector2 cizim_pozisyonu, std::string renk);
        ~Hedef();
        void Guncelle() override;
        void Ciz() override;
        std::string GorselSec();
        Vector2 getCizimPozisyonu();
    private:
        Texture2D objeDokusu;
        std::string renk;
        Vector2 cizimPozisyonu;
};
#endif