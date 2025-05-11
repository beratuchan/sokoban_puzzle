#ifndef KARAKTER_HPP
#define KARAKTER_HPP

#include "GameObject.hpp"
#include "DokuYonetici.hpp"
#include "YonEnum.hpp"
#include "GirdiKontrolcu.hpp"
#include "KesisimKontrolcu.hpp"

class Karakter : public GameObject {
    public:
        Karakter(Vector2 pozisyon, KesisimKontrolcu* kesisimKontrolcu);
        ~Karakter();
        void Guncelle() override;
        void Ciz() override;
        void AnimasyonuGuncelle();
        Vector2 IleriHucrePozisyonu(Yon yon, const Vector2& baslangicPoz);

    private:
        Texture2D objeDokusu;
        Vector2 cizimPozisyonu;
        Rectangle kare;
        KesisimKontrolcu* m_kesisimKontrolcu;

        int currentFrame = 0;
        int framesCounter = 0;
        int frameWidth;
        int frameHeight;
};
#endif