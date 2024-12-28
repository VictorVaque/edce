#pragma once
#ifndef TX_VISUALITZAR_PEL_H
#define TX_VISUALITZAR_PEL_H

#include<iostream>
#include<vector>
#include"CercadoraPel.h"
#include"PasarellaPel.h"
#include"CercadoraVisualitzaPel.h"
#include"PasarellaVisualitzaPel.h"
#include"PetitFlix.h"
using namespace std;

class TxVisualitzarPel {

    private:
    
        string nomP;
        string descP;
        string qualP;
        string dataP;
        int durP;
    
    public:

        TxVisualitzarPel(string &nP);
    
        ~TxVisualitzarPel();
    
        void executar();

        vector<PasarellaPel> relacionades();

        string getNom() const;

        string getDescripcio() const;

        string getQualificacio() const;

        string getData() const;

        int getDuracio() const;
    
};

#endif
