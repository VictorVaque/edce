#ifndef CERCADORAPEL_H
#define CERCADORAPEL_H

#include <string>
#include <vector>
#include "PasarellaPel.h"

class CercadoraPel {
public:
    // Constructor
    CercadoraPel();

    PasarellaPel cercaPel(const std::string& nomPelicula);
    std::vector<PasarellaPel> cercaRelacionadesPel(const std::string& nomFragment);

    // Nuevo m?todo para obtener todas las pel?culas
    std::vector<PasarellaPel> cercaTotesPel();
};

#endif // CERCADORAPEL_H