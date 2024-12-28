#ifndef CERCADORAVISUALITZASERIE_H
#define CERCADORAVISUALITZASERIE_H

#include <string>
#include "PasarellaVisualitzaSerie.h"

class CercadoraVisualitzaSerie {
public:
    // Constructor
    CercadoraVisualitzaSerie();

    // M�todos
    PasarellaVisualitzaSerie cercaVisualitzaSerie(const std::string& sobrenom, const std::string& nomSerie);
};

#endif // CERCADORAVISUALITZASERIE_H