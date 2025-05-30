#ifndef OBJEYONETICI_HPP
#define OBJEYONETICI_HPP

#include <vector>
#include "GameObject.hpp"
#include "raylib.h"
#include "Karakter.hpp"
#include "Sandik.hpp"
#include "Harita.hpp"
#include "Hedef.hpp"
#include "Kapan.hpp"
#include "Seviyeler.hpp"
#include "KesisimKontrolcu.hpp"
#include "DurumYonetici.hpp"

class Karakter;
class Sandik;
class Hedef;
class Kapan;

class ObjeYonetici{
    public:
        ObjeYonetici(int seviyeNo); 
        ~ObjeYonetici();
        void Dongu();

        std::vector<Sandik>& getSandiklar(){return sandiklar;};
        std::vector<Hedef>& getHedefler(){return hedefler;};
        Karakter* getKarakter(){return karakter;};
        Harita* getHarita(){return harita;};
        std::vector<Kapan>& getKapanlar() { return kapanlar; }
        KesisimKontrolcu* getKesisimKontolcu(){return kesisimKontrolcu;};
        DurumYonetici* getDurumYonetici(){return durumYonetici;};
        ObjeYonetici* getObjeYonetici() { return objeYonetici; }
        void BaslangicDurumunuKaydet();

    private:
        void SandiklariDoldur();
        void HedefleriDoldur();
        void ObjeleriDoldur();
        void KapanlariDoldur();

        Karakter* karakter;
        KesisimKontrolcu* kesisimKontrolcu;
        Harita* harita;
        DurumYonetici* durumYonetici;
        ObjeYonetici* objeYonetici;

        std::vector<Kapan> kapanlar;
        std::vector<Sandik> sandiklar;
        std::vector<Hedef> hedefler;
        std::vector<GameObject*> objeler;

        std::vector<SandikStruct> sandikStructlar;
        std::vector<HedefStruct> hedefStructlar;
        std::vector<KapanStruct> kapanStructlar;
};

#endif