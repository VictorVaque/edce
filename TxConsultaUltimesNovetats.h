#include <vector>
#include "PasarellaPel.h"
#include "CercadoraPel.h"
#include "PasarellaSerie.h"
#include "CercadoraSerie.h"
#include "PasarellaCapitol.h"
#include "CercadoraCapitol.h"
#include "PetitFlix.h"
using namespace std;

class TxConsultaUltimesNovetats{
    private:  
        string modalitat;
        vector<PasarellaPel> pelicules;
        vector<PasarellaSerie> series;
        
        void cercarUltimesNovetats();
    public:
        TxConsultaUltimesNovetats(string);
	    ~TxConsultaUltimesNovetats();

        
        string consultaUltimesNovetats();
};
