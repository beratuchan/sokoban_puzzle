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
#include "Structlar.hpp"
#include "Portal.hpp"


class Karakter;
class Sandik;
class Hedef;
class Kapan;
class Portal;
class Miknatis;

class ObjeYonetici{
    public:
        ObjeYonetici(int seviyeNo); 
        ~ObjeYonetici();
        void Dongu();
        void Guncelle();
        std::vector<Sandik*>& getSandiklar(){return sandiklar;};
        std::vector<Hedef>& getHedefler(){return hedefler;};
        std::vector<Portal>& getPortallar(){return portallar;};
        std::vector<Karakter*>& getKarakterler(){return karakterler;};
        Harita* getHarita(){return harita;};
        std::vector<Kapan>& getKapanlar() { return kapanlar; }
        KesisimKontrolcu* getKesisimKontolcu(){return kesisimKontrolcu;};
        DurumYonetici* getDurumYonetici(){return durumYonetici;};
        ObjeYonetici* getObjeYonetici() { return objeYonetici; }
        void BaslangicDurumunuKaydet();
        void YeniKarakterOlustur(Vector2 pozisyon);
        void YeniSandikOlustur(SandikStruct sandikstruct);
        int getSandikSayisi(){return sandikSayisi;};
        void KarakterDegistir();
    private:
        void SandiklariDoldur();
        void HedefleriDoldur();
        void ObjeleriDoldur();
        void KapanlariDoldur();
        void PortallariDoldur();
        void KarakterleriDoldur();
        
        int seviyeNo;
        int sandikSayisi;

        KesisimKontrolcu* kesisimKontrolcu;
        Harita* harita;
        DurumYonetici* durumYonetici;
        ObjeYonetici* objeYonetici;

        std::vector<Portal> portallar;
        std::vector<Kapan> kapanlar;
        std::vector<Sandik*> sandiklar;
        std::vector<Karakter*> karakterler;
        std::vector<Hedef> hedefler;
        
        std::vector<GameObject*> objeler;

        std::vector<SandikStruct> sandikStructlar;
        std::vector<HedefStruct> hedefStructlar;
        std::vector<KapanStruct> kapanStructlar;
        std::vector<PortalStruct> portalStructlar;
        std::vector<Vector2> karakterStructlar;
};

#endif