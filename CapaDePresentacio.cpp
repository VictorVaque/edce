#include "CapaDePresentacio.h"
#include "TxConsultaUsuari.h"
#include "CtrModificarUsuari.h"
#include "TxConsultarVisualitzacions.h"
#include "TxRegistraUsuari.h"
#include "TxTancaSessio.h"
#include "TxIniciSessio.h"
#include "TxEsborrarUsuari.h"
#include "TxVisualitzarPel.h"
#include "TxVisualitzarCapitol.h"
#include "TxConsultaUltimesNovetats.h"
#include "TxConsultaProperesEstrenes.h"
#include "TxConsultarPeliculesMesVistes.h"
#include <locale>
//---------------------------Gest. Sessi� i Usuaris--------------------------------------------

void CapaDePresentacio::ConsultarUsuari() const {
	try {
		TxConsultaUsuari tx;
		tx.executar();
		auto usuario = tx.obteResultat();

		std::cout << "** Consulta Usuari **\n";
		std::cout << "Nom complet: " << usuario.nom << "\n";
		std::cout << "Sobrenom: " << usuario.sobrenom << "\n";
		std::cout << "Correu electr�nic: " << usuario.correuElectronic << "\n";
		std::cout << "Data naixement: " << usuario.dataNaixement << "\n";
		std::cout << "Modalitat subscripci�: " << usuario.modalitatSubscripcio << "\n";
		std::cout << "Pel�l�cules visualitzades: " << usuario.numVisualitzacionsPel�l�cules << "\n";
		std::cout << "Cap�tols visualitzats: " << usuario.numVisualitzacionsCap�tols << "\n";
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << "\n";
	}
}

void CapaDePresentacio::ModificarUsuari() {
	try {
		TxConsultaUsuari txConsulta;
		txConsulta.executar();
		auto usuario = txConsulta.obteResultat();

		std::cout << "** Modificar Usuari **\n";
		std::cout << "Informaci� actual:\n";
		std::cout << "Nom complet: " << usuario.nom << "\n";
		std::cout << "Correu electr�nic: " << usuario.correuElectronic << "\n";
		std::cout << "Data naixement: " << usuario.dataNaixement << "\n";
		std::cout << "Modalitat subscripci�: " << usuario.modalitatSubscripcio << "\n";

		std::string nomNou, correuNou, dataNou, modalitatNova;
		std::cout << "Introdueix el nou nom complet (deixa buit per mantenir): ";
		std::getline(std::cin, nomNou);
		std::cout << "Introdueix el nou correu electr�nic: ";
		std::getline(std::cin, correuNou);
		std::cout << "Introdueix la nova data de naixement (deixa buit per mantenir): ";
		std::getline(std::cin, dataNou);
		std::cout << "Introdueix la nova modalitat: ";
		std::getline(std::cin, modalitatNova);

		CtrModificaUsuari txModificar;
		txModificar.modificaUsuari(nomNou, correuNou, dataNou, modalitatNova);

		std::cout << "Usuari modificat correctament.\n";
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << "\n";
	}
}

void CapaDePresentacio::EsborraUsuari() {
	std::string contrasenya;
	std::cout << "** Esborrar Usuari **" << std::endl;

	// Solicitar la contrase�a al usuario
	std::cout << "Per confirmar l'esborrat, introdueix la contrasenya: ";
	std::cin >> contrasenya;

	try {
		// Crear y ejecutar la transacci�n
		TxEsborrarUsuari tx(contrasenya);
		tx.executar();

		std::cout << "Usuari esborrat correctament!" << std::endl;
	}
	catch (const std::exception& e) {
		// Manejar errores y mostrar el mensaje
		std::cout << "Error: " << e.what() << std::endl;
	}
}

/*Pre:*/
/*Post:*/
void CapaDePresentacio::IniciSessio() {
	std::string sobrenomU, contrasenyaU;
	std::cout << "** Iniciar Sessi� **" << std::endl;

	// Solicitar sobrenom y contrasenya
	std::cout << "Sobrenom: ";
	std::cin >> sobrenomU;
	std::cout << "Contrasenya: ";
	std::cin >> contrasenyaU;

	try {
		// Crear y ejecutar la transacci�n
		TxIniciSessio tx(sobrenomU, contrasenyaU);
		tx.executar();

		std::cout << "Sessi� iniciada correctament!" << std::endl;
	}
	catch (const std::exception& e) {
		// Manejar errores y mostrar el mensaje
		std::cout << "Error: " << e.what() << std::endl;
	}



	std::string correuU, nomComplet, contrasenya, modalitat, dataNaixement;
	std::cout << "** Registre Usuari **" << std::endl;

	std::cout << "Nom complet: ";
	std::cin.ignore();
	std::getline(std::cin, nomComplet);

	std::cout << "Sobrenom: ";
	std::getline(std::cin, sobrenomU);

	std::cout << "Contrasenya: ";
	std::getline(std::cin, contrasenya);

	std::cout << "Correu electr�nic: ";
	std::getline(std::cin, correuU);

	std::cout << "Data de naixement (DD/MM/AAAA): ";
	std::getline(std::cin, dataNaixement);

	std::cout << "Modalitats disponibles:\n";
	std::cout << "1. Completa\n";
	std::cout << "2. Cin�fil\n";
	std::cout << "3. Infantil\n";
	std::cout << "Escull modalitat: ";
	std::getline(std::cin, modalitat);

	// Convertir la data a un objecte `Data`
	string dataNaixamentU = dataNaixement;
	try {
		TxRegistraUsuari tx(nomComplet, sobrenomU, contrasenya, correuU, dataNaixamentU, modalitat);
		tx.executa();
		std::cout << "Usuari registrat correctament!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void CapaDePresentacio::TencaSessio() {
	std::string instruccio;
	std::cout << "** Tancar Sessi� **" << std::endl;
	std::cout << "Vols tancar la sessi� (S/N): ";
	std::cin >> instruccio;

	if (instruccio == "S" || instruccio == "s") {
		try {
			TxTancaSessio tx;
			tx.executar();
			std::cout << "Sessi� tancada correctament!" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	else {
		std::cout << "Operaci� cancel�lada." << std::endl;
	}
}



void CapaDePresentacio::RegistreUsuari() const {
	std::string sobrenomU, correuU, nomComplet, contrasenya, modalitat, dataNaixement;
	std::cout << "** Registre Usuari **" << std::endl;

	std::cout << "Nom complet: ";
	std::cin.ignore();
	std::getline(std::cin, nomComplet);

	std::cout << "Sobrenom: ";
	std::getline(std::cin, sobrenomU);

	std::cout << "Contrasenya: ";
	std::getline(std::cin, contrasenya);

	std::cout << "Correu electr�nic: ";
	std::getline(std::cin, correuU);

	std::cout << "Data de naixement (DD/MM/AAAA): ";
	std::getline(std::cin, dataNaixement);

	std::cout << "Modalitats disponibles:\n";
	std::cout << "1. Completa\n";
	std::cout << "2. Cin�fil\n";
	std::cout << "3. Infantil\n";
	std::cout << "Escull modalitat: ";
	std::getline(std::cin, modalitat);

	// Convertir la data a un objecte `Data`

	try {
		TxRegistraUsuari tx(nomComplet, sobrenomU, contrasenya, correuU, dataNaixement, modalitat);
		tx.executa();
		std::cout << "Usuari registrat correctament!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

//--------------------------------------------------------------------------------------------



//---------------------------Visualitzaci� continguts-----------------------------------------

void CapaDePresentacio::VisualitPeli() {
	std::string titolPelicula;
	std::cout << "** Visualitzar Pel�l�cula **" << std::endl;

	// Solicitar el t�tulo de la pel�cula
	std::cout << "Introdu�u el t�tol de la pel�l�cula: ";
	std::cin.ignore();
	std::getline(std::cin, titolPelicula);

	try {
		// Crear y ejecutar la transacci�n
		TxVisualitzarPel tx(titolPelicula);
		tx.executar();

		// Mostrar informaci�n de la pel�cula
		std::cout << "\nDetalls de la pel�l�cula:\n";
		std::cout << " - T�tol: " << tx.getNom() << "\n";
		std::cout << " - Descripci�: " << tx.getDescripcio() << "\n";
		std::cout << " - Qualificaci�: " << tx.getQualificacio() << "\n";
		std::cout << " - Data d'estrena: " << tx.getData() << "\n";
		std::cout << " - Duraci� (minuts): " << tx.getDuracio() << "\n";

		// Confirmar visualizaci�n
		char opcio;
		std::cout << "Voleu confirmar la visualitzaci�? (S/N): ";
		std::cin >> opcio;

		if (opcio == 'S' || opcio == 's') {
			std::cout << "Pel�l�cula visualitzada amb �xit!" << std::endl;
		}
		else {
			std::cout << "Visualitzaci� cancel�lada." << std::endl;
		}
	}
	catch (const std::exception& e) {
		// Manejar errores y mostrar el mensaje
		std::cout << "Error: " << e.what() << std::endl;
	}
}

// Visualizar un cap�tulo con validaci�n de temporadas
void CapaDePresentacio::VisualitCapi() {
	std::string nomSerie;
	int numTemporada, numCapitol;

	std::cout << "** Visualitzar Cap�tol de S�rie **" << std::endl;

	// Solicitar el nombre de la serie
	std::cout << "Introdu�u el nom de la s�rie: ";
	std::cin.ignore();
	std::getline(std::cin, nomSerie);

	// Solicitar el n�mero de la temporada
	std::cout << "Introdu�u el n�mero de la temporada: ";
	std::cin >> numTemporada;

	// Solicitar el n�mero del cap�tol
	std::cout << "Introdu�u el n�mero del cap�tol: ";
	std::cin >> numCapitol;

	try {
		// Crear y ejecutar la transacci�n
		TxVisualitzarCapitol tx(nomSerie, numTemporada);
		tx.executar();

		// Mostrar informaci�n del cap�tulo
		std::cout << "\nDetalls del cap�tol:\n";
		std::cout << " - S�rie: " << tx.getNomSerie() << "\n";
		std::cout << " - Temporada: " << tx.getNumTemporada() << "\n";
		//std::cout << " - Cap�tol: " << tx.getNumCapitol() << "\n";
		//std::cout << " - T�tol: " << tx.getTitolCapitol() << "\n";
		//std::cout << " - Qualificaci�: " << tx.getQualificacio() << "\n";
		//std::cout << " - Data d'estrena: " << tx.getDataEstrena().toString() << "\n";

		// Confirmar visualizaci�n
		char opcio;
		std::cout << "Voleu confirmar la visualitzaci�? (S/N): ";
		std::cin >> opcio;

		if (opcio == 'S' || opcio == 's') {
			std::cout << "Cap�tol visualitzat amb �xit!" << std::endl;
		}
		else {
			std::cout << "Visualitzaci� cancel�lada." << std::endl;
		}
	}
	catch (const std::exception& e) {
		// Manejar errores y mostrar el mensaje
		std::cout << "Error: " << e.what() << std::endl;
	}
}


void CapaDePresentacio::ConsultVisualit() const {
	try {
		TxConsultaUsuari txConsulta;
		txConsulta.executar();
		auto usuario = txConsulta.obteResultat();

		TxConsultarVisualitzacions tx;
		tx.executar(usuario.sobrenom);

		auto pelicules = tx.getVisualitzacionsPel�l�cules();
		auto capitols = tx.getVisualitzacionsCap�tols();

		std::cout << "** Visualitzacions **\n";

		// Imprimir visualitzacions de pel�l�cules
		std::cout << "Pel�l�cules:\n";
		for (const auto& peli : pelicules) {
			std::cout << " - T�tol: " << peli.obteNomPelicula() << "\n";
			//std::cout << "   Descripci�: " << peli.descripcio << "\n";
			//std::cout << "   Qualificaci�: " << peli.qualificacioEdat << "\n";
			std::cout << "   Data: " << peli.obteDataVisualitzacio() << "\n";
			std::cout << "   Vegades visualitzades: " << peli.obteNumVisualitzacions() << "\n\n";
		}

		// Imprimir visualitzacions de cap�tols
		std::cout << "Cap�tols de s�ries:\n";
		for (const auto& cap : capitols) {
			std::cout << " - S�rie: " << cap.obteNomSerie() << "\n";
			std::cout << "   Temporada: " << cap.obteNumTemporada() << ", Cap�tol: " << cap.obteNumCapitol() << "\n";
			//std::cout << "   Qualificaci�: " << cap.qualificacioEdat << "\n";
			std::cout << "   Data: " << cap.obteDataVisualitzacio() << "\n";
			std::cout << "   Vegades visualitzades: " << cap.obteNumVisualitzacions() << "\n\n";
		}
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << "\n";
	}
}




//--------------------------------------------------------------------------------------------

//---------------------------Consultes--------------------------------------------------------

void CapaDePresentacio::ProxEstrenes() const {
	try {
		std::string modalitat;
		std::cout << "** Consulta Properes Estrenes **" << std::endl;

		// Solicitar la modalitat del usuario
		std::cout << "Introdueix la modalitat de subscripci�: ";
		std::cin >> modalitat;

		TxConsultarProperesEstrenes tx(modalitat);

		std::string estrenes = tx.consultarProximasEstrenas();
		std::cout << "Properes estrenes:\n" << estrenes << "\n";
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << "\n";
	}
}

void CapaDePresentacio::UltNovetats() const {
	try {
		std::string modalitat;
		std::cout << "** Consulta �ltimes Novetats **" << std::endl;

		// Solicitar la modalitat del usuario
		std::cout << "Introdueix la modalitat de subscripci�: ";
		std::cin >> modalitat;

		TxConsultaUltimesNovetats tx(modalitat);

		std::string novetats = tx.consultaUltimesNovetats();
		std::cout << "�ltimes novetats:\n" << novetats << "\n";
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << "\n";
	}
}

void CapaDePresentacio::PelisMesVistes() const {
	try {
		std::cout << "** Consulta Pel�l�cules M�s Vistes **" << std::endl;

		TxConsultarPeliculesMesVistes tx;

		std::string pelicules = tx.consultarPeliculesMesVistes();
		std::cout << "Pel�l�cules m�s vistes:\n" << pelicules << "\n";
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << "\n";
	}
}