#include "Harita.hpp"
#include "Seviyeler.hpp"

Harita::Harita(){
    harita = temsiliHarita;
    satirSayisi = temsiliHarita.size();
    sutunSayisi = temsiliHarita[0].size();
    zemin = LoadTexture("resources/zemin.png");
    duvar = LoadTexture("resources/duvar.png");
}

Harita::~Harita(){
    UnloadTexture(zemin);
    UnloadTexture(duvar);
}

void Harita::Ciz(){
    for(int i = 0; i < satirSayisi ; i++){
        for(int j = 0; j < sutunSayisi ; j++){
            if(harita[i][j]==1){
                DrawTextureRec(duvar,Rectangle{0,0,64,64},{j*64.0f,i*64.0f},WHITE);
            }
            else {
                DrawTextureRec(zemin,Rectangle{0,0,64,64},{j*64.0f,i*64.0f},WHITE);
            }
        }
    }
}
