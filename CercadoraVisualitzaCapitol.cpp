#include "CercadoraVisualitzaCapitol.h"
#include "Conexio.h"
#include <stdexcept>

// Constructor
CercadoraVisualitzaCapitol::CercadoraVisualitzaCapitol() {}

// Buscar una visualitzaci� concreta d'un cap�tol d'una s�rie
PasarellaVisualitzaCapitol CercadoraVisualitzaCapitol::cercaVisualitzaCapitol(const std::string& sobrenom, const std::string& nomSerie, int numTemporada, int numCapitol) {
    Conexio& con = Conexio::getInstance();
    try {
        // Consulta SQL per buscar una visualitzaci� concreta
        std::string query = "SELECT sobrenom_usuari, titol_serie, num_temporada, num_capitol, data, num_visualitzacions FROM visualitzacio_capitol WHERE sobrenom_usuari = '" +
            sobrenom + "' AND titol_serie = '" + nomSerie + "' AND num_temporada = " + std::to_string(numTemporada) + " AND num_capitol = " + std::to_string(numCapitol);

        auto resultSet = con.executar(query);

        if (resultSet->next()) {
            // Extreiem les dades del registre
            std::string sobrenomUsuari = resultSet->getString("sobrenom_usuari");
            std::string titolSerie = resultSet->getString("titol_serie");
            int temporada = resultSet->getInt("num_temporada");
            int capitol = resultSet->getInt("num_capitol");
            std::string dataVisualitzacio = resultSet->getString("data");
            int numVisualitzacions = resultSet->getInt("num_visualitzacions");

            // Retornem una inst�ncia de PasarellaVisualitzaCapitol
            return PasarellaVisualitzaCapitol(sobrenomUsuari, titolSerie, numVisualitzacions, temporada, capitol, dataVisualitzacio);
        }
        else {
            throw std::runtime_error("No s'ha trobat cap registre de visualitzacio per al cap�tol indicat.");
        }
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al cercar la visualitzacio de cap�tol en la base de dades: " + std::string(e.what()));
    }
}

// Buscar totes les visualitzacions de cap�tols associades a un usuari
std::vector<PasarellaVisualitzaCapitol> CercadoraVisualitzaCapitol::cercaTotsVisualitzaCapitols(const std::string& sobrenom) {
    Conexio& con = Conexio::getInstance();
    std::vector<PasarellaVisualitzaCapitol> visualitzacionsCapitols;

    try {
        // Consulta SQL per obtenir totes les visualitzacions de cap�tols d'un usuari
        std::string query = "SELECT sobrenom_usuari, titol_serie, num_temporada, num_capitol, data, num_visualitzacions FROM visualitzacio_capitol WHERE sobrenom_usuari = '" +
            sobrenom + "'";

        auto resultSet = con.executar(query);

        // Recorrem els resultats i afegim cada registre al vector
        while (resultSet->next()) {
            std::string sobrenomUsuari = resultSet->getString("sobrenom_usuari");
            std::string titolSerie = resultSet->getString("titol_serie");
            int temporada = resultSet->getInt("num_temporada");
            int capitol = resultSet->getInt("num_capitol");
            std::string dataVisualitzacio = resultSet->getString("data");
            int numVisualitzacions = resultSet->getInt("num_visualitzacions");

            // Creem una inst�ncia de PasarellaVisualitzaCapitol i l'afegim al vector
            visualitzacionsCapitols.emplace_back(sobrenomUsuari, titolSerie, numVisualitzacions, temporada, capitol, dataVisualitzacio);
        }

        // Retornem el vector amb totes les visualitzacions trobades
        return visualitzacionsCapitols;
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al cercar totes les visualitzacions de cap�tols per a l'usuari: " + std::string(e.what()));
    }
}