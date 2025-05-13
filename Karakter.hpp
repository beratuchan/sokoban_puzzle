#ifndef KARAKTER_HPP
#define KARAKTER_HPP

#include "GameObject.hpp"
#include "DokuYonetici.hpp"
#include "YonEnum.hpp"
#include "GirdiKontrolcu.hpp"
#include "KesisimKontrolcu.hpp"
#include "DurumYonetici.hpp"

class Karakter : public GameObject {
    public:
        Karakter(Vector2 pozisyon, KesisimKontrolcu* kesisimKontrolcu, DurumYonetici* durumYonetici);
        ~Karakter();
        void Guncelle() override;
        void Ciz() override;
        void AnimasyonuGuncelle();
        Vector2 IleriHucrePozisyonu(Yon yon, const Vector2& baslangicPoz);
        void DurumKaydet();
        void PozisyonAta(Vector2 yeniPozisyon);
        Vector2 getCizimPozisyonu() {return cizimPozisyonu;};
        void HareketEttir();
        void HareketTetikle(Vector2 gidilecekPozisyon);

    private:
        Texture2D objeDokusu;
        Vector2 cizimPozisyonu;
        Vector2 gidilecekPozisyon;
        Vector2 oncekiPozisyon;
        Rectangle kare;
        KesisimKontrolcu* kesisimKontrolcu;
        DurumYonetici* durumYonetici;
        Yon mevcutYon;

        bool hareketEdiyor = false;
        float mevcutFrame = 0;
        int frameGenisligi;
        int frameYuksekligi;
        

};
#endif