#include "Karakter.hpp"

Karakter::Karakter(Vector2 cizim_pozisyonu, KesisimKontrolcu* kesisimKontrolcu) {
    cizimPozisyonu = cizim_pozisyonu;
    m_kesisimKontrolcu = kesisimKontrolcu;
    objeDokusu = DokuYonetici::DokuYukle("resources/adam.png");
    frameWidth = objeDokusu.width / 6;
    frameHeight = objeDokusu.height / 2;
    kare = {0, 0, (float)frameWidth, (float)frameHeight};
}

Karakter::~Karakter() {
    UnloadTexture(objeDokusu);
}

void Karakter::Guncelle() {
    GirdiKontrolcu::HareketKontrol();
    if(GirdiKontrolcu::mevcutYon != Yon::HAREKETSIZ) {

        const Vector2 ileriHucre = IleriHucrePozisyonu(GirdiKontrolcu::mevcutYon, cizimPozisyonu);
        bool ilerisiBos = m_kesisimKontrolcu->HucreBos(ileriHucre);
        const Vector2 ikiIleriHucre = IleriHucrePozisyonu(GirdiKontrolcu::mevcutYon, ileriHucre);
        bool ikiIlerisiBos = m_kesisimKontrolcu->HucreBos(ikiIleriHucre);
        bool ilerisiSandik = m_kesisimKontrolcu->HucreSandik(ileriHucre);

        if(ilerisiBos || (ilerisiSandik && ikiIlerisiBos)){
            if(ilerisiSandik){
                Sandik *sandik = m_kesisimKontrolcu->HucredekiSandigiDondur(ileriHucre);
                sandik->HareketEttir(ikiIleriHucre);
            }
            cizimPozisyonu=ileriHucre;
        }
        
        AnimasyonuGuncelle();
    }
}

Vector2 Karakter::IleriHucrePozisyonu(Yon yon, const Vector2& baslangicPoz){
    Vector2 ileriPoz = baslangicPoz;
    switch(yon) {
        case Yon::YUKARI: ileriPoz.y -= 64; break;
        case Yon::ASAGI: ileriPoz.y += 64; break;
        case Yon::SAGA: ileriPoz.x += 64; break;
        case Yon::SOLA: ileriPoz.x -= 64; break;
        default: break;
    }
    return ileriPoz;
}

void Karakter::Ciz() {
    DokuYonetici::DokuCiz(objeDokusu, kare, cizimPozisyonu);
}

void Karakter::AnimasyonuGuncelle() {
    framesCounter++;
    currentFrame = framesCounter;
    switch(GirdiKontrolcu::mevcutYon) {
        case Yon::ASAGI:
            kare.y = 0;
            currentFrame = currentFrame % 3;
            kare.x = currentFrame * frameWidth;
            break;
            
        case Yon::YUKARI:
            kare.y = 0;
            currentFrame = 3 + (currentFrame % 3);
            kare.x = currentFrame * frameWidth;
            break;
            
        case Yon::SAGA:
            kare.y = frameHeight;
            currentFrame = currentFrame % 2;
            kare.x = currentFrame * frameWidth;
            break;
            
        case Yon::SOLA:
            kare.y = frameHeight;
            currentFrame = 3 + (currentFrame % 2);
            kare.x = currentFrame * frameWidth;
            break;
            
        case Yon::HAREKETSIZ:
            currentFrame = 0;
            framesCounter = 0;
            break;
    }
}