#pragma once
#include "PasarellaUsuari.h"
#include"Conexio.h"

class CercadoraUsuari
{
public:
	CercadoraUsuari() {};
	PasarellaUsuari cercaUsuari(std::string sobrenomU); //excepcio:UsuariNoExisteix
};