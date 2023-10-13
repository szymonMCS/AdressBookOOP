#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

class PlikZAdresatami{

    const std::string nazwaPlikuZAdresatami;
    int idOstatniegoAdresata;

    bool czyPlikJestPusty();
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(std::string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(std::string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(std::string daneAdresataOddzielonePionowymiKreskami);
    std::string pobierzLiczbe(std::string tekst, int pozycjaZnaku);
    std::string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

public:

    //METODY
    PlikZAdresatami(std::string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {
        idOstatniegoAdresata = 0;
    };
    std::vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanego);
    void dopiszAdresataDoPliku(Adresat adresat);
    //GETTERY
    int pobierzIdOstatniegoAdresata();
    void ustawIdOstatniegoAdresata(int input);

};

#endif // PLIKZADRESATAMI
