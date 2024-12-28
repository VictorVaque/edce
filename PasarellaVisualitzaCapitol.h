#ifndef PASARELLAVISUALITZACAPITOL_H
#define PASARELLAVISUALITZACAPITOL_H

#include <string>

class PasarellaVisualitzaCapitol {
private:
    // Atributs
    std::string _sobrenom;
    std::string _nomSerie;
    int _numVisualitzacions;
    int _numTemporada;
    int _numCapitol;
    std::string _dataVisualitzacio;

public:
    // Constructors
    PasarellaVisualitzaCapitol();
    PasarellaVisualitzaCapitol(std::string sobrenom, std::string nomSerie, int numVisualitzacions, int numTemporada, int numCapitol, std::string dataVisualitzacio);

    // Getters
    std::string obteSobrenom() const;
    std::string obteNomSerie() const;
    int obteNumVisualitzacions() const;
    int obteNumTemporada() const;
    int obteNumCapitol() const;
    std::string obteDataVisualitzacio() const;

    // Setters
    void posaSobrenom(const std::string& sobrenom);
    void posaNomSerie(const std::string& nomSerie);
    void posaNumVisualitzacions(int numVisualitzacions);
    void posaNumTemporada(int numTemporada);
    void posaNumCapitol(int numCapitol);
    void posaDataVisualitzacio(const std::string& dataVisualitzacio);

    // Operaciones con la base de datos
    void insereix();
    void aumentarNumVis();
};

#endif // PASARELLAVISUALITZACAPITOL_H
