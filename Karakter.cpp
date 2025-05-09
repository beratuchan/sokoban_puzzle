#include "Karakter.hpp"

Karakter::Karakter(const char* textureSheet, int x, int y) {
    objeDokusu = DokuYonetici::DokuYukle(textureSheet);
    frameWidth = objeDokusu.width / 6;
    frameHeight = objeDokusu.height / 2;
    hedefPozisyon = {(float)x, (float)y};
    kare = {0, 0, (float)frameWidth, (float)frameHeight};
}

Karakter::~Karakter() {
    UnloadTexture(objeDokusu);
}

void Karakter::HareketKontrol() {
    mevcutYon = Yon::HAREKETSIZ;
    
    if(IsKeyDown(KEY_W)) mevcutYon = Yon::ILERI;
    else if(IsKeyDown(KEY_S)) mevcutYon = Yon::GERI;
    if(IsKeyDown(KEY_D)) mevcutYon = Yon::SAGA;
    else if(IsKeyDown(KEY_A)) mevcutYon = Yon::SOLA;
}

void Karakter::AnimasyonuGuncelle() {
    switch(mevcutYon) {
        case Yon::GERI:
            kare.y = 0;
            currentFrame = currentFrame % 3;
            kare.x = currentFrame * frameWidth;
            break;
            
        case Yon::ILERI:
            kare.y = 0;
            currentFrame = 3 + (currentFrame % 3);
            kare.x = currentFrame * frameWidth;
            break;
            
        case Yon::SAGA:
            kare.y = frameHeight;
            currentFrame = currentFrame % 3;
            kare.x = currentFrame * frameWidth;
            break;
            
        case Yon::SOLA:
            kare.y = frameHeight;
            currentFrame = 3 + (currentFrame % 3);
            kare.x = currentFrame * frameWidth;
            break;
            
        case Yon::HAREKETSIZ:
            currentFrame = 0;
            framesCounter = 0;
            break;
    }
}

void Karakter::Guncelle() {
    HareketKontrol();
    if(mevcutYon != Yon::HAREKETSIZ) {
        framesCounter++;
        
        if(framesCounter >= (60/framesSpeed)) {
            framesCounter = 0;
            currentFrame++;
            AnimasyonuGuncelle();
        }

        switch(mevcutYon) {
            case Yon::ILERI: hedefPozisyon.y -= 2; break;
            case Yon::GERI: hedefPozisyon.y += 2; break;
            case Yon::SAGA: hedefPozisyon.x += 2; break;
            case Yon::SOLA: hedefPozisyon.x -= 2; break;
        }
    }
}

void Karakter::Ciz() {
    DokuYonetici::DokuCiz(objeDokusu, kare, hedefPozisyon);
}