#ifndef CERCADORAVISUALITZAPEL_H
#define CERCADORAVISUALITZAPEL_H

#include <string>
#include <vector>
#include "PasarellaVisualitzaPel.h"

class CercadoraVisualitzaPel {
public:
    // Constructor
    CercadoraVisualitzaPel();

    // Métodos
    PasarellaVisualitzaPel cercaVisualitzaPel(const std::string& sobrenom, const std::string& nomPelicula);

    std::vector<PasarellaVisualitzaPel> cercaTotesVisualitzacionsPel(const std::string& sobrenom);
};

#endif // CERCADORAVISUALITZAPEL_H