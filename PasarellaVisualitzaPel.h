#ifndef PASARELLAVISUALITZAPEL_H
#define PASARELLAVISUALITZAPEL_H

#include<iostream>
#include <string>

class PasarellaVisualitzaPel {
private:
    // Atributos
    std::string _sobrenom;
    std::string _nomPelicula;
    std::string _dataVisualitzacio;
    int _numVisualitzacions;

public:
    // Constructores
    PasarellaVisualitzaPel();
    PasarellaVisualitzaPel(std::string sobrenom, std::string nomPelicula, std::string dataVisualitzacio, int numVisualitzacions);

    // Getters
    std::string obteSobrenom() const;
    std::string obteNomPelicula() const;
    std::string obteDataVisualitzacio() const;
    int obteNumVisualitzacions() const;

    // Setters
    void posaSobrenom(const std::string& sobrenom);
    void posaNomPelicula(const std::string& nomPelicula);
    void posaDataVisualitzacio(const std::string& dataVisualitzacio);
    void posaNumVisualitzacions(int numVisualitzacions);

    // Operaciones con la base de datos
    void insereix();
    void aumentarNumVis();
};

#endif // PASARELLAVISUALITZAPEL_H
