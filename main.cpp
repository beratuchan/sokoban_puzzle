#include "raylib.h"
#include "Karakter.hpp"
#include "GirdiKontrolcu.hpp"
#include "Harita.hpp"
#include "Hedef.hpp"
#include "Sandik.hpp"
#include "ObjeYonetici.hpp"
#include "SeviyeSistemi.hpp"
#include "OyunDurumuEnum.hpp"
#include "BaslangicEkrani.hpp"
#include "OyunYonetici.hpp"

int main() {
    SetTargetFPS(60);
    InitWindow(9*64, 11*64 +10+53+10 , "2D Oyun Projesi");

    SeviyeSistemi seviyeSistemi;
    BaslangicEkrani baslangicEkrani;
    OyunYonetici oyunYonetici;

    OyunDurumu mevcutDurum = OyunDurumu::BASLANGIC;
    
    while (!WindowShouldClose()) {
        switch(mevcutDurum) {
            case OyunDurumu::BASLANGIC:
                mevcutDurum = baslangicEkrani.Guncelle();
                break;
                
            case OyunDurumu::OYUN:
                oyunYonetici.Guncelle();
                break;
        }

        BeginDrawing();
        ClearBackground((Color){122, 146, 148, 255});
        switch(mevcutDurum) {
            case OyunDurumu::BASLANGIC:
                baslangicEkrani.Ciz();
                break;
                
            case OyunDurumu::OYUN:
                oyunYonetici.Ciz();
                break;
        }
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
