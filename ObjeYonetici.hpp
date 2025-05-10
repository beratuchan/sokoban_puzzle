#include "raylib.h"
#include <vector>
#include "Karakter.hpp"
#include "Sandik.hpp"
#include "Harita.hpp"
#include "Hedef.hpp"
#include "Seviyeler.hpp"

using namespace std;

class ObjeYonetici{
    public:
        ObjeYonetici(); 
        ~ObjeYonetici();
        void Guncelle();
        void Dongu();

    private:
        void SandiklariDoldur();
        void HedefleriDoldur();
        void ObjeleriDoldur();
        Karakter* karakter;
        Harita* harita;
        vector<Sandik> sandiklar;
        vector<Hedef> hedefler;
        vector<GameObject*> objeler;
        vector<SandikStruct> sandikStructlar;
        vector<HedefStruct> hedefStructlar;

};