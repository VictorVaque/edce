#ifndef PASARELLASERIE_H
#define PASARELLASERIE_H

#include <string>
#include <vector>

class PasarellaSerie {
private:
    // Atributs
    std::string _nom;
    int _numTemporades;
    std::string _modalitat;
    std::string _data;
    std::string _qualificacio;
    std::vector<int> _numCapitolsPerTemporada;

public:
    // Constructors
    PasarellaSerie();
    PasarellaSerie(const std::string& nom, int numTemporades, const std::vector<int>& numCapitolsPerTemporada);

    // Getters
    std::string obteData() const;
    std::string obteQualificacio() const;
    std::string obteMod() const;
    std::string obteNom() const;
    int obteNumTemp() const;
    int obteNumCap(int numTemporada) const;

    // Setters
    void posaNom(const std::string& nom);
    void posaNumTemp(int numTemporades);
    void posaNumCapPerTemp(const std::vector<int>& numCapitolsPerTemporada);
};

#endif // PASARELLASERIE_H
