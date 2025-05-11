#include "KesisimKontrolcu.hpp"

KesisimKontrolcu::KesisimKontrolcu(Harita* harita, std::vector<Sandik>* sandiklar, std::vector<Hedef>* hedefler)
    : m_harita(harita), m_sandiklar(sandiklar), m_hedefler(hedefler) {

}

bool KesisimKontrolcu::HucreSandik(Vector2 hucre) const {
    if (!m_sandiklar || m_sandiklar->empty()) return false;
    
    for (auto& sandik : *m_sandiklar) {
        if (sandik.getCizimPozisyonu().x == hucre.x && 
            sandik.getCizimPozisyonu().y == hucre.y) {
            return true;
        }
    }
    return false;
}

bool KesisimKontrolcu::HucreHedef(Vector2 hucre) const {
    if (!m_hedefler || m_hedefler->empty()) return false;
    
    for (auto& hedef : *m_hedefler) {
        if (hedef.getCizimPozisyonu().x == hucre.x && 
            hedef.getCizimPozisyonu().y == hucre.y) {
            return true;
        }
    }
    return false;
}

bool KesisimKontrolcu::HucreDuvar(Vector2 hucre) const {
    if (!m_harita) return false;
    
    int satir = (int)(hucre.y / 64);
    int sutun = (int)(hucre.x / 64);
    auto izgara = m_harita->getIzgara();

    if (satir >= 0 && satir < (int)izgara.size() && sutun >= 0 && sutun < (int)izgara[0].size()) {
        return izgara[satir][sutun] == 1;
    }
    return false;
}

bool KesisimKontrolcu::HucreBos(Vector2 hucre) const {
    return (!HucreDuvar(hucre) && !HucreSandik(hucre));
}

Sandik* KesisimKontrolcu::HucredekiSandigiDondur(Vector2 hucre) const {
    if (!m_sandiklar || m_sandiklar->empty()) return nullptr;
    
    for (size_t i = 0; i < m_sandiklar->size(); i++) {
        Sandik& sandik = (*m_sandiklar)[i];
        if (sandik.getCizimPozisyonu().x == hucre.x && 
            sandik.getCizimPozisyonu().y == hucre.y) {
            return &(*m_sandiklar)[i];
        }
    }
    return nullptr;
}
