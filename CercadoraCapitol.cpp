#include "CercadoraCapitol.h"
#include "Conexio.h"
#include <stdexcept>

// Constructor
CercadoraCapitol::CercadoraCapitol() {}

PasarellaCapitol CercadoraCapitol::cercaCapitol(const std::string& nomSerie, int numTemporada, int numCapitol) {
    Conexio& con = Conexio::getInstance();
    try {
        std::string query = "SELECT titol_capitol, data_estrena FROM capitol WHERE titol_serie = '" +
            nomSerie + "' AND num_temporada = " + std::to_string(numTemporada) +
            " AND num_capitol = " + std::to_string(numCapitol);

        auto resultSet = con.executar(query);

        if (resultSet->next()) {
            std::string nomCapitol = resultSet->getString("titol_capitol");
            std::string dataEstrena = resultSet->getString("data_estrena");

            return PasarellaCapitol(nomCapitol, dataEstrena);
        }
        else {
            throw std::runtime_error("No s'ha trobat cap registre per al capítol indicat.");
        }
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al cercar el capítol en la base de dades: " + std::string(e.what()));
    }
}