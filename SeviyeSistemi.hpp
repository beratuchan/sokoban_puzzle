#ifndef SEVIYE_SISTEMI_HPP
#define SEVIYE_SISTEMI_HPP

#include "ObjeYonetici.hpp"
#include "Seviyeler.hpp"

class SeviyeSistemi {
    public:
        SeviyeSistemi();
        ~SeviyeSistemi();
        
        void Baslat();
        void SonrakiSeviye();
        void Dongu();
        bool TumSeviyelerBittiMi() const;
        ObjeYonetici* getObjeYonetici() { return objeYonetici; }

    private:
        int mevcutSeviye;
        ObjeYonetici* objeYonetici;
        bool SeviyeTamamlandiMi() const;
};

#endif