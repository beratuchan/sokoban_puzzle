#ifndef DOKU_YONETICI_HPP
#define DOKU_YONETICI_HPP

#include <raylib.h>
#include <string>
#include "GameObject.hpp"
#include <unordered_map>
#include "YonEnum.hpp"

class DokuYonetici {
private:
    static std::unordered_map<std::string, Texture2D> textureCache_;
public:
    static void DokuCiz(Texture2D doku, Rectangle kare, Vector2 pozisyon);
    static void DokuCiz(Texture2D doku, Rectangle kare,Vector2 boyut, Vector2 pozisyon);
    static Texture2D DokuYukle(const std::string& dosyaAdi);
    static void Temizle();
};
#endif 
