#include "raylib.h"
#include "Karakter.hpp"
#include "GirdiKontrolcu.hpp"

int main() {
    
    SetTargetFPS(60);
    InitWindow(6*64, 6*64, "2D Oyun Projesi");
    Karakter* adam = new Karakter({8,9});
    while(!WindowShouldClose()){
        GirdiKontrolcu::HareketKontrol();
        adam->Guncelle();
        BeginDrawing();
            ClearBackground(WHITE);
            adam->Ciz();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}