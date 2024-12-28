#pragma once
#include <iostream>
#include<ctime>
#include "PasarellaUsuari.h"
using namespace std;

class PetitFlix
{
private:
    // Atributos
    PasarellaUsuari _usuari;

    // Constructor privat per prevenir la creació d'instàncies
    PetitFlix() {

    }

public:
    // Mètode per obtenir la única instància d'aquesta classe (ha de ser static i estar a .h)
    static PetitFlix& getInstance() {
        static PetitFlix instance;
        return instance;
    }

    // Mètodes per obtenir i modificar els atributs (getters/setters)
    PasarellaUsuari& obteUsuari();
    void iniciar_sessio(PasarellaUsuari u);
    void tanca_sessio();
    string obtenirDataActual();
    bool hiHaUsuariLoggejat();
};
