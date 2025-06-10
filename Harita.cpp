#include "Harita.hpp"
#include "Seviyeler.hpp"

Harita::Harita(std::vector<std::vector<int>> harita){
    izgara = harita;
    satirSayisi = izgara.size();
    sutunSayisi = izgara[0].size();
    zemin = LoadTexture("resources/zemin.png");
    duvar = LoadTexture("resources/duvar.png");
    buz = LoadTexture("resources/buz.png");
    karadelik = LoadTexture("resources/karadelik.png");
    raylar = LoadTexture("resources/raylar.png");
}

Harita::~Harita(){
    UnloadTexture(zemin);
    UnloadTexture(duvar);
    UnloadTexture(buz);
    UnloadTexture(karadelik);
    UnloadTexture(raylar);
}

void Harita::setIzgara(std::vector<std::vector<int>> izgara){
    this->izgara = izgara;
}

void Harita::Ciz(){
    for(int i = 0; i < satirSayisi ; i++){
        for(int j = 0; j < sutunSayisi ; j++){
            if(izgara[i][j]==1){
                DrawTextureRec(duvar,Rectangle{0,0,64,64},{j*64.0f,i*64.0f},WHITE);
            }
            else if(izgara[i][j]==0) {
                DrawTextureRec(zemin,Rectangle{0,0,64,64},{j*64.0f,i*64.0f},WHITE);
            }
            else if(izgara[i][j]==2){
                DrawTextureRec(buz, Rectangle{0,0,64,64},{j*64.0f,i*64.0f},WHITE);  
            }
            else if(izgara[i][j]<6){
                DrawTextureRec(karadelik, Rectangle{float(izgara[i][j]%3)*64,0,64,64},{j*64.0f,i*64.0f},WHITE);
            }
            else{
                DrawTextureRec(raylar, Rectangle{float((izgara[i][j]-6)%10)*64,0,64,64},{j*64.0f,i*64.0f},WHITE);
            }
        }
    }
}

void Harita::FazGecisi(Vector2 hucre){
    float delta = GetFrameTime();
    gecenSure += delta;

    float alpha = gecenSure / gecisSuresi;
    
    if (alpha > 1.0f) alpha = 1.0f;
    Rectangle kare1 = Rectangle{4*64,0,64,64};
    Rectangle kare2 = Rectangle{5*64,0,64,64};

    // İlk frame (üstte) silikleşiyor
    Color renkA = {255, 255, 255, (unsigned char)(255 * (1.0f - alpha))};
    DrawTextureRec(karadelik, kare1, hucre, renkA);

    // İkinci frame (altta) belirginleşiyor
    Color renkB = {255, 255, 255, (unsigned char)(255 * alpha)};
    DrawTextureRec(karadelik, kare2, hucre, renkB);

};

void Harita::Guncelle(){
    
}
