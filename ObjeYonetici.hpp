#ifndef OBJEYONETICI_HPP
#define OBJEYONETICI_HPP

#include <vector>
#include "GameObject.hpp"
#include "raylib.h"
#include "Karakter.hpp"
#include "Sandik.hpp"
#include "Harita.hpp"
#include "Hedef.hpp"
#include "Seviyeler.hpp"
#include "KesisimKontrolcu.hpp"

class ObjeYonetici{
    public:
        ObjeYonetici(int seviyeNo); 
        ~ObjeYonetici();
        void Dongu();

        std::vector<Sandik>& getSandiklar();
        std::vector<Hedef>& getHedefler();
        Karakter* getKarakter();
        Harita* getHarita();
        KesisimKontrolcu* getKesisimKontolcu();

    private:
        void SandiklariDoldur();
        void HedefleriDoldur();
        void ObjeleriDoldur();

        Karakter* karakter;
        KesisimKontrolcu* kesisimKontrolcu;
        Harita* harita;

        std::vector<Sandik> sandiklar;
        std::vector<Hedef> hedefler;
        std::vector<GameObject*> objeler;

        std::vector<SandikStruct> sandikStructlar;
        std::vector<HedefStruct> hedefStructlar;

};

#endif