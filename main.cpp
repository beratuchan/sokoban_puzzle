#include "raylib.h"
#include "Karakter.hpp"

int main() {
    const int screenWidth = 6*64;
    const int screenHeight = 6*64;
    Color zeminrengi = {122,146,148};
    InitWindow(screenWidth, screenHeight, "2D Oyun Projesi");
    SetTargetFPS(60);

    Karakter adam("resources/adam.png" , 3*64, 3*64);

    while (!WindowShouldClose()) {
        adam.Guncelle();
        
        BeginDrawing();
            ClearBackground(zeminrengi);
            adam.Ciz();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}