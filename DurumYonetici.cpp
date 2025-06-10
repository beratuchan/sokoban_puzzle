#include "DurumYonetici.hpp"

DurumYonetici::DurumYonetici(ObjeYonetici* objeYonetici){
    this->objeYonetici = objeYonetici;
}

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

void DurumYonetici::setKarakterSilindiMi(bool silindi){
    if(silindi)
        karakterSilindiMi = true;
    else
        karakterSilindiMi = false;
}

void DurumYonetici::setSandikSilindiMi(bool silindi){
    if(silindi || ((int)objeYonetici->getSandiklar().size() < objeYonetici->getSandikSayisi()))
        sandikSilindiMi = true;
    else    
        sandikSilindiMi = false;
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