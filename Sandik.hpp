#ifndef SANDIK_HPP
#define SANDIK_HPP

#include "raylib.h"
#include "GameObject.hpp"

class Sandik:public GameObject{
    public:
        Sandik();
        ~Sandik();
        void Guncelle() override;
        void Ciz() override;
    private:
        Texture2D objeDokusu;
        Vector2 cizimPozisyonu = {0,0};
};
#endif