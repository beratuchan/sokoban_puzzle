#ifndef BASLANGIC_EKRANI_HPP
#define BASLANGIC_EKRANI_HPP
#include "raylib.h"
#include "OyunDurumuEnum.hpp"
#include "DokuYonetici.hpp"

class BaslangicEkrani{
    public:
        BaslangicEkrani();
        ~BaslangicEkrani();
        OyunDurumu Guncelle();
        void Ciz();
    private:
        Texture2D maskot;
        Rectangle baslaButon;
        Rectangle cikisButon;
};
#endif