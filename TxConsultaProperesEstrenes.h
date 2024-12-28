#include "PetitFlix.h"
#include "PasarellaSerie.h"
#include "CercadoraSerie.h"
#include "PasarellaCapitol.h"
#include "PasarellaPel.h"
#include "CercadoraPel.h"
#include "CercadoraCapitol.h"
#include <vector>

class TxConsultarProperesEstrenes {
private:
    string modalitat;
    vector<PasarellaSerie> series;
    vector<PasarellaPel> pelicules;

    void cercaSeriesiPelicules();

public:
    TxConsultarProperesEstrenes(string);
    ~TxConsultarProperesEstrenes();

    string consultarProximasEstrenas();
};