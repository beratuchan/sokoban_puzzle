#include "Karakter.hpp"
#include "GirdiKontrolcu.hpp"

Karakter::Karakter(Vector2 cizim_pozisyonu) {
    this->cizimPozisyonu = cizim_pozisyonu;
    objeDokusu = DokuYonetici::DokuYukle("resources/adam.png");
    frameWidth = objeDokusu.width / 6;
    frameHeight = objeDokusu.height / 2;
    kare = {0, 0, (float)frameWidth, (float)frameHeight};
}
Karakter::~Karakter() {
    UnloadTexture(objeDokusu);
}

void Karakter::AnimasyonuGuncelle() {
    switch(GirdiKontrolcu::mevcutYon) {
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
    if(GirdiKontrolcu::mevcutYon != Yon::HAREKETSIZ) {
        framesCounter++;
        currentFrame = framesCounter;
        AnimasyonuGuncelle();
        switch(GirdiKontrolcu::mevcutYon) {
            case Yon::ILERI: cizimPozisyonu.y -= 64; break;
            case Yon::GERI: cizimPozisyonu.y += 64; break;
            case Yon::SAGA: cizimPozisyonu.x += 64; break;
            case Yon::SOLA: cizimPozisyonu.x -= 64; break;
            default: break;
        }
    }
}

void Karakter::Ciz() {
    DokuYonetici::DokuCiz(objeDokusu, kare, cizimPozisyonu);
}