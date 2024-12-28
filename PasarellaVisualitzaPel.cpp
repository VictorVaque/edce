#include "PasarellaVisualitzaPel.h"
#include "Conexio.h"
#include <stdexcept>

// Constructores
PasarellaVisualitzaPel::PasarellaVisualitzaPel() : _numVisualitzacions(0) {}

PasarellaVisualitzaPel::PasarellaVisualitzaPel(std::string sobrenom, std::string nomPelicula, std::string dataVisualitzacio, int numVisualitzacions)
    : _sobrenom(sobrenom), _nomPelicula(nomPelicula), _dataVisualitzacio(dataVisualitzacio), _numVisualitzacions(numVisualitzacions) {}

// Getters
std::string PasarellaVisualitzaPel::obteSobrenom() const {
    return _sobrenom;
}

std::string PasarellaVisualitzaPel::obteNomPelicula() const {
    return _nomPelicula;
}

std::string PasarellaVisualitzaPel::obteDataVisualitzacio() const {
    return _dataVisualitzacio;
}

int PasarellaVisualitzaPel::obteNumVisualitzacions() const {
    return _numVisualitzacions;
}

// Setters
void PasarellaVisualitzaPel::posaSobrenom(const std::string& sobrenom) {
    _sobrenom = sobrenom;
}

void PasarellaVisualitzaPel::posaNomPelicula(const std::string& nomPelicula) {
    _nomPelicula = nomPelicula;
}

void PasarellaVisualitzaPel::posaDataVisualitzacio(const std::string& dataVisualitzacio) {
    _dataVisualitzacio = dataVisualitzacio;
}

void PasarellaVisualitzaPel::posaNumVisualitzacions(int numVisualitzacions) {
    _numVisualitzacions = numVisualitzacions;
}

// Operaciones con la base de datos
void PasarellaVisualitzaPel::insereix() {
    Conexio& con = Conexio::getInstance();
    try {
        std::string query = "INSERT INTO visualitzacio_pelicula (sobrenom_usuari, titol_pelicula, data, num_visualitzacions) VALUES ('" +
            _sobrenom + "', '" +
            _nomPelicula + "', '" +
            _dataVisualitzacio + "', " +
            std::to_string(_numVisualitzacions) + ")";
        con.executar(query);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error al insertar visualitzacio de pelicula en la base de dades: " + std::string(e.what()));
    }
}

void PasarellaVisualitzaPel::aumentarNumVis() {
    Conexio& con = Conexio::getInstance();
    try {
        std::string query = "UPDATE visualitzacio_pelicula SET num_visualitzacions = num_visualitzacions + 1 WHERE sobrenom_usuari = '" +
            _sobrenom + "' AND titol_pelicula = '" + _nomPelicula + "'";
        con.executar(query);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error al actualizar el numero de visualitzacions en la base de dades: " + std::string(e.what()));
    }
}
