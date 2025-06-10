#pragma once
#include <vector>
#include <raylib.h>
#include <cstddef>
#include <stack>
#include "ObjeYonetici.hpp"
#include "Structlar.hpp"

struct SandikStruct;
class ObjeYonetici;

struct Durum {
    std::vector<KarakterStruct> karakterStructlar;
    std::vector<SandikStruct> sandikStructlar;
    int hareketSayaci;
    std::vector<std::vector<int>> haritaIzgara;
};

class DurumYonetici {
public:
    DurumYonetici(ObjeYonetici* objeYonetici);
    void Kaydet(const Durum& durum);
    bool GeriAlinabilir();
    Durum GeriAl();
    bool BosMu() const;
    void Temizle();
    void setKarakterSilindiMi(bool silindi);
    bool getKarakterSilindiMi(){return karakterSilindiMi;}
    void setSandikSilindiMi(bool silindi);
    bool getSandikSilindiMi(){return sandikSilindiMi;};
private:
    std::vector<Durum> durumlar;
    int mevcutIndex = -1;
    bool karakterSilindiMi = false;
    bool sandikSilindiMi = false;
    ObjeYonetici* objeYonetici;
};