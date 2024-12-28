#include "PasarellaSerie.h"
#include <stdexcept>

// Constructors
PasarellaSerie::PasarellaSerie() : _numTemporades(0) {}

PasarellaSerie::PasarellaSerie(const std::string& nom, int numTemporades, const std::vector<int>& numCapitolsPerTemporada)
    : _nom(nom), _numTemporades(numTemporades), _numCapitolsPerTemporada(numCapitolsPerTemporada) {}

// Getters
std::string PasarellaSerie::obteNom() const {
    return _nom;
}

std::string PasarellaSerie::obteMod() const {
    return _modalitat;
}

std::string PasarellaSerie::obteQualificacio() const {
    return _qualificacio;
}

std::string PasarellaSerie::obteData() const {
    return _data;
}

int PasarellaSerie::obteNumTemp() const {
    return _numTemporades;
}

int PasarellaSerie::obteNumCap(int numTemporada) const {
    if (numTemporada > 0 && numTemporada <= static_cast<int>(_numCapitolsPerTemporada.size())) {
        return _numCapitolsPerTemporada[numTemporada - 1];
    }
    else {
        throw std::out_of_range("Número de temporada no válido.");
    }
}

// Setters
void PasarellaSerie::posaNom(const std::string& nom) {
    _nom = nom;
}

void PasarellaSerie::posaNumTemp(int numTemporades) {
    _numTemporades = numTemporades;
}

void PasarellaSerie::posaNumCapPerTemp(const std::vector<int>& numCapitolsPerTemporada) {
    _numCapitolsPerTemporada = numCapitolsPerTemporada;
}
