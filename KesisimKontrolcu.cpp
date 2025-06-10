#include "KesisimKontrolcu.hpp"

KesisimKontrolcu::KesisimKontrolcu(ObjeYonetici* objeYonetici)
{
    this->objeYonetici = objeYonetici;
}

bool KesisimKontrolcu::HucreSandik(Vector2 hucre) const {
    auto& sandiklar = objeYonetici->getSandiklar();
    for (auto& sandik : sandiklar) {
        if (sandik->getCizimPozisyonu().x == hucre.x && 
            sandik->getCizimPozisyonu().y == hucre.y) {
            return true;
        }
    }
    return false;
}
bool KesisimKontrolcu::HucreKarakter(Vector2 hucre) const {
    auto& karakterler = objeYonetici->getKarakterler();
    for (auto& karakter : karakterler) {
        if (karakter->getCizimPozisyonu().x == hucre.x && 
            karakter->getCizimPozisyonu().y == hucre.y) {
            return true;
        }
    }
    return false;
    /*
    if (!objeYonetici || !objeYonetici->getKarakter()) return false;
    Vector2 karakterPoz = objeYonetici->getKarakter()->getCizimPozisyonu();
    return (karakterPoz.x == hucre.x && karakterPoz.y == hucre.y);
    */
}

bool KesisimKontrolcu::HucrePortal(Vector2 hucre) const{
    auto& portallar = objeYonetici->getPortallar();
    for(auto& portal : portallar){
        if(portal.getCizimPozisyonu1().x==hucre.x && portal.getCizimPozisyonu1().y == hucre.y){
            return true;
        }
        else if(portal.getCizimPozisyonu2().x==hucre.x && portal.getCizimPozisyonu2().y == hucre.y){
            return true;
        }
    }
    return false;
}

int KesisimKontrolcu::HucreKaraDelik(Vector2 hucre) const{
    auto* harita = objeYonetici->getHarita();
    
    int satir = (int)(hucre.y / 64);
    int sutun = (int)(hucre.x / 64);
    auto izgara = harita->getIzgara();

    if (satir >= 0 && satir < (int)izgara.size() && sutun >= 0 && sutun < (int)izgara[0].size()) {
        if(izgara[satir][sutun]>=3)
            return izgara[satir][sutun];
    }
    return 0;
}

int KesisimKontrolcu::HucreRay(Vector2 hucre) const{
    auto* harita = objeYonetici->getHarita();

    int satir = (int)(hucre.y / 64);
    int sutun = (int)(hucre.x / 64);
    auto izgara = harita->getIzgara();

    if (satir >= 0 && satir < (int)izgara.size() && sutun >= 0 && sutun < (int)izgara[0].size()) {
        if(izgara[satir][sutun]>=6)
            return izgara[satir][sutun];
    }
    return 0;
};

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

void KesisimKontrolcu::HucreyiSonrakiFazaGecir(Vector2 hucre){
    auto* harita = objeYonetici->getHarita();
    int satir = (int)(hucre.y / 64);
    int sutun = (int)(hucre.x / 64);
    harita->FazGecisi(hucre);

    harita->getIzgara()[satir][sutun]++;
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
    std::vector<Kapan>& kapanlar = objeYonetici->getKapanlar();
    for (Kapan& kapan : kapanlar) {
        if (hucre.x == kapan.getCizimPozisyonu().x && hucre.y == kapan.getCizimPozisyonu().y) {
            if (!kapan.getAcikMi()) {
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
        Vector2 sandikPoz = sandik->getCizimPozisyonu();
        if (std::abs(sandikPoz.x - hucre.x) < 0.001f && std::abs(sandikPoz.y - hucre.y) < 0.001f) {
            return sandik; 
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

Portal* KesisimKontrolcu::HucredekiPortaliDondur(Vector2 hucre) const{
    auto& portallar = objeYonetici->getPortallar();
    for(auto& portal : portallar){
        if(portal.getCizimPozisyonu1().x==hucre.x && portal.getCizimPozisyonu1().y == hucre.y){
            return &portal;
        }
        else if(portal.getCizimPozisyonu2().x==hucre.x && portal.getCizimPozisyonu2().y == hucre.y){
            return &portal;
        }
    }
    return nullptr;
};