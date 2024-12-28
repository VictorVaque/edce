#include "PasarellaUsuari.h"
#include "Conexio.h"
#include <stdexcept>
#include <string>

PasarellaUsuari::PasarellaUsuari() {
    _nom = "";
    _sobrenom = "";
    _contrasenya = "";
    _correuElectronic = "";
    _dataNaixement = "";
    _subscripcio = "";
}

PasarellaUsuari::PasarellaUsuari(std::string nomU, std::string sobrenomU, std::string contrasenyaU, std::string correuElectronicU, std::string dataNaixementU, std::string subscripcioU) {
    _nom = nomU;
    _sobrenom = sobrenomU;
    _contrasenya = contrasenyaU;
    _correuElectronic = correuElectronicU;
    _dataNaixement = dataNaixementU;
    _subscripcio = subscripcioU;
}

PasarellaUsuari& PasarellaUsuari::operator=(const PasarellaUsuari& other) {
    _nom = other._nom;
    _sobrenom = other._sobrenom;
    _contrasenya = other._contrasenya;
    _correuElectronic = other._correuElectronic;
    _dataNaixement = other._dataNaixement;
    _subscripcio = other._subscripcio;
    return *this;
}

std::string PasarellaUsuari::obteNom() {
    return _nom;
}

std::string PasarellaUsuari::obteSobrenom() {
    return _sobrenom;
}

std::string PasarellaUsuari::obteContrasenya() {
    return _contrasenya;
}

std::string PasarellaUsuari::obteCorreuElectronic() {
    return _correuElectronic;
}

std::string PasarellaUsuari::obteDataNaixement() {
    return _dataNaixement;
}

std::string PasarellaUsuari::obteSubscripcio() {
    return _subscripcio;
}

void PasarellaUsuari::posaNom(std::string nom) {
    _nom = nom;
}

void PasarellaUsuari::posaContrasenya(std::string contrasenya) {
    _contrasenya = contrasenya;
}

void PasarellaUsuari::posaCorreuElectronic(std::string correuElectronic) {
    _correuElectronic = correuElectronic;
}

void PasarellaUsuari::posaDataNaixement(std::string dataNaixement) {
    _dataNaixement = dataNaixement;
}

void PasarellaUsuari::posaSubscripcio(std::string subscripcio) {
    _subscripcio = subscripcio;
}

void PasarellaUsuari::insereix() {
    Conexio& con = Conexio::getInstance();
    try {
        std::string query = "INSERT INTO usuari (nom, sobrenom, contrasenya, correu_electronic, data_naixement, subscripcio) VALUES ('" +
            _nom + "', '" +
            _sobrenom + "', '" +
            _contrasenya + "', '" +
            _correuElectronic + "', '" +
            _dataNaixement + "', '" +
            _subscripcio + "')";
        con.executar(query);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error al insertar usuari en la base de dades: " + std::string(e.what()));
    }
}

void PasarellaUsuari::modifica() {
    Conexio& con = Conexio::getInstance();
    try {
        std::string query = "UPDATE usuari SET nom='" + _nom + "', contrasenya='" + _contrasenya + "', correu_electronic='" + _correuElectronic + "', data_naixement='" + _dataNaixement + "', subscripcio='" + _subscripcio + "' WHERE sobrenom='" + _sobrenom + "'";
        con.executar(query);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error al modificar usuari en la base de dades: " + std::string(e.what()));
    }
}

void PasarellaUsuari::esborra() {
    Conexio& con = Conexio::getInstance();
    try {
        std::string query = "DELETE FROM usuari WHERE sobrenom='" + _sobrenom + "'";
        con.executar(query);
    } catch (const std::exception& e) {
        throw std::runtime_error("Error al esborrar usuari en la base de dades: " + std::string(e.what()));
    }
}
