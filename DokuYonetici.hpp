#ifndef DOKU_YONETICI_HPP
#define DOKU_YONETICI_HPP

#include "raylib.h"

class DokuYonetici {
public:
    static Texture2D DokuYukle(const char* dosyaAdi);
    static void DokuCiz(Texture2D doku, Rectangle frameRec, Vector2 pozisyon);
};

#endif