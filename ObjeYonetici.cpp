#include "ObjeYonetici.hpp"

ObjeYonetici::ObjeYonetici(int seviyeNo){
    karakter = new Karakter(SEVIYELER[seviyeNo].karakter);
    harita = new Harita(SEVIYELER[seviyeNo].harita);
    sandikStructlar = SEVIYELER[seviyeNo].sandiklar;
    hedefStructlar = SEVIYELER[seviyeNo].hedefler;
    SandiklariDoldur();
    HedefleriDoldur();
    ObjeleriDoldur();
}

ObjeYonetici::~ObjeYonetici() {
    delete karakter;
    delete harita;
}

void ObjeYonetici::SandiklariDoldur(){
    for(SandikStruct sandikStruct : sandikStructlar){
        sandiklar.emplace_back(sandikStruct.pozisyon,sandikStruct.renk);
    }
}

void ObjeYonetici::HedefleriDoldur(){
    for(HedefStruct hedefStruct : hedefStructlar){
        hedefler.emplace_back(hedefStruct.pozisyon,hedefStruct.renk);
    }
}

void ObjeYonetici::ObjeleriDoldur(){
    objeler.push_back(harita);
    for(auto& sandik : sandiklar){
        objeler.push_back(&sandik);
    }
    for(auto& hedef : hedefler){
        objeler.push_back(&hedef);
    }
    objeler.push_back(karakter);
}

void ObjeYonetici::Dongu(){
    for (auto* obje : objeler) {
        obje->Guncelle();  
        obje->Ciz();      
    }
}


