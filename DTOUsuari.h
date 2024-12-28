#ifndef DTOUSUARI_H
#define DTOUSUARI_H

using namespace std;
#include <iostream>
#include <string>

class DTOUsuari {
public:
    string nom;
    string sobrenom;
    string correuElectronic;
    string dataNaixement;
    string modalitatSubscripcio;
    int numVisualitzacionsPel�l�cules;
    int numVisualitzacionsCap�tols;

    // Constructor por defecto
    DTOUsuari();

    // Constructor parametrizado
    DTOUsuari(const string& nom, const string& sobrenom,
        const string& correuElectronic, const string& dataNaixement,
        const string& modalitatSubscripcio, int numPel�l�cules, int numCap�tols);

    // M�todos para serializar en texto (�til para imprimir)
    string toString() const;
};

#endif // DTOUSUARI_H