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
    private:
        Texture2D objeDokusu;
        Vector2 cizimPozisyonu = {0,0};
        std::string renk;
};
#endif