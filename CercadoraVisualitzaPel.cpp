#include "CercadoraVisualitzaPel.h"
#include "Conexio.h"
#include <stdexcept>

// Constructor
CercadoraVisualitzaPel::CercadoraVisualitzaPel() {}

// Cerca una visualitzaci� concreta d'una pel�l�cula basada en el sobrenom de l'usuari i el t�tol de la pel�l�cula
PasarellaVisualitzaPel CercadoraVisualitzaPel::cercaVisualitzaPel(const std::string& sobrenom, const std::string& nomPelicula) {
    Conexio& con = Conexio::getInstance(); // Obtenim la connexi� a la base de dades
    try {
        // Consulta SQL per buscar la visualitzaci� espec�fica
        std::string query = "SELECT sobrenom_usuari, titol_pelicula, data, num_visualitzacions FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" +
            sobrenom + "' AND titol_pelicula = '" + nomPelicula + "'";

        auto resultSet = con.executar(query); // Executem la consulta

        if (resultSet->next()) {
            // Extreiem les dades de la visualitzaci�
            std::string sobrenomUsuari = resultSet->getString("sobrenom_usuari");
            std::string titolPelicula = resultSet->getString("titol_pelicula");
            std::string dataVisualitzacio = resultSet->getString("data");
            int numVisualitzacions = resultSet->getInt("num_visualitzacions");

            // Retornem una inst�ncia de PasarellaVisualitzaPel amb les dades obtingudes
            return PasarellaVisualitzaPel(sobrenomUsuari, titolPelicula, dataVisualitzacio, numVisualitzacions);
        }
        else {
            // Si no es troben registres, llancem una excepci�
            throw std::runtime_error("No s'ha trobat cap registre de visualitzacio per a la pel�l�cula indicada.");
        }
    }
    catch (const std::exception& e) {
        // Gestionem els errors de la base de dades
        throw std::runtime_error("Error al cercar la visualitzaci� de pel�l�cula en la base de dades: " + std::string(e.what()));
    }
}

// Cerca totes les visualitzacions de pel�l�cules d'un usuari donat
std::vector<PasarellaVisualitzaPel> CercadoraVisualitzaPel::cercaTotesVisualitzacionsPel(const std::string& sobrenom) {
    Conexio& con = Conexio::getInstance(); // Obtenim la connexi� a la base de dades
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

            // Afegim una inst�ncia de PasarellaVisualitzaPel al vector
            visualitzacionsPel.emplace_back(sobrenomUsuari, titolPelicula, dataVisualitzacio, numVisualitzacions);
        }

        // Retornem el vector amb totes les visualitzacions trobades
        return visualitzacionsPel;
    }
    catch (const std::exception& e) {
        // Gestionem els errors de la base de dades
        throw std::runtime_error("Error al cercar totes les visualitzacions de pel�l�cules per a l'usuari: " + std::string(e.what()));
    }
}