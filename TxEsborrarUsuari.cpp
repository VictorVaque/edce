#include "TxEsborrarUsuari.h"

TxEsborrarUsuari::TxEsborrarUsuari(string &contrasenyaU): contraU(contrasenyaU) {}

void TxEsborrarUsuari::executar() {
    
	PasarellaUsuari u;
	PetitFlix& p = PetitFlix::getInstance();
	u = p.obteUsuari();
	string c = u.obteContrasenya();
	if (c != contraU)
		throw runtime_error("Error: Contrasenya incorrecta.");
	else {
		u.esborra();
		p.tanca_sessio();
	}
}
