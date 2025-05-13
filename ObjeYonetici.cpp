#include "ObjeYonetici.hpp"

ObjeYonetici::ObjeYonetici(int seviyeNo){
    harita = new Harita(SEVIYELER[seviyeNo].harita);

    sandikStructlar = SEVIYELER[seviyeNo].sandiklar;
    hedefStructlar = SEVIYELER[seviyeNo].hedefler;

    kesisimKontrolcu = new KesisimKontrolcu(harita, &sandiklar, &hedefler);
    durumYonetici = new DurumYonetici();

    SandiklariDoldur();
    HedefleriDoldur();
    karakter = new Karakter(SEVIYELER[seviyeNo].karakter, kesisimKontrolcu, durumYonetici);

    ObjeleriDoldur();
    BaslangicDurumunuKaydet();
}

void ObjeYonetici::BaslangicDurumunuKaydet(){
    Durum baslangicDurumu;
    baslangicDurumu.karakterPozisyon = karakter->getCizimPozisyonu();
    for (const auto& sandik : sandiklar) {
        baslangicDurumu.sandikPozisyonlar.push_back(sandik.getPozisyon());
    }
    baslangicDurumu.hareketSayaci = 0;
    durumYonetici->Kaydet(baslangicDurumu); 
}

ObjeYonetici::~ObjeYonetici() {
    delete karakter;
    delete harita;
    delete kesisimKontrolcu;
    delete durumYonetici;
}

std::vector<Sandik>& ObjeYonetici::getSandiklar(){
    return sandiklar;
}

std::vector<Hedef>& ObjeYonetici::getHedefler(){
    return hedefler;
}

Karakter* ObjeYonetici::getKarakter(){
    return karakter;
}

Harita* ObjeYonetici::getHarita(){
    return harita;
}

void ObjeYonetici::SandiklariDoldur(){
    for(SandikStruct sandikStruct : sandikStructlar){
        sandiklar.emplace_back(sandikStruct.pozisyon, sandikStruct.renk, kesisimKontrolcu);
    }
}

void ObjeYonetici::HedefleriDoldur(){
    for(HedefStruct hedefStruct : hedefStructlar){
        hedefler.emplace_back(hedefStruct.pozisyon, hedefStruct.renk);
    }
}

void ObjeYonetici::ObjeleriDoldur(){
    objeler.push_back(harita);
    for(size_t i = 0; i < hedefler.size(); i++){
        objeler.push_back(&hedefler[i]);
    }    
    for(size_t i = 0; i < sandiklar.size(); i++){
        objeler.push_back(&sandiklar[i]);
    }
    objeler.push_back(karakter);
}

void ObjeYonetici::Dongu(){
    for (auto* obje : objeler) {
        obje->Guncelle();  
        obje->Ciz();      
    }
}