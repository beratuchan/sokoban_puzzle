#include "DurumYonetici.hpp"

void DurumYonetici::Kaydet(const Durum& durum) {
    if (mevcutIndex < (int)durumlar.size() - 1) {
        durumlar.erase(durumlar.begin() + mevcutIndex + 1, durumlar.end());
    }
    durumlar.push_back(durum);
    mevcutIndex++;
}

Durum DurumYonetici::GeriAl() {
    if (GeriAlinabilir()) {
        Durum dondurulecek = durumlar[mevcutIndex];
        mevcutIndex--;
        return dondurulecek;
    }
    return Durum{}; 
}

bool DurumYonetici::GeriAlinabilir() {
    return mevcutIndex > 0;
}

bool DurumYonetici::BosMu() const {
    return mevcutIndex > 0;
}

void DurumYonetici::Temizle() {
    durumlar.clear();
    mevcutIndex = -1;
}