#include "PasarellaCapitol.h"

// Constructors
PasarellaCapitol::PasarellaCapitol() : _nomCapitol(""), _dataEstrena("") {}

PasarellaCapitol::PasarellaCapitol(std::string nomCapitol, std::string dataEstrena)
    : _nomCapitol(nomCapitol), _dataEstrena(dataEstrena) {}

// Getters
std::string PasarellaCapitol::obteNomCapitol() const {
    return _nomCapitol;
}

std::string PasarellaCapitol::obteDataEstrena() const {
    return _dataEstrena;
}

int PasarellaCapitol::obteDuracio() const {
    return _duracio;
}

// Setters
void PasarellaCapitol::posaNomCapitol(const std::string& nomCapitol) {
    _nomCapitol = nomCapitol;
}

void PasarellaCapitol::posaDataEstrena(const std::string& dataEstrena) {
    _dataEstrena = dataEstrena;
}
