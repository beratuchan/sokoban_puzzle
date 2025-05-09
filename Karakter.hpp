#ifndef KARAKTER_HPP
#define KARAKTER_HPP

#include "raylib.h"
#include "GameObject.hpp"
#include "DokuYonetici.hpp"

enum class Yon{
        HAREKETSIZ,
        SAGA,
        SOLA,
        ILERI,
        GERI
};

class Karakter : public GameObject {
public:
    Karakter(const char* textureSheet, int x, int y);
    ~Karakter();
    void Guncelle() override;
    void Ciz() override;

private:
    void HareketKontrol();
    void AnimasyonuGuncelle();
    
    Texture2D objeDokusu;
    Vector2 hedefPozisyon;
    Rectangle kare;
    
    Yon mevcutYon = Yon::HAREKETSIZ;
    int currentFrame = 0;
    int framesCounter = 0;
    const int framesSpeed = 8;
    int frameWidth;
    int frameHeight;
};

#endif