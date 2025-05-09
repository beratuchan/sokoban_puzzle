#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void Guncelle() = 0;
    virtual void Ciz() = 0;
};

#endif