#ifndef ADRESATMENADZER_H
#define ADRESATMENADZER_H

#include <vector>
#include <windows.h>
#include <sstream>
#include <fstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMenadzer.h"


class AdresatMenadzer {
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    std::vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(int input);

public:
    AdresatMenadzer(std::string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
     : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
};

#endif // ADRESATMENADZER
