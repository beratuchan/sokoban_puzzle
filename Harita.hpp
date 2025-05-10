// Harita.hpp
#pragma once
#include "GameObject.hpp"
#include <vector>

class Harita : public GameObject{
public:
    Harita(std::vector<std::vector<int>> harita);
    ~Harita();
    void Guncelle() override;
    void Ciz() override;
    
private:
    std::vector<std::vector<int>> harita;
    Texture2D zemin;
    Texture2D duvar;
    int satirSayisi;
    int sutunSayisi;
};