#include "raylib.h"
#include "GirdiKontrolcu.hpp"

Yon GirdiKontrolcu::mevcutYon = Yon::HAREKETSIZ;
int GirdiKontrolcu::hareketSayaci = 0;

void GirdiKontrolcu::HareketKontrol(){
    mevcutYon = Yon::HAREKETSIZ;
    if(IsKeyPressed(KEY_W)||IsKeyPressed(KEY_UP)) mevcutYon = Yon::YUKARI;
    else if(IsKeyPressed(KEY_S)||IsKeyPressed(KEY_DOWN)) mevcutYon = Yon::ASAGI;
    if(IsKeyPressed(KEY_D)||IsKeyPressed(KEY_RIGHT)) mevcutYon = Yon::SAGA;
    else if(IsKeyPressed(KEY_A)||IsKeyPressed(KEY_LEFT)) mevcutYon = Yon::SOLA;
}