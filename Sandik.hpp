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
        Vector2 getCizimPozisyonu();
        void HareketEttir(Vector2 yeniCizimPozisyonu);
    private:
        Vector2 cizimPozisyonu;
        std::string dokuYolu;
        Texture2D objeDokusu;
        std::string renk;
};
#endif