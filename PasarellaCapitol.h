#ifndef PASARELLACAPITOL_H
#define PASARELLACAPITOL_H

#include <string>

class PasarellaCapitol {
private:
    // Atributs
    std::string _nomCapitol;
    std::string _dataEstrena;
    int _duracio;

public:
    // Constructors
    PasarellaCapitol();
    PasarellaCapitol(std::string nomCapitol, std::string dataEstrena);

    // Getters
    std::string obteNomCapitol() const;
    std::string obteDataEstrena() const;
    int obteDuracio() const;

    // Setters
    void posaNomCapitol(const std::string& nomCapitol);
    void posaDataEstrena(const std::string& dataEstrena);
};

#endif // PASARELLACAPITOL_H
