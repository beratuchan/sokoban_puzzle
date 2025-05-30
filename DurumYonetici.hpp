#pragma once
#include <vector>
#include <raylib.h>
#include <cstddef>
#include <stack>

struct Durum {
    Vector2 karakterPozisyon;
    std::vector<Vector2> sandikPozisyonlar;
    int hareketSayaci;
};

class DurumYonetici {
public:
    void Kaydet(const Durum& durum);
    bool GeriAlinabilir();
    Durum GeriAl();
    bool BosMu() const;
    void Temizle();

private:
    std::vector<Durum> durumlar;
    int mevcutIndex = -1;
};