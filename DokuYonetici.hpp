#ifndef DOKU_YONETICI_HPP
#define DOKU_YONETICI_HPP

#include <raylib.h>
#include <string>
#include "GameObject.hpp"

class DokuYonetici{
    public:
        static Texture2D DokuYukle(std::string dosyaAdi);
        static void DokuCiz(Texture2D doku, Rectangle kare, Vector2 pozisyon );
};
#endif 
