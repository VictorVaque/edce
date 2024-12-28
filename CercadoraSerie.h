#ifndef CERCADORASERIE_H
#define CERCADORASERIE_H

#include <string>
#include <vector>
#include "PasarellaSerie.h"

class CercadoraSerie {
public:
    // Constructor
    CercadoraSerie();

    PasarellaSerie cercaSerie(const std::string& nomSerie);

    // Nuevo m?todo para obtener todas las series
    std::vector<PasarellaSerie> cercaTotesSeries();
};

#endif // CERCADORASERIE_H