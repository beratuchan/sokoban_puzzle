#ifndef SEVIYELER_HPP
#define SEVIYELER_HPP

#include <vector>
#include <string>
#include "raylib.h"
#include "DokuYonetici.hpp"

struct SandikStruct {
    Vector2 pozisyon;
    std::string renk;
};

struct HedefStruct {
    Vector2 pozisyon;
    std::string renk;
};

struct Seviye {
    std::vector<std::vector<int>> harita;
    Vector2 karakterBaslangic;
    std::vector<SandikStruct> sandiklar;
    std::vector<HedefStruct> hedefler;
};

#endif