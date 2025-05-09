#include "raylib.h"
#include "Karakter.hpp"
#include "GirdiKontrolcu.hpp"
#include "Harita.hpp"

int main() {
    SetTargetFPS(60);
    InitWindow(9*64, 8*64, "2D Oyun Projesi");
    Karakter* adam = new Karakter({0,0});
    Harita * harita = new Harita();
    while(!WindowShouldClose()){
        
        GirdiKontrolcu::HareketKontrol();
        adam->Guncelle();
        BeginDrawing();
            ClearBackground(WHITE);
            harita->Ciz();
            adam->Ciz();
        EndDrawing();
    }
    delete adam;
    delete harita;
    CloseWindow();
    return 0;
}
