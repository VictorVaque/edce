#include "TxVisualitzarCapitol.h"

TxVisualitzarCapitol::TxVisualitzarCapitol() {}

TxVisualitzarCapitol::TxVisualitzarCapitol(string& nSerie, int nTemporada)
    : nomSerie(nSerie), numTempEscollida(nTemporada), numCapEscollit(0) {

    CercadoraSerie aux;
    CercadoraCapitol aux2;
    PasarellaSerie serie = aux.cercaSerie(nSerie);
    numTemporades = serie.obteNumTemp();
    numCapitols = serie.obteNumCap(numTempEscollida);

    for (int i = 0; i < numCapitols; ++i) {
        capitols.push_back(aux2.cercaCapitol(nSerie, numTempEscollida, i + 1));
    }
}

TxVisualitzarCapitol::~TxVisualitzarCapitol() {}

void TxVisualitzarCapitol::EscollirCap(int nCap) {
    numCapEscollit = nCap;
}

void TxVisualitzarCapitol::executar() {
    PetitFlix& p = PetitFlix::getInstance();
    CercadoraVisualitzaSerie aux;
    CercadoraVisualitzaCapitol aux2;
    PasarellaUsuari usu = p.obteUsuari();
    std::string sobrenom = usu.obteSobrenom();

    try {
        PasarellaVisualitzaSerie vserie = aux.cercaVisualitzaSerie(sobrenom, nomSerie);
        try {
            PasarellaVisualitzaCapitol vcapitol = aux2.cercaVisualitzaCapitol(sobrenom, nomSerie, numTempEscollida, numCapEscollit);
            vcapitol.aumentarNumVis();
        }
        catch (const std::runtime_error&) {
            PasarellaVisualitzaCapitol vcapitol(sobrenom, nomSerie, 1, numTempEscollida, numCapEscollit, p.obtenirDataActual());
            vcapitol.insereix();
        }
        vserie.aumentarNumVis();
    }
    catch (const std::runtime_error&) {
        PasarellaVisualitzaSerie vserie(sobrenom, nomSerie, p.obtenirDataActual(), 1);
        vserie.insereix();
        PasarellaVisualitzaCapitol vcapitol(sobrenom, nomSerie, 1, numTempEscollida, numCapEscollit, p.obtenirDataActual());
        vcapitol.insereix();
    }
}

string TxVisualitzarCapitol::getNomSerie() const {
    return nomSerie;
}

int TxVisualitzarCapitol::getNumTemporada() const {
    return numTempEscollida;
}

int TxVisualitzarCapitol::getNumCapitols() const {
    return numCapitols;
}

vector<PasarellaCapitol> TxVisualitzarCapitol::getCapitols() const {
    return capitols;
}

