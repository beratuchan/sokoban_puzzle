#ifndef HARITA_HPP
#define HARITA_HPP

#include <vector>
#include "GameObject.hpp"


class Harita : public GameObject{
public:
    Harita(std::vector<std::vector<int>> harita);
    ~Harita();
    void Guncelle() override;
    void Ciz() override;
    std::vector<std::vector<int>> getIzgara(){return izgara;};

private:
    std::vector<std::vector<int>> izgara;
    Texture2D zemin;
    Texture2D duvar;
    Texture2D buz;
    int satirSayisi;
    int sutunSayisi;
};

#endif