#ifndef TXCONSULTARUSUARI_H
#define TXCONSULTARUSUARI_H

#include <string>
#include "DTOUsuari.h"
#include "PasarellaUsuari.h"
#include "PetitFlix.h"

class TxConsultaUsuari {
private:
    DTOUsuari _resultat; // Datos del usuario consultado
    PasarellaUsuari _usuari; // Pasarela para acceder al usuario

public:

    TxConsultaUsuari();
    ~TxConsultaUsuari();

    void executar();
    DTOUsuari obteResultat();
    PasarellaUsuari obteUsuari();
};

#endif // TXCONSULTARUSUARI_H

