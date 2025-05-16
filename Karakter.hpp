#ifndef KARAKTER_HPP
#define KARAKTER_HPP

#include "GameObject.hpp"
#include "DokuYonetici.hpp"
#include "YonEnum.hpp"
#include "GirdiKontrolcu.hpp"
#include "ObjeYonetici.hpp"
#include "DurumYonetici.hpp"

class KesisimKontrolcu;
class ObjeYonetici;

class Karakter : public GameObject {
    public:
        Karakter(Vector2 pozisyon, ObjeYonetici* objeYonetici, DurumYonetici* durumYonetici);
        ~Karakter();
        void Guncelle() override;
        void Ciz() override;
        void Tetikle();
        void AnimasyonuGuncelle();
        Vector2 IleriHucrePozisyonu(Yon yon, Vector2& baslangicPoz);
        void DurumKaydet();
        void PozisyonAta(Vector2 yeniPozisyon);
        Vector2 getCizimPozisyonu() {return cizimPozisyonu;};

    private:
        void HareketTetikle(Vector2 gidilecekPozisyon);
        void BuzdaKayTetikle();
        void HareketEttir();
        void BuzdaKay();
        
        Texture2D objeDokusu;
        Vector2 cizimPozisyonu;
        Vector2 gidilecekPozisyon;
        Vector2 oncekiPozisyon;
        Rectangle kare;

        DurumYonetici* durumYonetici;
        ObjeYonetici* objeYonetici;
        Yon mevcutYon;

        bool hareketEdiyor = false;
        bool buzdaKayiyor = false;
        float mevcutFrame = 0;
        int frameGenisligi;
        int frameYuksekligi;
        

};
#endif