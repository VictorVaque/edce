#include "TxConsultarPeliculesMesVistes.h"
#include "PetitFlix.h"
#include "CercadoraVisualitzaPel.h"
#include <stdexcept>
#include <algorithm> // Para usar sort
using namespace std;

TxConsultarPeliculesMesVistes::TxConsultarPeliculesMesVistes() {}

TxConsultarPeliculesMesVistes::~TxConsultarPeliculesMesVistes() {}

void TxConsultarPeliculesMesVistes::cerca_pelicules() {
    CercadoraPel aux;
    vector<PasarellaPel> totesPelis = aux.cercaTotesPel();

    // Ordenar las películas por visualizaciones (y por fecha si son iguales)
    std::sort(totesPelis.begin(), totesPelis.end(), [](const PasarellaPel& a, const PasarellaPel& b) {
        if (a.obteNumVisualitzacions() != b.obteNumVisualitzacions()) {
            return a.obteNumVisualitzacions() > b.obteNumVisualitzacions();
        }
        });
    // Tomar las 5 primeras películas más vistas
    int limit = std::min(5, static_cast<int>(totesPelis.size()));
    pelicules.assign(totesPelis.begin(), totesPelis.begin() + limit);
}

string TxConsultarPeliculesMesVistes::consultarPeliculesMesVistes() {
    this->cerca_pelicules();

    string pelMesVistes = "** Pel·lícules més visualitzades **\n\n";
    PetitFlix& p = PetitFlix::getInstance();

    for (int i = 0; i < pelicules.size(); ++i) {
        PasarellaPel pel = pelicules[i];
        pelMesVistes += to_string(i + 1) + ".- ";
        pelMesVistes += pel.obteNom() + "; " + pel.obteQualificacio() + "; ";
        pelMesVistes += to_string(pel.obteDuracio()) + "; ";
        pelMesVistes += "Visualitzacions: " + to_string(pel.obteNumVisualitzacions());

        if (p.hiHaUsuariLoggejat()) {
            PasarellaUsuari u = p.obteUsuari();
            CercadoraVisualitzaPel auxv;
            try {
                auto vp = auxv.cercaVisualitzaPel(u.obteSobrenom(), pel.obteNom());
                pelMesVistes += " [VISTA: " + vp.obteDataVisualitzacio() + "]";
            }
            catch (const std::exception& e) {
             
            }
        }
        pelMesVistes += "\n";
    }

    return pelMesVistes;
}