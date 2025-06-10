#include "ObjeYonetici.hpp"
#include "iostream"

ObjeYonetici::ObjeYonetici(int seviyeNo){
    this->seviyeNo = seviyeNo;
    this->sandikSayisi = sandikStructlar.size();
    this->harita = new Harita(SEVIYELER[seviyeNo].harita);
    this->kesisimKontrolcu = new KesisimKontrolcu(this);
    this->durumYonetici = new DurumYonetici(this);
   

    sandikStructlar = SEVIYELER[seviyeNo].sandiklar;
    hedefStructlar = SEVIYELER[seviyeNo].hedefler;
    kapanStructlar = SEVIYELER[seviyeNo].kapanlar;
    portalStructlar = SEVIYELER[seviyeNo].portallar;
    karakterStructlar = SEVIYELER[seviyeNo].karakterler;

    HedefleriDoldur();
    KapanlariDoldur();
    PortallariDoldur();
    SandiklariDoldur();
    KarakterleriDoldur();
    ObjeleriDoldur();

    BaslangicDurumunuKaydet();
}
void ObjeYonetici::KarakterDegistir(){
    if(karakterler[0]->getAktifMi()){
        karakterler[0]->setAktifMi(false);
        karakterler[1]->setAktifMi(true);
    }
    else{
        karakterler[0]->setAktifMi(true);
        karakterler[1]->setAktifMi(false);
    }
};
void ObjeYonetici::YeniKarakterOlustur(Vector2 pozisyon){
    bool aktifMi = !karakterler[0]->getAktifMi();
    int karakterNo = (karakterler[0]==0) ? 1:0;
    Karakter* karakter = new Karakter(SEVIYELER[seviyeNo].karakterler[0], aktifMi, karakterNo, this, durumYonetici);
    objeler.push_back(karakter);
}
void ObjeYonetici::YeniSandikOlustur(SandikStruct sandikstruct){
    Sandik* sandik = new Sandik(sandikstruct.pozisyon, sandikstruct.renk, kesisimKontrolcu);
    sandiklar.push_back(sandik);
    objeler.push_back(sandik);
}

void ObjeYonetici::BaslangicDurumunuKaydet(){
    Durum baslangicDurumu;
    for (const auto& karakter : karakterler) {
        KarakterStruct karakterStruct;
        karakterStruct.pozisyon = karakter->getCizimPozisyonu();
        karakterStruct.AktifMi = karakter->getAktifMi();
        karakterStruct.karakterNo = karakter->getKarakterNo();
        baslangicDurumu.karakterStructlar.push_back(karakterStruct);
    }
    for (const auto& sandik : sandiklar) {
        SandikStruct sandikstruct;
        sandikstruct.pozisyon = sandik->getPozisyon();
        sandikstruct.renk = sandik->getRenk();
        baslangicDurumu.sandikStructlar.push_back(sandikstruct);
    }
    baslangicDurumu.hareketSayaci = 0;
    durumYonetici->Kaydet(baslangicDurumu); 
}

ObjeYonetici::~ObjeYonetici() {
    delete harita;
    delete kesisimKontrolcu;
    delete durumYonetici;
}

void ObjeYonetici::SandiklariDoldur(){
    for(SandikStruct sandikStruct : sandikStructlar){
        Sandik* sandik = new Sandik(sandikStruct.pozisyon, sandikStruct.renk, kesisimKontrolcu);
        sandiklar.push_back(sandik);
    }
}

void ObjeYonetici::KarakterleriDoldur(){
    for(size_t i = 0; i < karakterStructlar.size(); i++){
        bool aktifMi = (i==0);
        Karakter* karakter = new Karakter(karakterStructlar[i], aktifMi, i, this, durumYonetici);
        karakterler.push_back(karakter);
    }
}

void ObjeYonetici::HedefleriDoldur(){
    for(HedefStruct hedefStruct : hedefStructlar){
        hedefler.emplace_back(hedefStruct.pozisyon, hedefStruct.renk, kesisimKontrolcu);
    }
}

void ObjeYonetici::KapanlariDoldur(){
    for(KapanStruct kapanStruct : kapanStructlar){
        kapanlar.emplace_back(kapanStruct.kapanpozisyon, kapanStruct.anahtarpozisyonlari, kapanStruct.acikMi, kapanStruct.renk,kesisimKontrolcu);
    }
}

void ObjeYonetici::PortallariDoldur(){
    for(PortalStruct portalStruct : portalStructlar){
        portallar.emplace_back(portalStruct.portalPozisyonlari, portalStruct.renk, kesisimKontrolcu);
    }
}

void ObjeYonetici::ObjeleriDoldur(){
    objeler.push_back(harita);
    for(size_t i = 0; i < hedefler.size(); i++){
        objeler.push_back(&hedefler[i]);
    }    
    for(size_t i = 0; i < kapanlar.size(); i++){
        objeler.push_back(&kapanlar[i]);
    }   
    for(size_t i = 0; i < sandiklar.size(); i++){
        objeler.push_back(sandiklar[i]);
    } 
    for(size_t i = 0; i < portallar.size(); i++){
        objeler.push_back(&portallar[i]);
    } 
    for(size_t i = 0; i < karakterler.size(); i++){
        objeler.push_back(karakterler[i]);
    } 
}

void ObjeYonetici::Dongu(){
    for (auto it = objeler.begin(); it != objeler.end();){
        GameObject* obje = *it;
        if(obje->getSilinmeliMi()){
            for(auto sandikIt = sandiklar.begin(); sandikIt!=sandiklar.end();++sandikIt){
                 if (*sandikIt == obje) {
                    durumYonetici->setSandikSilindiMi(true);
                    sandiklar.erase(sandikIt);
                    break;
                 }
            }
            delete obje;
            it = objeler.erase(it);

            for(auto karakterIt = karakterler.begin(); karakterIt!=karakterler.end();++karakterIt){
                 if (*karakterIt == obje) {
                    durumYonetici->setKarakterSilindiMi(true);
                    karakterler.erase(karakterIt);
                    break;
                 }
            }
        }
        else{
            obje -> Guncelle();
            obje -> Ciz();
            it++;
        }
    }
}