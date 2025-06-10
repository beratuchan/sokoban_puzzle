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
    bool getSilinmeliMi() override{return silinmeliMi;};
    std::vector<std::vector<int>>& getIzgara(){return izgara;};
    void setIzgara(std::vector<std::vector<int>> izgara);
    void FazGecisi(Vector2 hucre);
private:
    std::vector<std::vector<int>> izgara;
    Texture2D zemin;
    Texture2D duvar;
    Texture2D buz;
    Texture2D karadelik;
    Texture2D raylar;
    int satirSayisi;
    int sutunSayisi;
    bool silinmeliMi = false;
    float gecisSuresi = 2.0f;       
    float gecenSure = 0.0f; 
};

#endif 