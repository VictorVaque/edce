#ifndef PASARELLAVISUALITZASERIE_H
#define PASARELLAVISUALITZASERIE_H

#include <string>

class PasarellaVisualitzaSerie {
private:
    // Atributos
    std::string _sobrenom;
    std::string _nomSerie;
    std::string _dataVisualitzacio;
    int _numVisualitzacions;

public:
    // Constructores
    PasarellaVisualitzaSerie();
    PasarellaVisualitzaSerie(std::string sobrenom, std::string nomSerie, std::string dataVisualitzacio, int numVisualitzacions);

    // Getters
    std::string obteSobrenom() const;
    std::string obteNomSerie() const;
    std::string obteDataVisualitzacio() const;
    int obteNumVisualitzacions() const;

    // Setters
    void posaSobrenom(const std::string& sobrenom);
    void posaNomSerie(const std::string& nomSerie);
    void posaDataVisualitzacio(const std::string& dataVisualitzacio);
    void posaNumVisualitzacions(int numVisualitzacions);

    // Operaciones con la base de datos
    void insereix();
    void aumentarNumVis();
};

#endif // PASARELLAVISUALITZASERIE_H
