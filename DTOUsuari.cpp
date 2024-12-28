#include "DTOUsuari.h"
#include <sstream>

// Constructor por defecto
DTOUsuari::DTOUsuari()
    : nom(""), sobrenom(""), correuElectronic(""), dataNaixement(""),
    modalitatSubscripcio(""), numVisualitzacionsPel�l�cules(0), numVisualitzacionsCap�tols(0) {}

// Constructor parametrizado
DTOUsuari::DTOUsuari(const std::string& nom, const std::string& sobrenom,
    const std::string& correuElectronic, const std::string& dataNaixement,
    const std::string& modalitatSubscripcio, int numPel�l�cules, int numCap�tols)
    : nom(nom), sobrenom(sobrenom), correuElectronic(correuElectronic),
    dataNaixement(dataNaixement), modalitatSubscripcio(modalitatSubscripcio),
    numVisualitzacionsPel�l�cules(numPel�l�cules), numVisualitzacionsCap�tols(numCap�tols) {}

// M�todo para convertir los datos a un string
std::string DTOUsuari::toString() const {
    std::ostringstream oss;
    oss << "Nom complet: " << nom << "\n"
        << "Sobrenom: " << sobrenom << "\n"
        << "Correu electr�nic: " << correuElectronic << "\n"
        << "Data de naixement: " << dataNaixement << "\n"
        << "Modalitat subscripci�: " << modalitatSubscripcio << "\n"
        << "Pel�l�cules visualitzades: " << numVisualitzacionsPel�l�cules << "\n"
        << "Cap�tols visualitzats: " << numVisualitzacionsCap�tols << "\n";
    return oss.str();
}