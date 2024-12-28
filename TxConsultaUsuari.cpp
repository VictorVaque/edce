#include "TxConsultaUsuari.h"

TxConsultaUsuari::TxConsultaUsuari() {

}

TxConsultaUsuari::~TxConsultaUsuari() {}

void TxConsultaUsuari::executar() {
	PetitFlix& p = PetitFlix::getInstance();
	_usuari = p.obteUsuari();
	_resultat.nom = _usuari.obteNom();
	_resultat.sobrenom = _usuari.obteSobrenom();
	_resultat.correuElectronic = _usuari.obteCorreuElectronic();
	_resultat.dataNaixement = _usuari.obteDataNaixement();
}

DTOUsuari TxConsultaUsuari::obteResultat() {
	return _resultat;
}

PasarellaUsuari TxConsultaUsuari::obteUsuari() {
	return _usuari;
}
