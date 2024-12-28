#ifndef CERCADORACAPITOL_H
#define CERCADORACAPITOL_H

#include <string>
#include "PasarellaCapitol.h"

class CercadoraCapitol {
public:
    // Constructor
    CercadoraCapitol();

    PasarellaCapitol cercaCapitol(const std::string& nomSerie, int numTemporada, int numCapitol);
};

#endif // CERCADORACAPITOL_H