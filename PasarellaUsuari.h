#ifndef PASARELLAUSUARI_H
#define PASARELLAUSUARI_H

#include <string>

class PasarellaUsuari {
private:
    std::string _nom;
    std::string _sobrenom;
    std::string _contrasenya;
    std::string _correuElectronic;
    std::string _dataNaixement;
    std::string _subscripcio;

public:
    // Constructores
    PasarellaUsuari();
    PasarellaUsuari(std::string nomU, std::string sobrenomU, std::string contrasenyaU, std::string correuElectronicU, std::string dataNaixementU, std::string subscripcioU);

    // Operador de asignación
    PasarellaUsuari& operator=(const PasarellaUsuari& other);

    // Getters
    std::string obteNom();
    std::string obteSobrenom();
    std::string obteContrasenya();
    std::string obteCorreuElectronic();
    std::string obteDataNaixement();
    std::string obteSubscripcio();

    // Setters
    void posaNom(std::string nom);
    void posaContrasenya(std::string contrasenya);
    void posaCorreuElectronic(std::string correuElectronic);
    void posaDataNaixement(std::string dataNaixement);
    void posaSubscripcio(std::string subscripcio);

    // Métodos para interactuar con la base de datos
    void insereix();
    void modifica();
    void esborra();
};

#endif // PASARELLAUSUARI_H

