#include "PetitFlix.h"

PasarellaUsuari& PetitFlix::obteUsuari() {
	return _usuari;
}

void PetitFlix::iniciar_sessio(PasarellaUsuari u) {
	_usuari = u;
}

void PetitFlix::tanca_sessio() {
	PasarellaUsuari aux;
	_usuari = aux;
}

string PetitFlix::obtenirDataActual() {
    time_t tempsActual = time(nullptr);
    tm* tempsLocal = localtime(&tempsActual);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", tempsLocal);
    return string(buffer);
}

bool PetitFlix::hiHaUsuariLoggejat() {
	return _usuari.obteNom() != "";
}
