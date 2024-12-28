#pragma once
#include "DTOUsuari.h"
#include "TxConsultaUsuari.h"
#include "PasarellaUsuari.h"
#include"PetitFlix.h"
class CtrModificaUsuari
{
public:
	CtrModificaUsuari() {}
	DTOUsuari consultaUsuari();
	void modificaUsuari(std::string nomU, std::string contraU, std::string correuU, std::string neixU);
private:
	PasarellaUsuari _usuari;
};
