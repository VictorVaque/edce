#include "TxIniciSessio.h"

TxIniciSessio::TxIniciSessio(string &sU, string &cU) : sobrenomU(sU), contrasenyaU(cU) {}

void TxIniciSessio::executar() {
	
	CercadoraUsuari aux;
    PasarellaUsuari usuari = aux.cercaUsuari(sobrenomU);
	string con = usuari.obteContrasenya();
	PetitFlix& p = PetitFlix::getInstance();
	if (contrasenyaU != con) throw runtime_error("Error: Contrasenya incorrecta.");
	else {
		p.iniciar_sessio(usuari);
	}
}
