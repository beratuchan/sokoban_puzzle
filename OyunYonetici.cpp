#include "OyunYonetici.hpp"

OyunYonetici::OyunYonetici(){

}

void OyunYonetici::Ciz(){
    GirdiKontrolcu::HareketKontrol(seviyeSistemi.getObjeYonetici(), seviyeSistemi);
}

void OyunYonetici::Guncelle(){
    seviyeSistemi.Dongu();
}
