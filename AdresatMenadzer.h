#ifndef ADRESATMENADZER.H
#define ADRESATMENADZER.H

#include <vector>
#include <windows.h>
#include <sstream>
#include <fstream>


#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"


class AdresatMenadzer {


    int idZalogowanegoUzytkownika;
    std::vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    std::vector<Adresat> wektorAdresatow;


    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(int input);

public:

    AdresatMenadzer(std::string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};

    //SETTERY
    void ustawIdZalogowanegoUzytkownika(int idZalogowanego);
    //GETTERY
    int pobierzIdZalogowanegoUzytkownika();
    //METODY
    void pobierzAdresatowZalogowanegoUzytkownikaZPliku();
    int dodajAdresata();
    void wyswietlWszystkichAdresatow();
    std::vector<Adresat>& pobierzWektorAdresatow();

};

#endif // ADRESATMENADZER
