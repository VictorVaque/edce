#include "CercadoraVisualitzaPel.h"
#include "Conexio.h"
#include <stdexcept>

// Constructor
CercadoraVisualitzaPel::CercadoraVisualitzaPel() {}

// Cerca una visualització concreta d'una pel·lícula basada en el sobrenom de l'usuari i el títol de la pel·lícula
PasarellaVisualitzaPel CercadoraVisualitzaPel::cercaVisualitzaPel(const std::string& sobrenom, const std::string& nomPelicula) {
    Conexio& con = Conexio::getInstance(); // Obtenim la connexió a la base de dades
    try {
        // Consulta SQL per buscar la visualització específica
        std::string query = "SELECT sobrenom_usuari, titol_pelicula, data, num_visualitzacions FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" +
            sobrenom + "' AND titol_pelicula = '" + nomPelicula + "'";

        auto resultSet = con.executar(query); // Executem la consulta

        if (resultSet->next()) {
            // Extreiem les dades de la visualització
            std::string sobrenomUsuari = resultSet->getString("sobrenom_usuari");
            std::string titolPelicula = resultSet->getString("titol_pelicula");
            std::string dataVisualitzacio = resultSet->getString("data");
            int numVisualitzacions = resultSet->getInt("num_visualitzacions");

            // Retornem una instància de PasarellaVisualitzaPel amb les dades obtingudes
            return PasarellaVisualitzaPel(sobrenomUsuari, titolPelicula, dataVisualitzacio, numVisualitzacions);
        }
        else {
            // Si no es troben registres, llancem una excepció
            throw std::runtime_error("No s'ha trobat cap registre de visualitzacio per a la pel·lícula indicada.");
        }
    }
    catch (const std::exception& e) {
        // Gestionem els errors de la base de dades
        throw std::runtime_error("Error al cercar la visualització de pel·lícula en la base de dades: " + std::string(e.what()));
    }
}

// Cerca totes les visualitzacions de pel·lícules d'un usuari donat
std::vector<PasarellaVisualitzaPel> CercadoraVisualitzaPel::cercaTotesVisualitzacionsPel(const std::string& sobrenom) {
    Conexio& con = Conexio::getInstance(); // Obtenim la connexió a la base de dades
    std::vector<PasarellaVisualitzaPel> visualitzacionsPel;

    try {
        // Consulta SQL per obtenir totes les visualitzacions associades a un usuari
        std::string query = "SELECT sobrenom_usuari, titol_pelicula, data, num_visualitzacions FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + sobrenom + "'";

        auto resultSet = con.executar(query); // Executem la consulta

        // Recorrem els resultats i els afegim al vector
        while (resultSet->next()) {
            std::string sobrenomUsuari = resultSet->getString("sobrenom_usuari");
            std::string titolPelicula = resultSet->getString("titol_pelicula");
            std::string dataVisualitzacio = resultSet->getString("data");
            int numVisualitzacions = resultSet->getInt("num_visualitzacions");

            // Afegim una instància de PasarellaVisualitzaPel al vector
            visualitzacionsPel.emplace_back(sobrenomUsuari, titolPelicula, dataVisualitzacio, numVisualitzacions);
        }

        // Retornem el vector amb totes les visualitzacions trobades
        return visualitzacionsPel;
    }
    catch (const std::exception& e) {
        // Gestionem els errors de la base de dades
        throw std::runtime_error("Error al cercar totes les visualitzacions de pel·lícules per a l'usuari: " + std::string(e.what()));
    }
}