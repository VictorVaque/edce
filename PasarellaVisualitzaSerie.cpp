#include "PasarellaVisualitzaSerie.h"
#include "Conexio.h"
#include <stdexcept>

// Constructores
PasarellaVisualitzaSerie::PasarellaVisualitzaSerie() : _numVisualitzacions(0) {}

PasarellaVisualitzaSerie::PasarellaVisualitzaSerie(std::string sobrenom, std::string nomSerie, std::string dataVisualitzacio, int numVisualitzacions)
    : _sobrenom(sobrenom), _nomSerie(nomSerie), _dataVisualitzacio(dataVisualitzacio), _numVisualitzacions(numVisualitzacions) {}

// Getters
std::string PasarellaVisualitzaSerie::obteSobrenom() const {
    return _sobrenom;
}

std::string PasarellaVisualitzaSerie::obteNomSerie() const {
    return _nomSerie;
}

std::string PasarellaVisualitzaSerie::obteDataVisualitzacio() const {
    return _dataVisualitzacio;
}

int PasarellaVisualitzaSerie::obteNumVisualitzacions() const {
    return _numVisualitzacions;
}

// Setters
void PasarellaVisualitzaSerie::posaSobrenom(const std::string& sobrenom) {
    _sobrenom = sobrenom;
}

void PasarellaVisualitzaSerie::posaNomSerie(const std::string& nomSerie) {
    _nomSerie = nomSerie;
}

void PasarellaVisualitzaSerie::posaDataVisualitzacio(const std::string& dataVisualitzacio) {
    _dataVisualitzacio = dataVisualitzacio;
}

void PasarellaVisualitzaSerie::posaNumVisualitzacions(int numVisualitzacions) {
    _numVisualitzacions = numVisualitzacions;
}

// Operaciones con la base de datos
void PasarellaVisualitzaSerie::insereix() {
    Conexio& con = Conexio::getInstance();
    try {
        std::string query = "INSERT INTO visualitzacio_serie (sobrenom_usuari, titol_serie, data, num_visualitzacions) VALUES ('" +
            _sobrenom + "', '" +
            _nomSerie + "', '" +
            _dataVisualitzacio + "', " +
            std::to_string(_numVisualitzacions) + ")";
        con.executar(query);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error al insertar visualitzacio de serie en la base de dades: " + std::string(e.what()));
    }
}

void PasarellaVisualitzaSerie::aumentarNumVis() {
    Conexio& con = Conexio::getInstance();
    try {
        std::string query = "UPDATE visualitzacio_serie SET num_visualitzacions = num_visualitzacions + 1 WHERE sobrenom_usuari = '" +
            _sobrenom + "' AND titol_serie = '" + _nomSerie + "'";
        con.executar(query);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error al actualizar el numero de visualitzacions en la base de dades: " + std::string(e.what()));
    }
}
