#ifndef GIRDI_KONTROLCU_HPP
#define GIRDI_KONTROLCU_HPP

#include "YonEnum.hpp"
#include "ObjeYonetici.hpp"

class ObjeYonetici;

class GirdiKontrolcu{
    public:
        static void HareketKontrol(ObjeYonetici* objeYonetici);
        static Yon mevcutYon;
        static int hareketSayaci;
    private:
        static void GeriAl(ObjeYonetici* objeYonetici);
};

#endif