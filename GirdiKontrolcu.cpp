#include "raylib.h"
#include "GirdiKontrolcu.hpp"

Yon GirdiKontrolcu::mevcutYon = Yon::HAREKETSIZ;
int GirdiKontrolcu::hareketSayaci = 0;

void GirdiKontrolcu::HareketKontrol(){
    mevcutYon = Yon::HAREKETSIZ;
    if(IsKeyPressed(KEY_W)) mevcutYon = Yon::ILERI;
    else if(IsKeyPressed(KEY_S)) mevcutYon = Yon::GERI;
    if(IsKeyPressed(KEY_D)) mevcutYon = Yon::SAGA;
    else if(IsKeyPressed(KEY_A)) mevcutYon = Yon::SOLA;
}