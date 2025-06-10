#include "DokuYonetici.hpp"
#include "YonEnum.hpp"
#include <iostream>
#include <algorithm>

std::unordered_map<std::string, Texture2D> DokuYonetici::textureCache_{};

Texture2D DokuYonetici::DokuYukle(const std::string& dosyaAdi) {
    auto it = textureCache_.find(dosyaAdi);
    if (it != textureCache_.end()) {
        return it->second;
    }
    
    Texture2D texture = LoadTexture(dosyaAdi.c_str());
    if (texture.id == 0) {
        std::cerr << "Texture yuklenemedi: " << dosyaAdi << std::endl;
    }
    
    textureCache_[dosyaAdi] = texture;
    return texture;
}

void DokuYonetici::DokuCiz(Texture2D doku, Rectangle kare, Vector2 pozisyon) {
    DrawTextureRec(doku, kare, pozisyon, WHITE);
}

void DokuYonetici::DokuCiz(Texture2D doku, Rectangle kare,Vector2 pozisyon,Vector2 boyut) {
        Vector2 origin = {0,0};
        Rectangle destRec = {
            pozisyon.x-(boyut.x-64)/2,
            pozisyon.y-(boyut.y-64)/2,
            boyut.x,boyut.y
        };
        DrawTexturePro(doku, kare, destRec, origin, 0, WHITE);
}



void DokuYonetici::Temizle() {
    for (auto& pair : textureCache_) {
        UnloadTexture(pair.second);
    }
    textureCache_.clear();
}