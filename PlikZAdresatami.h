#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "PlikTekstowy.h"
#include "Adresat.h"
#include "MetodyPomocnicze.h"

class PlikZAdresatami : public PlikTekstowy{
    const std::string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;

    bool czyPlikJestPusty();
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(std::string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(std::string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(std::string daneAdresataOddzielonePionowymiKreskami);
    std::string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void usunPlik(std::string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(std::string staraNazwa, std::string nowaNazwa);
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata);
    int pobierzZPlikuIdOstatniegoAdresata();

public:
    PlikZAdresatami(std::string nazwaPlikuZAdresatami, std::string nazwaTymczasowegoPlikuZAdresatami)
    : PlikTekstowy(nazwaPlikuZAdresatami), NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI(nazwaTymczasowegoPlikuZAdresatami){
        idOstatniegoAdresata = 0;
    };
    std::vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanego);
    bool dopiszAdresataDoPliku(Adresat adresat);
    int usunWybranegoAdresataZPlikuTekstowego (int idAdresata);
    int pobierzIdOstatniegoAdresata();
};

#endif // PLIKZADRESATAMI
