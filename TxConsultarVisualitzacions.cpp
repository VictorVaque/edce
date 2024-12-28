#include "TxConsultarVisualitzacions.h"
#include "CercadoraVisualitzaPel.h"
#include "CercadoraVisualitzaSerie.h"
#include <stdexcept>

TxConsultarVisualitzacions::TxConsultarVisualitzacions() {}

TxConsultarVisualitzacions::~TxConsultarVisualitzacions() {}

void TxConsultarVisualitzacions::executar(const std::string& sobrenomUsuari) {
    if (sobrenomUsuari.empty()) {
        throw std::runtime_error("El sobrenom de l'usuari no pot estar buit.");
    }

    // Obtenim les visualitzacions de pel·lícules
    CercadoraVisualitzaPel cercadorPel;
    try {
        visualitzacionsPel·lícules = cercadorPel.cercaTotesVisualitzacionsPel(sobrenomUsuari);
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al obtenir visualitzacions de pel·lícules: " + std::string(e.what()));
    }

    // Obtenim les visualitzacions de capítols
    CercadoraVisualitzaCapitol cercador;
    try {
        visualitzacionsCapítols = cercador.cercaTotsVisualitzaCapitols(sobrenomUsuari);
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al obtenir visualitzacions de capítols: " + std::string(e.what()));
    }
}

const std::vector<PasarellaVisualitzaPel>& TxConsultarVisualitzacions::getVisualitzacionsPel·lícules() const {
    return visualitzacionsPel·lícules;
}

const std::vector<PasarellaVisualitzaCapitol>& TxConsultarVisualitzacions::getVisualitzacionsCapítols() const {
    return visualitzacionsCapítols;
}
