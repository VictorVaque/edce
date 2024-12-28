#include "CercadoraSerie.h"
#include "Conexio.h"
#include <stdexcept>

// Constructor
CercadoraSerie::CercadoraSerie() {}

// M�todo para buscar una serie espec�fica
PasarellaSerie CercadoraSerie::cercaSerie(const std::string& nomSerie) {
    Conexio& con = Conexio::getInstance();
    try {
        std::string query = "SELECT nom, num_temporades FROM serie WHERE nom = '" + nomSerie + "'";

        auto resultSet = con.executar(query);

        if (resultSet->next()) {
            std::string nom = resultSet->getString("nom");
            int numTemporades = resultSet->getInt("num_temporades");

            // Obtener el n�mero de cap�tulos por temporada
            std::vector<int> numCapitolsPerTemporada;
            for (int i = 1; i <= numTemporades; ++i) {
                std::string capQuery = "SELECT COUNT(*) AS num_capitols FROM capitol WHERE titol_serie = '" +
                    nom + "' AND num_temporada = " + std::to_string(i);
                auto capResultSet = con.executar(capQuery);
                if (capResultSet->next()) {
                    numCapitolsPerTemporada.push_back(capResultSet->getInt("num_capitols"));
                }
            }

            return PasarellaSerie(nom, numTemporades, numCapitolsPerTemporada);
        }
        else {
            throw std::runtime_error("No s'ha trobat cap s�rie amb aquest nom.");
        }
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al cercar la s�rie en la base de dades: " + std::string(e.what()));
    }
}

// Nuevo m�todo para obtener todas las series
std::vector<PasarellaSerie> CercadoraSerie::cercaTotesSeries() {
    Conexio& con = Conexio::getInstance();
    std::vector<PasarellaSerie> totesSeries;

    try {
        // Consulta para obtener todas las series
        std::string query = "SELECT nom, num_temporades FROM serie";
        auto resultSet = con.executar(query);

        while (resultSet->next()) {
            std::string nom = resultSet->getString("nom");
            int numTemporades = resultSet->getInt("num_temporades");

            // Obtener el n�mero de cap�tulos por temporada
            std::vector<int> numCapitolsPerTemporada;
            for (int i = 1; i <= numTemporades; ++i) {
                std::string capQuery = "SELECT COUNT(*) AS num_capitols FROM capitol WHERE titol_serie = '" +
                    nom + "' AND num_temporada = " + std::to_string(i);
                auto capResultSet = con.executar(capQuery);
                if (capResultSet->next()) {
                    numCapitolsPerTemporada.push_back(capResultSet->getInt("num_capitols"));
                }
            }

            // Crear objeto PasarellaSerie y a�adirlo al vector
            totesSeries.emplace_back(nom, numTemporades, numCapitolsPerTemporada);
        }

        return totesSeries;
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al cercar totes les s�ries en la base de dades: " + std::string(e.what()));
    }
}