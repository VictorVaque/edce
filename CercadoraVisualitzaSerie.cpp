#include "CercadoraVisualitzaSerie.h"
#include "Conexio.h"
#include <stdexcept>

// Constructor
CercadoraVisualitzaSerie::CercadoraVisualitzaSerie() {}

// Métodos
PasarellaVisualitzaSerie CercadoraVisualitzaSerie::cercaVisualitzaSerie(const std::string& sobrenom, const std::string& nomSerie) {
    Conexio& con = Conexio::getInstance();
    try {
        std::string query = "SELECT sobrenom_usuari, titol_serie, data, num_visualitzacions FROM visualitzacio_serie WHERE sobrenom_usuari = '" +
            sobrenom + "' AND titol_serie = '" + nomSerie + "'";

        auto resultSet = con.executar(query);

        if (resultSet->next()) {
            std::string sobrenomUsuari = resultSet->getString("sobrenom_usuari");
            std::string titolSerie = resultSet->getString("titol_serie");
            std::string dataVisualitzacio = resultSet->getString("data");
            int numVisualitzacions = resultSet->getInt("num_visualitzacions");

            return PasarellaVisualitzaSerie(sobrenomUsuari, titolSerie, dataVisualitzacio, numVisualitzacions);
        }
        else {
            throw std::runtime_error("No s'ha trobat cap registre de visualitzacio per a la serie indicada.");
        }
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al cercar la visualitzacio de serie en la base de dades: " + std::string(e.what()));
    }
}