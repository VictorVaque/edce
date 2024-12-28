#ifndef CERCADORAVISUALITZACAPITOL_H
#define CERCADORAVISUALITZACAPITOL_H

#include <string>
#include <vector>
#include "PasarellaVisualitzaCapitol.h"

class CercadoraVisualitzaCapitol {
public:
    // Constructor
    CercadoraVisualitzaCapitol();

    // M?todos
    PasarellaVisualitzaCapitol cercaVisualitzaCapitol(const std::string& sobrenom, const std::string& nomSerie, int numTemporada, int numCapitol);

    // Nuevo m?todo: Obtener todas las visualizaciones de cap?tulos de un usuario
    std::vector<PasarellaVisualitzaCapitol> cercaTotsVisualitzaCapitols(const std::string& sobrenom);
};

#endif // CERCADORAVISUALITZACAPITOL_H