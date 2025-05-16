#include "KesisimKontrolcu.hpp"

KesisimKontrolcu::KesisimKontrolcu(ObjeYonetici* objeYonetici)
{
    this->objeYonetici = objeYonetici;
}

bool KesisimKontrolcu::HucreSandik(Vector2 hucre) const {
    auto& sandiklar = objeYonetici->getSandiklar();
    for (auto& sandik : sandiklar) {
        if (sandik.getCizimPozisyonu().x == hucre.x && 
            sandik.getCizimPozisyonu().y == hucre.y) {
            return true;
        }
    }
    return false;
}

bool KesisimKontrolcu::HucreKarakter(Vector2 hucre) const {
    if (!objeYonetici || !objeYonetici->getKarakter()) return false;
    Vector2 karakterPoz = objeYonetici->getKarakter()->getCizimPozisyonu();
    return (karakterPoz.x == hucre.x && karakterPoz.y == hucre.y);
}

bool KesisimKontrolcu::HucreHedef(Vector2 hucre) const {
    auto& hedefler = objeYonetici->getHedefler();
    
    for (auto& hedef : hedefler) {
        if (hedef.getCizimPozisyonu().x == hucre.x && 
            hedef.getCizimPozisyonu().y == hucre.y) {
            return true;
        }
    }
    return false;
}

bool KesisimKontrolcu::HucreDuvar(Vector2 hucre) const {
    auto* harita = objeYonetici->getHarita();
    
    int satir = (int)(hucre.y / 64);
    int sutun = (int)(hucre.x / 64);
    auto izgara = harita->getIzgara();

    if (satir >= 0 && satir < (int)izgara.size() && sutun >= 0 && sutun < (int)izgara[0].size()) {
        return izgara[satir][sutun] == 1;
    }
    return false;
}

bool KesisimKontrolcu::HucreKapaliKapan(Vector2 hucre) const{
    std::vector<Kapan> kapanlar = objeYonetici->getKapanlar();
    for(Kapan kapan: kapanlar){
        if(hucre.x == kapan.getCizimPozisyonu().x && hucre.y == kapan.getCizimPozisyonu().y){
            if(!kapan.getAcikMi()){
                return true;
            }
        }
    }
    return false;
};

bool KesisimKontrolcu::HucreBos(Vector2 hucre) const {
    return (!HucreDuvar(hucre) && !HucreSandik(hucre) && !HucreKarakter(hucre) && !HucreKapaliKapan(hucre));
}


bool KesisimKontrolcu::HucreBuz(Vector2 hucre){
    auto* harita = objeYonetici->getHarita();
    
    int satir = (int)(hucre.y / 64);
    int sutun = (int)(hucre.x / 64);
    auto izgara = harita->getIzgara();

    if (satir >= 0 && satir < (int)izgara.size() && sutun >= 0 && sutun < (int)izgara[0].size()) {
        return izgara[satir][sutun] == 2;
    }
    return false;
}

Sandik* KesisimKontrolcu::HucredekiSandigiDondur(Vector2 hucre) const {
    if (!objeYonetici) return nullptr; 
    auto& sandiklar = objeYonetici->getSandiklar();
    for (auto& sandik : sandiklar) {
        Vector2 sandikPoz = sandik.getCizimPozisyonu();
        if (std::abs(sandikPoz.x - hucre.x) < 0.001f && std::abs(sandikPoz.y - hucre.y) < 0.001f) {
            return &sandik; 
        }
    }
    return nullptr; 
}

Hedef* KesisimKontrolcu::HucredekiHedefiDondur(Vector2 hucre) const{
    auto& hedefler = objeYonetici->getHedefler();
    
    for (size_t i = 0; i < hedefler.size(); i++) {
        Hedef& hedef = hedefler[i];
        if (hedef.getCizimPozisyonu().x == hucre.x && 
            hedef.getCizimPozisyonu().y == hucre.y) {
            return &hedefler[i];
        }
    }
    return nullptr;
};
