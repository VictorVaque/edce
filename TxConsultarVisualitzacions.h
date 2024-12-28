#ifndef TXCONSULTARVISUALITZACIONS_H
#define TXCONSULTARVISUALITZACIONS_H

#include <vector>
#include <string>
#include "PasarellaVisualitzaPel.h"
#include "PasarellaVisualitzaCapitol.h"
#include "CercadoraVisualitzaCapitol.h"

// Estructura per representar una visualització de pel·lícula
struct VisualitzacioPelicula {
    std::string dataVisualitzacio;
    std::string titol;
    std::string descripcio;
    std::string qualificacioEdat;
    int numVisualitzacions;
};

// Estructura per representar una visualització de capítol
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
    std::vector<PasarellaVisualitzaPel> visualitzacionsPel·lícules;
    std::vector<PasarellaVisualitzaCapitol> visualitzacionsCapítols;

public:
    TxConsultarVisualitzacions();
    ~TxConsultarVisualitzacions();

    void executar(const std::string& sobrenomUsuari);
    const std::vector<PasarellaVisualitzaPel>& getVisualitzacionsPel·lícules() const;
    const std::vector<PasarellaVisualitzaCapitol>& getVisualitzacionsCapítols() const;
};

#endif // TXCONSULTARVISUALITZACIONS_H

