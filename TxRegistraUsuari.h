#ifndef TXREGISTRAUSUARI_H
#define TXREGISTRAUSUARI_H

using namespace std;
#include "PasarellaUsuari.h"
#include <iostream>

class TxRegistraUsuari {

    private:
        string nomU;
        string sobrenomU;
		string contrasenyaU;
		string correuElectronicU;
		string dataNaiexementU;
		string modalitatSubscripcio;

	public:

		/* Pre: cert */
		/* Post: es crea un TxRegistraUsuari amb (nomU, sobrenomU, contrasenyaU, correuElectronicU, dataNaixamentU, modalitatU)*/
		TxRegistraUsuari(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixamentU, string modalitatU);

		/* Pre: no existeix cap usuari amb corre = correuElectronicU i sobrenom = sobrenomU */
		/* Post: es crea un Usuari u = (nomU, sobrenomU, contrasenyaU, correuElectronicU, dataNaixamentU, modalitatU)*/
		void executa();

};

#endif;
