#ifndef TXINICISESSIO_H
#define TXINICISESSIO_H

#include "CercadoraUsuari.h"
#include "PasarellaUsuari.h"
#include "PetitFlix.h"
#include <iostream>
#include <string>
using namespace std;

class TxIniciSessio {
	private:
		string sobrenomU;
		string contrasenyaU;
	public:

		/* Pre: cert */ 
		/* Post: crea un TxIniciSessio amb sobrenom sU i contrasenya cU */
		TxIniciSessio(string &sU, string &cU);

		/* Pre: no hi ha un usuari loggejat – és precondició donat el mapa navegacional.
		existeix un usuari u amb u.sobrenom = sobrenomU,
		la contrasenyaU es correspon a u.contrasenya*/
		/* Post: el sistema registra que l’usuari u és el que està loggejat a partir d’aquest moment */
		void executar();

};

#endif
