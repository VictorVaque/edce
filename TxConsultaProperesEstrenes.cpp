#include "TxConsultaProperesEstrenes.h"

TxConsultarProperesEstrenes::TxConsultarProperesEstrenes(string mod) {
    modalitat = mod;
}

TxConsultarProperesEstrenes::~TxConsultarProperesEstrenes() {}

void TxConsultarProperesEstrenes::cercaSeriesiPelicules() {
    PetitFlix& p = PetitFlix::getInstance();
    string dataActual = p.obtenirDataActual();

    vector<PasarellaPel> totespelis;
    CercadoraPel auxp;
    totespelis = auxp.cercaTotesPel();

    for (int i = 0; i < totespelis.size(); ++i) {
        if (totespelis[i].obteDataEstrena() > dataActual && totespelis[i].obteMod() == modalitat) {
            pelicules.push_back(totespelis[i]);
        }
    }

    vector<PasarellaSerie> totesseries;
    CercadoraSerie auxs;
    totesseries = auxs.cercaTotesSeries();
    CercadoraCapitol aux2;

    for (int i = 0; i < totesseries.size(); ++i) {
        PasarellaSerie s = totesseries[i];
        int numTemp = s.obteNumTemp();
        int numCap = s.obteNumCap(numTemp);
        string nom = s.obteNom();
        PasarellaCapitol c = aux2.cercaCapitol(nom ,numTemp, numCap);
        if (c.obteDataEstrena() > dataActual && s.obteMod() == modalitat) {
            series.push_back(s);
        }
    }
}

string TxConsultarProperesEstrenes::consultarProximasEstrenas() {
    cercaSeriesiPelicules();

    string estrenes = "** Properes estrenes **\n Modalitat: " + modalitat + "\n\n";
    int i = 0, j = 0, cont = 1;

    while (i < pelicules.size() && j < series.size()) {
        if (pelicules[i].obteDataEstrena() < series[j].obteData()) {
            estrenes += to_string(cont) + ".- " + pelicules[i].obteDataEstrena() + ": [Pel·lícula]: " +
                pelicules[i].obteNom() + "; " +
                pelicules[i].obteQualificacio() + "; " +
                to_string(pelicules[i].obteDuracio()) + ".\n";
            ++i;
        }
        else {
            estrenes += to_string(cont) + ".- " + series[j].obteData() + ": [Sèrie]: " +
                series[j].obteNom() + "; " +
                series[j].obteQualificacio() + "; " +
                to_string(series[j].obteNumTemp()) + ".\n";
            ++j;
        }
        ++cont;
    }

    while (i < pelicules.size()) {
        estrenes += to_string(cont) + ".- " + pelicules[i].obteDataEstrena() + ": [Pel·lícula]: " +
            pelicules[i].obteNom() + "; " +
            pelicules[i].obteQualificacio() + "; " +
            to_string(pelicules[i].obteDuracio()) + ".\n";
        ++i;
        ++cont;
    }

    while (j < series.size()) {
        estrenes += to_string(cont) + ".- " + series[j].obteData() + ": [Sèrie]: " +
            series[j].obteNom() + "; " +
            series[j].obteQualificacio() + "; " +
            to_string(series[j].obteNumTemp()) + ".\n";
        ++j;
        ++cont;
    }

    return estrenes;
}