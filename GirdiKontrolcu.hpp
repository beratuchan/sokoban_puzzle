#ifndef GIRDI_KONTROLCU_HPP
#define GIRDI_KONTROLCU_HPP

#include "YonEnum.hpp"
#include "ObjeYonetici.hpp"
#include "SeviyeSistemi.hpp"

class ObjeYonetici;
class SeviyeSistemi;

class GirdiKontrolcu{
    public:
        static void HareketKontrol(ObjeYonetici* objeYonetici, SeviyeSistemi& SeviyeSistemi);
        static Yon mevcutYon;
        static int hareketSayaci;
    private:
        static void GeriAl(ObjeYonetici* objeYonetici);
        static void CizimKontrol(SeviyeSistemi& seviyeSistemi);
};

#endif