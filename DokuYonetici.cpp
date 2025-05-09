#include "DokuYonetici.hpp"

Texture2D DokuYonetici::DokuYukle(std::string dosyaAdi) {
    return LoadTexture(dosyaAdi.c_str());
}

void DokuYonetici::DokuCiz(Texture2D doku, Rectangle frameRec, Vector2 pozisyon) {
    DrawTextureRec(doku, frameRec, pozisyon, WHITE);
}