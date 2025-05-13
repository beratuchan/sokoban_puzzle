#include "raylib.h"
#include "GirdiKontrolcu.hpp"

Yon GirdiKontrolcu::mevcutYon = Yon::HAREKETSIZ;
int GirdiKontrolcu::hareketSayaci = 0;

void GirdiKontrolcu::HareketKontrol(ObjeYonetici* objeYonetici){
    mevcutYon = Yon::HAREKETSIZ;
    if(IsKeyPressed(KEY_W)||IsKeyPressed(KEY_UP)) mevcutYon = Yon::YUKARI;
    else if(IsKeyPressed(KEY_S)||IsKeyPressed(KEY_DOWN)) mevcutYon = Yon::ASAGI;
    if(IsKeyPressed(KEY_D)||IsKeyPressed(KEY_RIGHT)) mevcutYon = Yon::SAGA;
    else if(IsKeyPressed(KEY_A)||IsKeyPressed(KEY_LEFT)) mevcutYon = Yon::SOLA;
    
    if (IsKeyPressed(KEY_G)) GeriAl(objeYonetici);
}

void GirdiKontrolcu::GeriAl(ObjeYonetici* objeYonetici){
    if (!objeYonetici) return;
    
    DurumYonetici* durumYonetici = objeYonetici->getDurumYonetici();
    if (!durumYonetici || !durumYonetici->GeriAlinabilir()) return;

    Durum oncekiDurum = durumYonetici->GeriAl(); 

    objeYonetici->getKarakter()->PozisyonAta(oncekiDurum.karakterPozisyon);
    
    auto& sandiklar = objeYonetici->getKesisimKontolcu()->getSandiklar();
    if (oncekiDurum.sandikPozisyonlar.size() == sandiklar.size()) {
        for (size_t i = 0; i < sandiklar.size(); ++i) {
            sandiklar[i].PozisyonAta(oncekiDurum.sandikPozisyonlar[i]);
        }
    }
    
    hareketSayaci = oncekiDurum.hareketSayaci;
}