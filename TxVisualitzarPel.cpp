#include"TxVisualitzarPel.h"

TxVisualitzarPel::TxVisualitzarPel(string& nP) : nomP(nP) {
    CercadoraPel aux;

    try {
        PasarellaPel peli = aux.cercaPel(nomP);
        descP = peli.obteDescripcio();
        qualP = peli.obteQualificacio();
        dataP = peli.obteDataEstrena();
        durP = peli.obteDuracio();
    }
    catch (const std::runtime_error&) {
        // Manejo del caso en que no se encuentra la película.
        descP = "";
        qualP = "";
        dataP = "";
        durP = 0;
    }
}

TxVisualitzarPel::~TxVisualitzarPel() {}

string TxVisualitzarPel::getNom() const {
    return nomP;
}

string TxVisualitzarPel::getDescripcio() const {
    return descP;
}

string TxVisualitzarPel::getQualificacio() const {
    return qualP;
}

string TxVisualitzarPel::getData() const {
    return dataP;
}

int TxVisualitzarPel::getDuracio() const {
    return durP;
}

void TxVisualitzarPel::executar() {
    string sobrenom;
    CercadoraVisualitzaPel aux;
    PetitFlix& p = PetitFlix::getInstance();
    PasarellaUsuari usu = p.obteUsuari();
    sobrenom = usu.obteSobrenom();

    try {
        PasarellaVisualitzaPel vpeli = aux.cercaVisualitzaPel(sobrenom, nomP);
        vpeli.aumentarNumVis();
    }
    catch (const std::runtime_error&) {
        PasarellaVisualitzaPel vpeli(sobrenom, nomP, p.obtenirDataActual(), 1);
        vpeli.insereix();
    }
}

vector<PasarellaPel> TxVisualitzarPel::relacionades() {
    vector<PasarellaPel> pelis;
    CercadoraPel aux;

    size_t posEspai = nomP.find(' ');
    string nomp = (posEspai != string::npos) ? nomP.substr(0, posEspai) : nomP;

    pelis = aux.cercaRelacionadesPel(nomp);

    return pelis;
}
