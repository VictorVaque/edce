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

    // Obtenim les visualitzacions de pel�l�cules
    CercadoraVisualitzaPel cercadorPel;
    try {
        visualitzacionsPel�l�cules = cercadorPel.cercaTotesVisualitzacionsPel(sobrenomUsuari);
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al obtenir visualitzacions de pel�l�cules: " + std::string(e.what()));
    }

    // Obtenim les visualitzacions de cap�tols
    CercadoraVisualitzaCapitol cercador;
    try {
        visualitzacionsCap�tols = cercador.cercaTotsVisualitzaCapitols(sobrenomUsuari);
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al obtenir visualitzacions de cap�tols: " + std::string(e.what()));
    }
}

const std::vector<PasarellaVisualitzaPel>& TxConsultarVisualitzacions::getVisualitzacionsPel�l�cules() const {
    return visualitzacionsPel�l�cules;
}

const std::vector<PasarellaVisualitzaCapitol>& TxConsultarVisualitzacions::getVisualitzacionsCap�tols() const {
    return visualitzacionsCap�tols;
}
