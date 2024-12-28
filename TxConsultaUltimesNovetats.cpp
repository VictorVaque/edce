#include "TxConsultaUltimesNovetats.h"
#include <algorithm>
#include <stdexcept>

// Constructor
TxConsultaUltimesNovetats::TxConsultaUltimesNovetats(std::string mod) : modalitat(mod) {}

// Destructor
TxConsultaUltimesNovetats::~TxConsultaUltimesNovetats() {}

// Método para buscar las últimas novedades
void TxConsultaUltimesNovetats::cercarUltimesNovetats() {
    PetitFlix& pf = PetitFlix::getInstance();
    std::string dataActual = pf.obtenirDataActual();

    // Buscar películas
    CercadoraPel auxp;
    std::vector<PasarellaPel> totespelis = auxp.cercaTotesPel();
    for (const auto& pel : totespelis) {
        if (pel.obteDataEstrena() < dataActual && pel.obteMod() == modalitat) {
            pelicules.push_back(pel);
        }
    }

    // Ordenar y limitar a las 5 películas más recientes
    std::sort(pelicules.begin(), pelicules.end(), [](const PasarellaPel& a, const PasarellaPel& b) {
        return a.obteDataEstrena() > b.obteDataEstrena();
        });
    if (pelicules.size() > 5) {
        pelicules.resize(5);
    }

    // Buscar series
    CercadoraSerie auxs;
    std::vector<PasarellaSerie> totesseries = auxs.cercaTotesSeries();
    for (const auto& serie : totesseries) {
        int numTemp = serie.obteNumTemp();
        int numCap = serie.obteNumCap(numTemp);
        CercadoraCapitol auxc;
        PasarellaCapitol cap = auxc.cercaCapitol(serie.obteNom(), numTemp, numCap);
        if (cap.obteDataEstrena() < dataActual && serie.obteMod() == modalitat) {
            series.push_back(serie);
        }
    }

    // Ordenar y limitar a las 5 series más recientes
    std::sort(series.begin(), series.end(), [](const PasarellaSerie& a, const PasarellaSerie& b) {
        int numTempA = a.obteNumTemp();
        int numCapA = a.obteNumCap(numTempA);
        int numTempB = b.obteNumTemp();
        int numCapB = b.obteNumCap(numTempB);
        CercadoraCapitol auxc;
        PasarellaCapitol capA = auxc.cercaCapitol(a.obteNom(), numTempA, numCapA);
        PasarellaCapitol capB = auxc.cercaCapitol(b.obteNom(), numTempB, numCapB);
        return capA.obteDataEstrena() > capB.obteDataEstrena();
        });
    if (series.size() > 5) {
        series.resize(5);
    }
}

// Método para consultar las últimas novedades
std::string TxConsultaUltimesNovetats::consultaUltimesNovetats() {
    cercarUltimesNovetats();

    std::string novetats = "** Novetats **\n Modalitat: " + modalitat + "\n\n";

    // Añadir novedades de películas
    novetats += "** Novetats Pel·lícules ** \n ****************\n";
    for (size_t i = 0; i < pelicules.size(); ++i) {
        novetats += std::to_string(i + 1) + ".- ";
        novetats += pelicules[i].obteDataEstrena() + ": " + pelicules[i].obteNom() + "; ";
        novetats += pelicules[i].obteQualificacio() + "; " + std::to_string(pelicules[i].obteDuracio()) + " min.\n";
    }

    // Añadir novedades de series
    novetats += "** Novetats Sèries ** \n ****************\n";
    for (size_t i = 0; i < series.size(); ++i) {
        int numTemp = series[i].obteNumTemp();
        int numCap = series[i].obteNumCap(numTemp);
        CercadoraCapitol auxc;
        PasarellaCapitol cap = auxc.cercaCapitol(series[i].obteNom(), numTemp, numCap);

        novetats += std::to_string(i + 1) + ".- ";
        novetats += cap.obteDataEstrena() + ": " + series[i].obteNom() + "; ";
        novetats += series[i].obteQualificacio() + "; Temporada " + std::to_string(numTemp) + "; Capítol " + std::to_string(numCap) + "; ";
        novetats += std::to_string(cap.obteDuracio()) + " min.\n";
    }

    return novetats;
}