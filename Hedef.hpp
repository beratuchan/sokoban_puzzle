#ifndef HEDEF_HPP
#define HEDEF_HPP

#include "GameObject.hpp"
#include "DokuYonetici.hpp"
#include "KesisimKontrolcu.hpp"

class KesisimKontrolcu;

class Hedef : public GameObject {
    public:
        Hedef(Vector2 cizim_pozisyonu, std::string renk, KesisimKontrolcu* kesisimKontrolcu);
        ~Hedef();
        void Guncelle() override;
        void Ciz() override;
        bool getSilinmeliMi() override{return silinmeliMi;};
        std::string GorselSec();
        bool DoluMu();
        Vector2 getCizimPozisyonu(){return cizimPozisyonu;};
        std::string getRenk(){return renk;};
        
    private:
        Texture2D objeDokusu;
        std::string renk;
        Vector2 cizimPozisyonu;
        KesisimKontrolcu* kesisimKontrolcu;
        bool silinmeliMi = false;
};
#endif