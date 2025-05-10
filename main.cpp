#include "raylib.h"
#include "Karakter.hpp"
#include "GirdiKontrolcu.hpp"
#include "Harita.hpp"
#include "Hedef.hpp"
#include "Sandik.hpp"

int main() {
    SetTargetFPS(60);
    InitWindow(9*64, 8*64, "2D Oyun Projesi");
    Karakter* adam = new Karakter({0,0});
    Harita * harita = new Harita();
    Hedef* hedef = new Hedef({64*2,64*1},"yesil");
    Sandik* sandik = new Sandik({0,64},"mavi");

    while(!WindowShouldClose()){
        
        GirdiKontrolcu::HareketKontrol();
        
        adam->Guncelle();
        BeginDrawing();
            ClearBackground(WHITE);
            harita->Ciz();
            hedef->Ciz();
            adam->Ciz();
            sandik->Ciz();
        EndDrawing();
    }
    delete adam;
    delete harita;
    CloseWindow();
    return 0;
}
