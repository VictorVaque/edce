#include "PasarellaPel.h"

// Constructores
PasarellaPel::PasarellaPel() : _duracio(0) {}

PasarellaPel::PasarellaPel(std::string nom, std::string descripcio, std::string qualificacio, std::string dataEstrena, int duracio)
    : _nom(nom), _descripcio(descripcio), _qualificacio(qualificacio), _dataEstrena(dataEstrena), _duracio(duracio) {}

// Getters
std::string PasarellaPel::obteNom() const {
    return _nom;
}

std::string PasarellaPel::obteDescripcio() const {
    return _descripcio;
}


int PasarellaPel::obteNumVisualitzacions() const {
    return _numVis;
}

std::string PasarellaPel::obteQualificacio() const {
    return _qualificacio;
}

std::string PasarellaPel::obteDataEstrena() const {
    return _dataEstrena;
}

std::string PasarellaPel::obteMod() const {
    return _modalitat;
}

int PasarellaPel::obteDuracio() const {
    return _duracio;
}

// Setters
void PasarellaPel::posaNom(const std::string& nom) {
    _nom = nom;
}

void PasarellaPel::posaDescripcio(const std::string& descripcio) {
    _descripcio = descripcio;
}

void PasarellaPel::posaQualificacio(const std::string& qualificacio) {
    _qualificacio = qualificacio;
}

void PasarellaPel::posaDataEstrena(const std::string& dataEstrena) {
    _dataEstrena = dataEstrena;
}

void PasarellaPel::posaDuracio(int duracio) {
    _duracio = duracio;
}
