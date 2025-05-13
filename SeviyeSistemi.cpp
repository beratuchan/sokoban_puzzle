#include "SeviyeSistemi.hpp"
#include "iostream"
SeviyeSistemi::SeviyeSistemi() : mevcutSeviye(0), objeYonetici(nullptr) {
    Baslat();
}

SeviyeSistemi::~SeviyeSistemi() {
    delete objeYonetici;
}

void SeviyeSistemi::Baslat() {
    delete objeYonetici;
    objeYonetici = new ObjeYonetici(mevcutSeviye);
}

bool SeviyeSistemi::SeviyeTamamlandiMi() const {
    if(!objeYonetici) return false;
    std::vector<Hedef> hedefler = objeYonetici->getHedefler();
    for(Hedef hedef: hedefler){
        if(!hedef.DoluMu()){
            return false;
        }
    }
    return true;
}

void SeviyeSistemi::SonrakiSeviye() {

    
    if(mevcutSeviye + 1 < (int)SEVIYELER.size()) {
        mevcutSeviye++;
        Baslat();
    }
}

void SeviyeSistemi::Dongu() {
    if(SeviyeTamamlandiMi()) {
        SonrakiSeviye();
    }
    if(objeYonetici) objeYonetici->Dongu();
}

bool SeviyeSistemi::TumSeviyelerBittiMi() const {
    return mevcutSeviye >= (int)SEVIYELER.size() - 1 && SeviyeTamamlandiMi();
}