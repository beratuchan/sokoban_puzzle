#include "raylib.h"
#include "GirdiKontrolcu.hpp"

Yon GirdiKontrolcu::mevcutYon = Yon::HAREKETSIZ;
int GirdiKontrolcu::hareketSayaci = 0;

void GirdiKontrolcu::HareketKontrol(ObjeYonetici* objeYonetici, SeviyeSistemi& seviyeSistemi){
    mevcutYon = Yon::HAREKETSIZ;
    if(IsKeyPressed(KEY_W)||IsKeyPressed(KEY_UP)) mevcutYon = Yon::YUKARI;
    else if(IsKeyPressed(KEY_S)||IsKeyPressed(KEY_DOWN)) mevcutYon = Yon::ASAGI;
    else if(IsKeyPressed(KEY_D)||IsKeyPressed(KEY_RIGHT)) mevcutYon = Yon::SAGA;
    else if(IsKeyPressed(KEY_A)||IsKeyPressed(KEY_LEFT)) mevcutYon = Yon::SOLA;
    else if (IsKeyPressed(KEY_G)) GeriAl(objeYonetici);
    else if(seviyeSistemi.getObjeYonetici()->getKarakterler().size()>1&&IsKeyPressed(KEY_E)){seviyeSistemi.getObjeYonetici()->KarakterDegistir();}
    else if(IsKeyPressed(KEY_T)){seviyeSistemi.Baslat();}
    else if(IsKeyPressed(KEY_TAB)){CizimKontrol(seviyeSistemi);}
}

void GirdiKontrolcu::CizimKontrol(SeviyeSistemi& seviyeSistemi){
    std::vector<Karakter*> karakterler = seviyeSistemi.getObjeYonetici()->getKarakterler();
    std::vector<Sandik*> sandiklar = seviyeSistemi.getObjeYonetici()->getSandiklar();
    for(auto& sandik: sandiklar){
        sandik->setCizilmeliMi(!sandik->getCizilmeliMi());
    }
    for(auto& karakter: karakterler){
        karakter->setCizilmeliMi(!karakter->getCizilmeliMi());
    }
}

void GirdiKontrolcu::GeriAl(ObjeYonetici* objeYonetici){
    if (!objeYonetici) return;
    
    DurumYonetici* durumYonetici = objeYonetici->getDurumYonetici();
    if (!durumYonetici || !durumYonetici->GeriAlinabilir()) return;

    Durum oncekiDurum = durumYonetici->GeriAl(); 

    objeYonetici->getHarita()->setIzgara(oncekiDurum.haritaIzgara);
    
    auto& karakterler = objeYonetici->getKarakterler();
    if(objeYonetici->getDurumYonetici()->getKarakterSilindiMi()){
        objeYonetici->YeniKarakterOlustur(oncekiDurum.karakterStructlar.back().pozisyon);
        objeYonetici->getDurumYonetici()->setKarakterSilindiMi(false);
    }
    if (oncekiDurum.karakterStructlar.size() == karakterler.size()) {
        for (size_t i = 0; i < karakterler.size(); ++i) {
            karakterler[i]->PozisyonAta(oncekiDurum.karakterStructlar[i].pozisyon);
            karakterler[i]->setAktifMi(oncekiDurum.karakterStructlar[i].AktifMi);
            karakterler[i]->setKarakterNo(oncekiDurum.karakterStructlar[i].karakterNo);
        }
    }
    
    
    
    auto& sandiklar = objeYonetici->getSandiklar();
    if(objeYonetici->getDurumYonetici()->getSandikSilindiMi()){
        objeYonetici->YeniSandikOlustur(oncekiDurum.sandikStructlar.back());
    }
    if (oncekiDurum.sandikStructlar.size() == sandiklar.size()) {
        for (size_t i = 0; i < sandiklar.size(); ++i) {
            sandiklar[i]->setPozisyon(oncekiDurum.sandikStructlar[i].pozisyon);
            sandiklar[i]->setRenk(oncekiDurum.sandikStructlar[i].renk);
        }
    }
    
    hareketSayaci = oncekiDurum.hareketSayaci;
}