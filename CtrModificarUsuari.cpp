#include "CtrModificarUsuari.h"

DTOUsuari CtrModificaUsuari::consultaUsuari() {
    TxConsultaUsuari aux;
    aux.executar();
    DTOUsuari sol = aux.obteResultat();
    _usuari = aux.obteUsuari();
    return sol;
}

void CtrModificaUsuari::modificaUsuari(std::string nomU, std::string contraU, std::string correuU, std::string neixU) {
    bool haModificat = false;

    if (!nomU.empty()) {
        _usuari.posaNom(nomU);
        haModificat = true;
    }
    if (!contraU.empty()) {
        _usuari.posaContrasenya(contraU);
        haModificat = true;
    }
    if (!correuU.empty()) {
        _usuari.posaCorreuElectronic(correuU);
        haModificat = true;
    }
    if (!neixU.empty()) {
        _usuari.posaDataNaixement(neixU);
        haModificat = true;
    }

    if (haModificat) {
        try {
            _usuari.modifica();
            PetitFlix& p = PetitFlix::getInstance();
            p.iniciar_sessio(_usuari);
        }
        catch (const std::exception& e) {
            throw std::runtime_error("Error al modificar l'usuari: " + std::string(e.what()));
        }
    }
}