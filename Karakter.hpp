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
class DurumYonetici;

class Karakter : public GameObject {
    public:
        Karakter(Vector2 pozisyon, bool aktifMi, int karakterNo, ObjeYonetici* objeYonetici, DurumYonetici* durumYonetici);
        ~Karakter();
        void Guncelle() override;
        void Ciz() override;
        bool getSilinmeliMi() override{return silinmeliMi;};
        void Tetikle(Vector2 ileriHucre);
        void AnimasyonuGuncelle();
        Vector2 IleriHucrePozisyonu(Yon yon, Vector2& baslangicPoz);
        void DurumKaydet();
        void PozisyonAta(Vector2 yeniPozisyon);
        Vector2 getCizimPozisyonu() {return cizimPozisyonu;};
        bool getAktifMi(){return aktifMi;};
        void setAktifMi(bool aktifMi);
        void setKarakterNo(int karakterNo);
        bool getKarakterNo(){return karakterNo;};
        void Dus();
        void DusmeTetikle(Vector2 ileriHucre);
        void setCizilmeliMi(bool cizilmeliMi){this->cizilmeliMi = cizilmeliMi;};
        bool getCizilmeliMi(){return cizilmeliMi;};
    private:
        void HareketTetikle(Vector2 gidilecekPozisyon);
        void BuzdaKayTetikle();
        void HareketEttir();
        void BuzdaKay();
        void PortalTetikle(Vector2 ileriHucre);
        
        Texture2D objeDokusu;
        bool cizilmeliMi;
        Vector2 cizimPozisyonu;
        Vector2 gidilecekPozisyon;
        Vector2 oncekiPozisyon;
        Rectangle kare;
        Rectangle hedefKare;

        DurumYonetici* durumYonetici;
        ObjeYonetici* objeYonetici;
        Yon mevcutYon;

        int karakterNo;
        bool aktifMi;

        bool hareketEdiyor = false;
        bool dusuyor = false;
        bool buzdaKayiyor = false;
        bool silinmeliMi = false;
        float mevcutFrame = 0;
        int frameGenisligi;
        int frameYuksekligi;
        float donmeAcisi;

};
#endif