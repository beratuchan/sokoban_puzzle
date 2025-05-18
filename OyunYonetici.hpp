#ifndef OYUN_YONETICI_HPP
#define OYUN_YONETICI_HPP

#include "SeviyeSistemi.hpp"

class OyunYonetici{
    public:
        OyunYonetici();
        void Guncelle();
        void Ciz();
    private:
        SeviyeSistemi seviyeSistemi;
};
#endif