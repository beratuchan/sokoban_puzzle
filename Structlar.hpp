#pragma once
#include "raylib.h"
#include <vector>
#include <string>
#include "Renkler.hpp"

struct SandikStruct {
    Vector2 pozisyon;
    std::string renk;
};

struct KarakterStruct{
    Vector2 pozisyon;
    bool AktifMi;
    int karakterNo;
};

struct HedefStruct {
    Vector2 pozisyon;
    std::string renk;
};

struct KapanStruct{
    std::vector<Vector2> anahtarpozisyonlari;
    Vector2 kapanpozisyon;
    bool acikMi;
    RenkEnum renk;
};

struct PortalStruct{
    std::vector<Vector2> portalPozisyonlari;
    RenkEnum renk;
};