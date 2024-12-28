#ifndef TXCONSULTARVISUALITZACIONS_H
#define TXCONSULTARVISUALITZACIONS_H

#include <vector>
#include <string>
#include "PasarellaVisualitzaPel.h"
#include "PasarellaVisualitzaCapitol.h"
#include "CercadoraVisualitzaCapitol.h"

// Estructura per representar una visualitzaci� de pel�l�cula
struct VisualitzacioPelicula {
    std::string dataVisualitzacio;
    std::string titol;
    std::string descripcio;
    std::string qualificacioEdat;
    int numVisualitzacions;
};

// Estructura per representar una visualitzaci� de cap�tol
struct VisualitzacioCapitol {
    std::string dataVisualitzacio;
    std::string titolSerie;
    int numTemporada;
    int numCapitol;
    std::string qualificacioEdat;
    int numVisualitzacions;
};

class TxConsultarVisualitzacions {
private:
    std::vector<PasarellaVisualitzaPel> visualitzacionsPel�l�cules;
    std::vector<PasarellaVisualitzaCapitol> visualitzacionsCap�tols;

public:
    TxConsultarVisualitzacions();
    ~TxConsultarVisualitzacions();

    void executar(const std::string& sobrenomUsuari);
    const std::vector<PasarellaVisualitzaPel>& getVisualitzacionsPel�l�cules() const;
    const std::vector<PasarellaVisualitzaCapitol>& getVisualitzacionsCap�tols() const;
};

#endif // TXCONSULTARVISUALITZACIONS_H

