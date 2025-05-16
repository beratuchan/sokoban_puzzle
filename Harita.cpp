#include "Harita.hpp"
#include "Seviyeler.hpp"

Harita::Harita(std::vector<std::vector<int>> harita){
    izgara = harita;
    satirSayisi = izgara.size();
    sutunSayisi = izgara[0].size();
    zemin = LoadTexture("resources/zemin.png");
    duvar = LoadTexture("resources/duvar.png");
    buz = LoadTexture("resources/buz.png");
}

Harita::~Harita(){
    UnloadTexture(zemin);
    UnloadTexture(duvar);
    UnloadTexture(buz);
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
            else{
                DrawTextureRec(buz, Rectangle{0,0,64,64},{j*64.0f,i*64.0f},WHITE);  
            }
        }
    }
}

void Harita::Guncelle(){
    
}
