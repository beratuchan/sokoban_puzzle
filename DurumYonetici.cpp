#include "DurumYonetici.hpp"

void DurumYonetici::Kaydet(const Durum& durum) {
    if (mevcutIndex < (int)durumlar.size() - 1) {
        durumlar.erase(durumlar.begin() + mevcutIndex + 1, durumlar.end());
    }
    durumlar.push_back(durum);
    mevcutIndex++;

    if (durumlar.size() > MAX_DURUM) {
        durumlar.erase(durumlar.begin());
        mevcutIndex--;
    }
}

Durum DurumYonetici::GeriAl() {
    if (GeriAlinabilir()) {
        mevcutIndex--;
        return durumlar[mevcutIndex];
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