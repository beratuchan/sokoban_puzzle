#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP
#include "raylib.h"

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void Guncelle() = 0;
    virtual void Ciz() = 0;
    virtual bool getSilinmeliMi() = 0;
};

#endif