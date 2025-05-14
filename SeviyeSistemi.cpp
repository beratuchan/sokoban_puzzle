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

void SeviyeSistemi::OncekiSeviye() {
    if(mevcutSeviye - 1 > (int)SEVIYELER.size()) {
        mevcutSeviye--;
        Baslat();
    }
}

void SeviyeSistemi::MesajVer(){
    if(SeviyeTamamlandiMi()) {
        DokuYonetici::DokuCiz(seviyetamam,{0,0,ekrangenislik/2,ekranyukseklik/2},  {(ekrangenislik/4),(ekranyukseklik/4)});
        Color buton1Renk = LIGHTGRAY;
        Color buton2Renk = LIGHTGRAY;
        Color buton3Renk = LIGHTGRAY;

        Vector2 fare = GetMousePosition();

        DrawRectangleRec(buton1, buton1Renk);
        DrawRectangleRec(buton2, buton2Renk);
        DrawRectangleRec(buton3, buton3Renk);

        if (CheckCollisionPointRec(fare, buton1)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                OncekiSeviye();
        }

        if (CheckCollisionPointRec(fare, buton3)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                SonrakiSeviye();
        }
    }
}

void SeviyeSistemi::Dongu() {
    if(objeYonetici){
        objeYonetici->Dongu();
        if(SeviyeTamamlandiMi()){
            MesajVer();
        }
    }
}

bool SeviyeSistemi::TumSeviyelerBittiMi() const {
    return mevcutSeviye >= (int)SEVIYELER.size() - 1 && SeviyeTamamlandiMi();
}