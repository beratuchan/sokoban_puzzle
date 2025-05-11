#ifndef KESISIM_KONTROLCU_HPP
#define KESISIM_KONTROLCU_HPP

#include <vector>
#include <raylib.h>
#include "GameObject.hpp"
#include "Sandik.hpp"
#include "Hedef.hpp"
#include "Harita.hpp"

class KesisimKontrolcu{
    public:
        KesisimKontrolcu(Harita* harita, std::vector<Sandik>* sandiklar, std::vector<Hedef>* hedefler);

        bool HucreSandik(Vector2 hucre) const;
        bool HucreHedef(Vector2 hucre) const;
        bool HucreDuvar(Vector2 hucre) const;
        bool HucreBos(Vector2 hucre) const;
        Sandik* HucredekiSandigiDondur(Vector2 hucre) const;

        
    private:
        Harita* m_harita;
        std::vector<Sandik>* m_sandiklar;
        std::vector<Hedef>* m_hedefler;
};
#endif 