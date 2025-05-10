#ifndef SANDIK_HPP
#define SANDIK_HPP

#include "raylib.h"
#include "GameObject.hpp"
#include <string>
#include "DokuYonetici.hpp"

class Sandik:public GameObject{
    public:
        Sandik(Vector2 cizim_pozisyonu, std::string renk);
        ~Sandik();
        void Guncelle() override;
        void Ciz() override;
        std::string GorselSec();
    private:
        Texture2D objeDokusu;
        Vector2 cizimPozisyonu = {0,0};
        std::string renk;
};
#endif