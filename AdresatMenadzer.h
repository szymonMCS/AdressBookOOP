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


    int idZalogowanegoUzytkownika;
    std::vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;


    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(int input);

public:

    AdresatMenadzer(std::string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {

    };
    //SETTERY
    void ustawIdZalogowanegoUzytkownika(int id);
    //GETTERY
    int pobierzIdZalogowanegoUzytkownika();
    //METODY
    void pobierzAdresatowZalogowanegoUzytkownikaZPliku();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wyczyscWektor();

};

#endif // ADRESATMENADZER
