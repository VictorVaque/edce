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
//---------------------------Gest. Sessió i Usuaris--------------------------------------------

void CapaDePresentacio::ConsultarUsuari() const {
	try {
		TxConsultaUsuari tx;
		tx.executar();
		auto usuario = tx.obteResultat();

		std::cout << "** Consulta Usuari **\n";
		std::cout << "Nom complet: " << usuario.nom << "\n";
		std::cout << "Sobrenom: " << usuario.sobrenom << "\n";
		std::cout << "Correu electrònic: " << usuario.correuElectronic << "\n";
		std::cout << "Data naixement: " << usuario.dataNaixement << "\n";
		std::cout << "Modalitat subscripció: " << usuario.modalitatSubscripcio << "\n";
		std::cout << "Pel·lícules visualitzades: " << usuario.numVisualitzacionsPel·lícules << "\n";
		std::cout << "Capítols visualitzats: " << usuario.numVisualitzacionsCapítols << "\n";
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
		std::cout << "Informació actual:\n";
		std::cout << "Nom complet: " << usuario.nom << "\n";
		std::cout << "Correu electrònic: " << usuario.correuElectronic << "\n";
		std::cout << "Data naixement: " << usuario.dataNaixement << "\n";
		std::cout << "Modalitat subscripció: " << usuario.modalitatSubscripcio << "\n";

		std::string nomNou, correuNou, dataNou, modalitatNova;
		std::cout << "Introdueix el nou nom complet (deixa buit per mantenir): ";
		std::getline(std::cin, nomNou);
		std::cout << "Introdueix el nou correu electrònic: ";
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

	// Solicitar la contraseña al usuario
	std::cout << "Per confirmar l'esborrat, introdueix la contrasenya: ";
	std::cin >> contrasenya;

	try {
		// Crear y ejecutar la transacción
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
	std::cout << "** Iniciar Sessió **" << std::endl;

	// Solicitar sobrenom y contrasenya
	std::cout << "Sobrenom: ";
	std::cin >> sobrenomU;
	std::cout << "Contrasenya: ";
	std::cin >> contrasenyaU;

	try {
		// Crear y ejecutar la transacción
		TxIniciSessio tx(sobrenomU, contrasenyaU);
		tx.executar();

		std::cout << "Sessió iniciada correctament!" << std::endl;
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

	std::cout << "Correu electrònic: ";
	std::getline(std::cin, correuU);

	std::cout << "Data de naixement (DD/MM/AAAA): ";
	std::getline(std::cin, dataNaixement);

	std::cout << "Modalitats disponibles:\n";
	std::cout << "1. Completa\n";
	std::cout << "2. Cinèfil\n";
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
	std::cout << "** Tancar Sessió **" << std::endl;
	std::cout << "Vols tancar la sessió (S/N): ";
	std::cin >> instruccio;

	if (instruccio == "S" || instruccio == "s") {
		try {
			TxTancaSessio tx;
			tx.executar();
			std::cout << "Sessió tancada correctament!" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	else {
		std::cout << "Operació cancel·lada." << std::endl;
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

	std::cout << "Correu electrònic: ";
	std::getline(std::cin, correuU);

	std::cout << "Data de naixement (DD/MM/AAAA): ";
	std::getline(std::cin, dataNaixement);

	std::cout << "Modalitats disponibles:\n";
	std::cout << "1. Completa\n";
	std::cout << "2. Cinèfil\n";
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



//---------------------------Visualització continguts-----------------------------------------

void CapaDePresentacio::VisualitPeli() {
	std::string titolPelicula;
	std::cout << "** Visualitzar Pel·lícula **" << std::endl;

	// Solicitar el título de la película
	std::cout << "Introduïu el títol de la pel·lícula: ";
	std::cin.ignore();
	std::getline(std::cin, titolPelicula);

	try {
		// Crear y ejecutar la transacción
		TxVisualitzarPel tx(titolPelicula);
		tx.executar();

		// Mostrar información de la película
		std::cout << "\nDetalls de la pel·lícula:\n";
		std::cout << " - Títol: " << tx.getNom() << "\n";
		std::cout << " - Descripció: " << tx.getDescripcio() << "\n";
		std::cout << " - Qualificació: " << tx.getQualificacio() << "\n";
		std::cout << " - Data d'estrena: " << tx.getData() << "\n";
		std::cout << " - Duració (minuts): " << tx.getDuracio() << "\n";

		// Confirmar visualización
		char opcio;
		std::cout << "Voleu confirmar la visualització? (S/N): ";
		std::cin >> opcio;

		if (opcio == 'S' || opcio == 's') {
			std::cout << "Pel·lícula visualitzada amb èxit!" << std::endl;
		}
		else {
			std::cout << "Visualització cancel·lada." << std::endl;
		}
	}
	catch (const std::exception& e) {
		// Manejar errores y mostrar el mensaje
		std::cout << "Error: " << e.what() << std::endl;
	}
}

// Visualizar un capítulo con validación de temporadas
void CapaDePresentacio::VisualitCapi() {
	std::string nomSerie;
	int numTemporada, numCapitol;

	std::cout << "** Visualitzar Capítol de Sèrie **" << std::endl;

	// Solicitar el nombre de la serie
	std::cout << "Introduïu el nom de la sèrie: ";
	std::cin.ignore();
	std::getline(std::cin, nomSerie);

	// Solicitar el número de la temporada
	std::cout << "Introduïu el número de la temporada: ";
	std::cin >> numTemporada;

	// Solicitar el número del capítol
	std::cout << "Introduïu el número del capítol: ";
	std::cin >> numCapitol;

	try {
		// Crear y ejecutar la transacción
		TxVisualitzarCapitol tx(nomSerie, numTemporada);
		tx.executar();

		// Mostrar información del capítulo
		std::cout << "\nDetalls del capítol:\n";
		std::cout << " - Sèrie: " << tx.getNomSerie() << "\n";
		std::cout << " - Temporada: " << tx.getNumTemporada() << "\n";
		//std::cout << " - Capítol: " << tx.getNumCapitol() << "\n";
		//std::cout << " - Títol: " << tx.getTitolCapitol() << "\n";
		//std::cout << " - Qualificació: " << tx.getQualificacio() << "\n";
		//std::cout << " - Data d'estrena: " << tx.getDataEstrena().toString() << "\n";

		// Confirmar visualización
		char opcio;
		std::cout << "Voleu confirmar la visualització? (S/N): ";
		std::cin >> opcio;

		if (opcio == 'S' || opcio == 's') {
			std::cout << "Capítol visualitzat amb èxit!" << std::endl;
		}
		else {
			std::cout << "Visualització cancel·lada." << std::endl;
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

		auto pelicules = tx.getVisualitzacionsPel·lícules();
		auto capitols = tx.getVisualitzacionsCapítols();

		std::cout << "** Visualitzacions **\n";

		// Imprimir visualitzacions de pel·lícules
		std::cout << "Pel·lícules:\n";
		for (const auto& peli : pelicules) {
			std::cout << " - Títol: " << peli.obteNomPelicula() << "\n";
			//std::cout << "   Descripció: " << peli.descripcio << "\n";
			//std::cout << "   Qualificació: " << peli.qualificacioEdat << "\n";
			std::cout << "   Data: " << peli.obteDataVisualitzacio() << "\n";
			std::cout << "   Vegades visualitzades: " << peli.obteNumVisualitzacions() << "\n\n";
		}

		// Imprimir visualitzacions de capítols
		std::cout << "Capítols de sèries:\n";
		for (const auto& cap : capitols) {
			std::cout << " - Sèrie: " << cap.obteNomSerie() << "\n";
			std::cout << "   Temporada: " << cap.obteNumTemporada() << ", Capítol: " << cap.obteNumCapitol() << "\n";
			//std::cout << "   Qualificació: " << cap.qualificacioEdat << "\n";
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
		std::cout << "Introdueix la modalitat de subscripció: ";
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
		std::cout << "** Consulta Últimes Novetats **" << std::endl;

		// Solicitar la modalitat del usuario
		std::cout << "Introdueix la modalitat de subscripció: ";
		std::cin >> modalitat;

		TxConsultaUltimesNovetats tx(modalitat);

		std::string novetats = tx.consultaUltimesNovetats();
		std::cout << "Últimes novetats:\n" << novetats << "\n";
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << "\n";
	}
}

void CapaDePresentacio::PelisMesVistes() const {
	try {
		std::cout << "** Consulta Pel·lícules Més Vistes **" << std::endl;

		TxConsultarPeliculesMesVistes tx;

		std::string pelicules = tx.consultarPeliculesMesVistes();
		std::cout << "Pel·lícules més vistes:\n" << pelicules << "\n";
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << "\n";
	}
}