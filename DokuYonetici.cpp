#include "DokuYonetici.hpp"

Texture2D DokuYonetici::DokuYukle(const char* dosyaAdi) {
    Texture2D texture = LoadTexture(dosyaAdi);
    return texture;
}

void DokuYonetici::DokuCiz(Texture2D doku, Rectangle frameRec, Vector2 pozisyon) {
    DrawTextureRec(doku, frameRec, pozisyon, WHITE);
}