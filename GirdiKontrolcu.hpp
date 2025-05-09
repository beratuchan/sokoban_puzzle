enum class Yon{
        HAREKETSIZ,
        SAGA,
        SOLA,
        ILERI,
        GERI
};

class GirdiKontrolcu{
    public:
        GirdiKontrolcu();
        static void HareketKontrol();
        static Yon mevcutYon;
        static int hareketSayaci;

};