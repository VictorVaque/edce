#include "TxRegistraUsuari.h"

TxRegistraUsuari::TxRegistraUsuari(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixamentU, string modalitatU): nomU(nomU), sobrenomU(sobrenomU), contrasenyaU(contrasenyaU), correuElectronicU(correuElectronicU), dataNaiexementU(dataNaixamentU), modalitatSubscripcio(modalitatU) {}

void TxRegistraUsuari::executa() {

    PasarellaUsuari nouUsuari(nomU, sobrenomU, contrasenyaU, correuElectronicU, dataNaiexementU, modalitatSubscripcio);

    nouUsuari.insereix();
    
}
