#include "BaslangicEkrani.hpp"

BaslangicEkrani::BaslangicEkrani(){
    maskot = DokuYonetici::DokuYukle("resources/maskot.png");
    baslaButon = { (9*64 - 200)/2, 300, 200, 50 };
    cikisButon = { (9*64 - 200)/2, 400, 200, 50 };
}
BaslangicEkrani::~BaslangicEkrani(){

}

OyunDurumu BaslangicEkrani::Guncelle(){
    if (CheckCollisionPointRec(GetMousePosition(), baslaButon) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        return OyunDurumu::OYUN;
    }
    return OyunDurumu::BASLANGIC;
}

void BaslangicEkrani::Ciz(){
    DrawTexture(maskot, 0, 0, WHITE);
    DrawRectangleRec(baslaButon, CheckCollisionPointRec(GetMousePosition(), baslaButon) ? SKYBLUE : BLUE);
    DrawText("BASLA", baslaButon.x + 50, baslaButon.y + 15, 20, WHITE);
}