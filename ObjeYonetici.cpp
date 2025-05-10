#include "ObjeYonetici.hpp"

ObjeYonetici::ObjeYonetici(){
    karakter = new Karakter({0,0});
    harita = new Harita(      
        {    
            {0,0,0,1,1,1,1,0,0},
            {0,0,1,1,0,0,1,0,0},
            {0,0,1,0,0,0,1,1,0},
            {0,0,1,0,0,0,0,1,0},
            {0,0,1,0,0,0,0,1,0},
            {0,0,1,1,0,0,1,1,0},
            {0,0,0,1,1,1,1,0,0},
        }
    );
    sandikStructlar = {{{{4*64, 4*64}, "yesil"},{{5*64, 2*64}, "mavi"}}};
    hedefStructlar = {{{{5*64, 3*64}, "yesil"},{{4*64, 3*64}, "mavi"}}};
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


