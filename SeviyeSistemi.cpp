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

void SeviyeSistemi::ButonEkle(){
        float ekranyukseklik = 11*64;
        float ekrangenislik = (9*64);
        float butongenisligi = 57;
        float arabosluk = (ekrangenislik-(3*butongenisligi))/4;
        
        Rectangle buton1 = {arabosluk, ekranyukseklik+10, butongenisligi, 53};
        Rectangle buton2 = {arabosluk*2 + butongenisligi, ekranyukseklik+10, butongenisligi, 53};
        Rectangle buton3 = {arabosluk*3 + butongenisligi*2, ekranyukseklik+10, butongenisligi, 53};

        Vector2 fare = GetMousePosition();

        DokuYonetici::DokuCiz(onceki,{0,0,53,53},{buton1.x+2,buton1.y});
        DokuYonetici::DokuCiz(tekrar,{0,0,53,53},{buton2.x+2,buton2.y});
        DokuYonetici::DokuCiz(sonraki,{0,0,53,53},{buton3.x+2,buton3.y});

        if (CheckCollisionPointRec(fare, buton1)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                OncekiSeviye();
        }

        if (CheckCollisionPointRec(fare, buton2)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                Baslat();
        }

        if (CheckCollisionPointRec(fare, buton3)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                SonrakiSeviye();
        }
}

void SeviyeSistemi::SonrakiSeviye() {
    if(mevcutSeviye + 1 < (int)SEVIYELER.size()) {
        mevcutSeviye++;
        Baslat();
    }
}

void SeviyeSistemi::OncekiSeviye() {
    if(mevcutSeviye - 1 >= 0) {
        mevcutSeviye--;
        Baslat();
    }
}

void SeviyeSistemi::MesajVer(){
    if(SeviyeTamamlandiMi()) {
        DokuYonetici::DokuCiz(seviyetamam,{0,0,ekrangenislik/2,ekranyukseklik/2},  {(ekrangenislik/4),(ekranyukseklik/4)});
        Vector2 fare = GetMousePosition();

        DokuYonetici::DokuCiz(onceki,{0,0,53,53},{2*bos+ekrangenislik/4,255+ekranyukseklik/4+bos});
        DokuYonetici::DokuCiz(tekrar,{0,0,53,53},{3*bos+ekrangenislik/4+butongen + (2*butongen-53)/2,255+ekranyukseklik/4+bos});
        DokuYonetici::DokuCiz(sonraki,{0,0,53,53},{4*bos+ekrangenislik/4+3*butongen,255+ekranyukseklik/4+bos});

        if (CheckCollisionPointRec(fare, buton1)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                OncekiSeviye();
        }

        if (CheckCollisionPointRec(fare, buton2)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                Baslat();
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
        else{
            ButonEkle();
        }
    }
}

bool SeviyeSistemi::TumSeviyelerBittiMi() const {
    return mevcutSeviye >= (int)SEVIYELER.size() - 1 && SeviyeTamamlandiMi();
}