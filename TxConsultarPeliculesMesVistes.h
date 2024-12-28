#include "PasarellaPel.h"
#include "CercadoraPel.h"
#include "PasarellaVisualitzaPel.h"
#include "CercadoraVisualitzaPel.h"
using namespace std;

class TxConsultarPeliculesMesVistes{
	private:
		vector<PasarellaPel> pelicules;
		string sobrenom;

		void cerca_pelicules();
	public:
		TxConsultarPeliculesMesVistes();
		~TxConsultarPeliculesMesVistes();

		string consultarPeliculesMesVistes();
};