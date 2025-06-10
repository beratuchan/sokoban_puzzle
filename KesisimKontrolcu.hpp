#ifndef KESISIM_KONTROLCU_HPP
#define KESISIM_KONTROLCU_HPP

#include <vector>
#include <raylib.h>
#include "GameObject.hpp"
#include "Sandik.hpp"
#include "Hedef.hpp"
#include "Harita.hpp"
#include "Portal.hpp"

class ObjeYonetici;
class Sandik;
class Portal;

class KesisimKontrolcu{
    public:
        KesisimKontrolcu(ObjeYonetici* objeYonetici);

        bool HucreSandik(Vector2 hucre) const;
        bool HucreHedef(Vector2 hucre) const;
        bool HucreDuvar(Vector2 hucre) const;
        bool HucreBos(Vector2 hucre) const;
        bool HucreBuz(Vector2 hucre);
        int HucreKaraDelik(Vector2 hucre) const;
        int HucreRay(Vector2 hucre) const;
        bool HucreKarakter(Vector2 hucre) const;
        bool HucrePortal(Vector2 hucre) const;

        bool HucreKapaliKapan(Vector2 hucre) const;
        Sandik* HucredekiSandigiDondur(Vector2 hucre) const;
        Hedef* HucredekiHedefiDondur(Vector2 hucre) const;
        Portal* HucredekiPortaliDondur(Vector2 hucre) const;
        void HucreyiSonrakiFazaGecir(Vector2 hucre);

    private:
        ObjeYonetici* objeYonetici;
};
#endif 