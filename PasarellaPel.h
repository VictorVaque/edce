#ifndef PASARELLAPEL_H
#define PASARELLAPEL_H

#include <string>

class PasarellaPel {
private:
    // Atributs
    std::string _nom;
    std::string _descripcio;
    std::string _qualificacio;
    std::string _dataEstrena;
    int _numVis;
    std::string _modalitat;
    int _duracio;

public:
    // Constructors
    PasarellaPel();
    PasarellaPel(std::string nom, std::string descripcio, std::string qualificacio, std::string dataEstrena, int duracio);

    // Getters
    std::string obteNom() const;
    std::string obteDescripcio() const;
    std::string obteQualificacio() const;
    std::string obteDataEstrena() const;
    std::string obteMod() const;
    int obteNumVisualitzacions() const;
    int obteDuracio() const;

    // Setters
    void posaNom(const std::string& nom);
    void posaDescripcio(const std::string& descripcio);
    void posaQualificacio(const std::string& qualificacio);
    void posaDataEstrena(const std::string& dataEstrena);
    void posaDuracio(int duracio);
};

#endif // PASARELLAPEL_H
