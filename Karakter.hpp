#ifndef KARAKTER_HPP
#define KARAKTER_HPP

#include "raylib.h"
#include "GameObject.hpp"
#include "DokuYonetici.hpp"



class Karakter : public GameObject {
    public:
        Karakter(Vector2 pozisyon);
        ~Karakter();
        void Guncelle() override;
        void Ciz() override;
        void AnimasyonuGuncelle();

    private:
        Texture2D objeDokusu;
        Vector2 cizimPozisyonu = {0,0};
        Rectangle kare;


        int currentFrame = 0;
        int framesCounter = 0;
        int frameWidth;
        int frameHeight;
};
#endif