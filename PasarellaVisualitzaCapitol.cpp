#include "PasarellaVisualitzaCapitol.h"
#include "Conexio.h"
#include <stdexcept>

// Constructores
PasarellaVisualitzaCapitol::PasarellaVisualitzaCapitol() : _numVisualitzacions(0), _numTemporada(0), _numCapitol(0) {}

PasarellaVisualitzaCapitol::PasarellaVisualitzaCapitol(std::string sobrenom, std::string nomSerie, int numVisualitzacions, int numTemporada, int numCapitol, std::string dataVisualitzacio)
    : _sobrenom(sobrenom), _nomSerie(nomSerie), _numVisualitzacions(numVisualitzacions), _numTemporada(numTemporada), _numCapitol(numCapitol), _dataVisualitzacio(dataVisualitzacio) {}

// Getters
std::string PasarellaVisualitzaCapitol::obteSobrenom() const {
    return _sobrenom;
}

std::string PasarellaVisualitzaCapitol::obteNomSerie() const {
    return _nomSerie;
}

int PasarellaVisualitzaCapitol::obteNumVisualitzacions() const {
    return _numVisualitzacions;
}

int PasarellaVisualitzaCapitol::obteNumTemporada() const {
    return _numTemporada;
}

int PasarellaVisualitzaCapitol::obteNumCapitol() const {
    return _numCapitol;
}

std::string PasarellaVisualitzaCapitol::obteDataVisualitzacio() const {
    return _dataVisualitzacio;
}

// Setters
void PasarellaVisualitzaCapitol::posaSobrenom(const std::string& sobrenom) {
    _sobrenom = sobrenom;
}

void PasarellaVisualitzaCapitol::posaNomSerie(const std::string& nomSerie) {
    _nomSerie = nomSerie;
}

void PasarellaVisualitzaCapitol::posaNumVisualitzacions(int numVisualitzacions) {
    _numVisualitzacions = numVisualitzacions;
}

void PasarellaVisualitzaCapitol::posaNumTemporada(int numTemporada) {
    _numTemporada = numTemporada;
}

void PasarellaVisualitzaCapitol::posaNumCapitol(int numCapitol) {
    _numCapitol = numCapitol;
}

void PasarellaVisualitzaCapitol::posaDataVisualitzacio(const std::string& dataVisualitzacio) {
    _dataVisualitzacio = dataVisualitzacio;
}

// Operaciones con la base de datos
void PasarellaVisualitzaCapitol::insereix() {
    Conexio& con = Conexio::getInstance();
    try {
        std::string query = "INSERT INTO visualitzacio_capitol (sobrenom_usuari, titol_serie, num_temporada, num_capitol, data, num_visualitzacions) VALUES ('" +
            _sobrenom + "', '" +
            _nomSerie + "', " +
            std::to_string(_numTemporada) + ", " +
            std::to_string(_numCapitol) + ", '" +
            _dataVisualitzacio + "', " +
            std::to_string(_numVisualitzacions) + ")";
        con.executar(query);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error al insertar visualitzacio de capítol en la base de dades: " + std::string(e.what()));
    }
}

void PasarellaVisualitzaCapitol::aumentarNumVis() {
    Conexio& con = Conexio::getInstance();
    try {
        std::string query = "UPDATE visualitzacio_capitol SET num_visualitzacions = num_visualitzacions + 1 WHERE sobrenom_usuari = '" +
            _sobrenom + "' AND titol_serie = '" + _nomSerie + "' AND num_temporada = " +
            std::to_string(_numTemporada) + " AND num_capitol = " +
            std::to_string(_numCapitol);
        con.executar(query);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error al actualizar el numero de visualitzacions en la base de dades: " + std::string(e.what()));
    }
}
