#ifndef KESISIM_KONTROLCU_HPP
#define KESISIM_KONTROLCU_HPP

#include <vector>
#include <raylib.h>
#include "GameObject.hpp"
#include "Sandik.hpp"
#include "Hedef.hpp"
#include "Harita.hpp"

class ObjeYonetici;
class Sandik;

class KesisimKontrolcu{
    public:
        KesisimKontrolcu(ObjeYonetici* objeYonetici);

        bool HucreSandik(Vector2 hucre) const;
        bool HucreHedef(Vector2 hucre) const;
        bool HucreDuvar(Vector2 hucre) const;
        bool HucreBos(Vector2 hucre) const;
        bool HucreBuz(Vector2 hucre);
        bool HucreKarakter(Vector2 hucre) const;

        bool HucreKapaliKapan(Vector2 hucre) const;
        Sandik* HucredekiSandigiDondur(Vector2 hucre) const;
        Hedef* HucredekiHedefiDondur(Vector2 hucre) const;
    private:
        ObjeYonetici* objeYonetici;
};
#endif 