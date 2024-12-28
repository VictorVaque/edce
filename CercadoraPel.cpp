#include "CercadoraPel.h"
#include "Conexio.h"
#include <stdexcept>

// Constructor
CercadoraPel::CercadoraPel() {}

// Método para buscar una película específica
PasarellaPel CercadoraPel::cercaPel(const std::string& nomPelicula) {
    Conexio& con = Conexio::getInstance();
    try {
        std::string query = "SELECT nom, descripcio, qualificacio, data_estrena, duracio FROM pelicula WHERE nom = '" + nomPelicula + "'";

        auto resultSet = con.executar(query);

        if (resultSet->next()) {
            std::string nom = resultSet->getString("nom");
            std::string descripcio = resultSet->getString("descripcio");
            std::string qualificacio = resultSet->getString("qualificacio");
            std::string dataEstrena = resultSet->getString("data_estrena");
            int duracio = resultSet->getInt("duracio");

            return PasarellaPel(nom, descripcio, qualificacio, dataEstrena, duracio);
        }
        else {
            throw std::runtime_error("No s'ha trobat cap pel·lícula amb aquest nom.");
        }
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al cercar la pel·lícula en la base de dades: " + std::string(e.what()));
    }
}

// Método para buscar películas relacionadas
std::vector<PasarellaPel> CercadoraPel::cercaRelacionadesPel(const std::string& nomFragment) {
    Conexio& con = Conexio::getInstance();
    std::vector<PasarellaPel> peliculesRelacionades;

    try {
        std::string query = "SELECT nom, descripcio, qualificacio, data_estrena, duracio FROM pelicula WHERE nom LIKE '%" + nomFragment + "%'";

        auto resultSet = con.executar(query);

        while (resultSet->next()) {
            std::string nom = resultSet->getString("nom");
            std::string descripcio = resultSet->getString("descripcio");
            std::string qualificacio = resultSet->getString("qualificacio");
            std::string dataEstrena = resultSet->getString("data_estrena");
            int duracio = resultSet->getInt("duracio");

            peliculesRelacionades.emplace_back(nom, descripcio, qualificacio, dataEstrena, duracio);
        }

        return peliculesRelacionades;
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al cercar pel·lícules relacionades en la base de dades: " + std::string(e.what()));
    }
}

// Nuevo método para obtener todas las películas
std::vector<PasarellaPel> CercadoraPel::cercaTotesPel() {
    Conexio& con = Conexio::getInstance();
    std::vector<PasarellaPel> totesPelicules;

    try {
        std::string query = "SELECT nom, descripcio, qualificacio, data_estrena, duracio FROM pelicula";

        auto resultSet = con.executar(query);

        while (resultSet->next()) {
            std::string nom = resultSet->getString("nom");
            std::string descripcio = resultSet->getString("descripcio");
            std::string qualificacio = resultSet->getString("qualificacio");
            std::string dataEstrena = resultSet->getString("data_estrena");
            int duracio = resultSet->getInt("duracio");

            totesPelicules.emplace_back(nom, descripcio, qualificacio, dataEstrena, duracio);
        }

        return totesPelicules;
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al cercar totes les pel·lícules en la base de dades: " + std::string(e.what()));
    }
}