#ifndef TX_VISUALITZAR_CAPITOL_H
#define TX_VISUALITZAR_CAPITOL_H

#include<iostream>
#include<vector>
#include"CercadoraCapitol.h"
#include"PasarellaCapitol.h"
#include"CercadoraVisualitzaCapitol.h"
#include"PasarellaVisualitzaCapitol.h"
#include"CercadoraSerie.h"
#include"PasarellaSerie.h"
#include"CercadoraVisualitzaSerie.h"
#include"PasarellaVisualitzaSerie.h"
#include"PetitFlix.h"
using namespace std;

class TxVisualitzarCapitol {

    private:
        string nomSerie;
        int numTempEscollida;
        int numTemporades;
        int numCapitols;
        int numCapEscollit;
        vector<PasarellaCapitol> capitols;

    public:
        TxVisualitzarCapitol();

        TxVisualitzarCapitol(string &nSerie, int nTemporada);

        ~TxVisualitzarCapitol();

        void executar();

        void EscollirCap(int nCap);

        string getNomSerie() const;

        int getNumTemporada() const;

        int getNumCapitols() const;

        vector<PasarellaCapitol> getCapitols() const;

};

#endif
