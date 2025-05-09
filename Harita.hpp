// Harita.hpp
#pragma once
#include "GameObject.hpp"
#include <vector>


class Harita{
public:
    Harita();
    ~Harita();
    void Ciz();
    
private:
    std::vector<std::vector<int>> harita;
    Texture2D zemin;
    Texture2D duvar;
    int satirSayisi;
    int sutunSayisi;
};