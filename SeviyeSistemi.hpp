#ifndef SEVIYE_SISTEMI_HPP
#define SEVIYE_SISTEMI_HPP

#include "ObjeYonetici.hpp"
#include "Seviyeler.hpp"
class ObjeYonetici;

class SeviyeSistemi {
    public:
        SeviyeSistemi();
        ~SeviyeSistemi();
        
        void Baslat();
        void SonrakiSeviye();
        void OncekiSeviye();
        void Dongu();
        bool TumSeviyelerBittiMi() const;
        void MesajVer();
        void ButonEkle();
        ObjeYonetici* getObjeYonetici() { return objeYonetici; }

    private:
        int mevcutSeviye;
        ObjeYonetici* objeYonetici;
        bool SeviyeTamamlandiMi() const;
        
        Texture2D seviyetamam = DokuYonetici::DokuYukle("resources/seviyesonu.png");
        Texture2D sonraki = DokuYonetici::DokuYukle("resources/sagoklar.png");
        Texture2D onceki = DokuYonetici::DokuYukle("resources/soloklar.png");
        Texture2D tekrar = DokuYonetici::DokuYukle("resources/tekrarla.png");
        float ekrangenislik = (9*64);
        float ekranyukseklik = (11*64);
        float bos = 10;
        float butongen = (ekrangenislik/2 - 6*bos)/4;
        Rectangle buton1 = {2*bos+ekrangenislik/4,255+ekranyukseklik/4+bos,butongen, butongen};
        Rectangle buton2 = {3*bos+ekrangenislik/4+butongen,255+ekranyukseklik/4+bos,2*butongen, butongen};
        Rectangle buton3 = {4*bos+ekrangenislik/4+3*butongen,255+ekranyukseklik/4+bos,butongen, butongen};
};

#endif