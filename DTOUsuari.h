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
    int numVisualitzacionsPel·lícules;
    int numVisualitzacionsCapítols;

    // Constructor por defecto
    DTOUsuari();

    // Constructor parametrizado
    DTOUsuari(const string& nom, const string& sobrenom,
        const string& correuElectronic, const string& dataNaixement,
        const string& modalitatSubscripcio, int numPel·lícules, int numCapítols);

    // Métodos para serializar en texto (útil para imprimir)
    string toString() const;
};

#endif // DTOUSUARI_H