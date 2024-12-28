#pragma once
#ifndef TX_ESBORRAR_USUARI_H
#define TX_ESBORRAR_USUARI_H

#include<iostream>
#include <string>
#include "PetitFlix.h"
#include "PasarellaUsuari.h"
using namespace std;
    
class TxEsborrarUsuari {
    private:
        string contraU;

    public:
        TxEsborrarUsuari(string &contrasenyaU);

        void executar();
};

#endif
