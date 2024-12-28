#ifndef TXTANCASESSIO_H
#define TXTANCASESSIO_H

#pragma once
#include "PetitFlix.h"
#include <iostream>
#include <string>
using namespace std;

class TxTancaSessio {

	private:
	
	public:

		/* Pre: cert */ 
		/* Post: crea un TxTancaSessio */
		TxTancaSessio();

		/* Pre: Existeix un usuari loggejat*/
		/* Post: el sistema registra que no hi ha cap usuari loggejat a partir d’aquest moment */
		void executar();

};

#endif;
