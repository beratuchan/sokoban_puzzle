#pragma once
#include <array>

enum class Yon {
    HAREKETSIZ,
    YUKARI,
    SAGA,
    ASAGI,
    SOLA,
};

static const std::array<Yon, 4> SaatYonundeYonler = {
    Yon::YUKARI,
    Yon::SAGA,
    Yon::ASAGI,
    Yon::SOLA,
};