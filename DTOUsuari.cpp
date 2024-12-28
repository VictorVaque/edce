#include "DTOUsuari.h"
#include <sstream>

// Constructor por defecto
DTOUsuari::DTOUsuari()
    : nom(""), sobrenom(""), correuElectronic(""), dataNaixement(""),
    modalitatSubscripcio(""), numVisualitzacionsPel·lícules(0), numVisualitzacionsCapítols(0) {}

// Constructor parametrizado
DTOUsuari::DTOUsuari(const std::string& nom, const std::string& sobrenom,
    const std::string& correuElectronic, const std::string& dataNaixement,
    const std::string& modalitatSubscripcio, int numPel·lícules, int numCapítols)
    : nom(nom), sobrenom(sobrenom), correuElectronic(correuElectronic),
    dataNaixement(dataNaixement), modalitatSubscripcio(modalitatSubscripcio),
    numVisualitzacionsPel·lícules(numPel·lícules), numVisualitzacionsCapítols(numCapítols) {}

// Método para convertir los datos a un string
std::string DTOUsuari::toString() const {
    std::ostringstream oss;
    oss << "Nom complet: " << nom << "\n"
        << "Sobrenom: " << sobrenom << "\n"
        << "Correu electrònic: " << correuElectronic << "\n"
        << "Data de naixement: " << dataNaixement << "\n"
        << "Modalitat subscripció: " << modalitatSubscripcio << "\n"
        << "Pel·lícules visualitzades: " << numVisualitzacionsPel·lícules << "\n"
        << "Capítols visualitzats: " << numVisualitzacionsCapítols << "\n";
    return oss.str();
}