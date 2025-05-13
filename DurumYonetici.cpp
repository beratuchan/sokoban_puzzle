#include "DurumYonetici.hpp"

void DurumYonetici::Kaydet(const Durum& durum) {
    durumlar.push(durum);
}

Durum DurumYonetici::GeriAl() {
    Durum son = durumlar.top();
    durumlar.pop();
    return son;
}

bool DurumYonetici::BosMu() const {
    return durumlar.empty();
}

void DurumYonetici::Temizle() {
    while (!durumlar.empty()) {
        durumlar.pop();
}
}