#include "raylib.h"
#include "Karakter.hpp"
#include "GirdiKontrolcu.hpp"
#include "Harita.hpp"
#include "Hedef.hpp"
#include "Sandik.hpp"
#include "ObjeYonetici.hpp"
#include "SeviyeSistemi.hpp"

int main() {

    SetTargetFPS(60);
    InitWindow(9*64, 8*64, "2D Oyun Projesi");
    SeviyeSistemi seviyeSistemi;
    while(!WindowShouldClose()){
        GirdiKontrolcu::HareketKontrol();
        BeginDrawing();
        ClearBackground((Color){122, 146, 148, 255});
        seviyeSistemi.Dongu();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
