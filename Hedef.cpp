#ifndef KARAKTER_HPP
#define KARAKTER_HPP

#include "GameObject.hpp"
#include "DokuYonetici.hpp"

class Hedef : public GameObject {
    public:
        Hedef(Vector2 pozisyon);
        ~Hedef();
        void Guncelle() override;
        void Ciz() override;
        void AnimasyonuGuncelle();

    private:
        Texture2D objeDokusu;
        Vector2 cizimPozisyonu = {0,0};
};
#endif