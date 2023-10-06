#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenadzer.h"
#include "MetodyPomocnicze.h"

class KsiazkaAdresowa {

    UzytkownikMenadzer uzytkownikMenadzer;
    //AdresatMenadzer adresatMenadzer;

public:

    KsiazkaAdresowa(std::string nazwaPlikuZUzytkownikami) : uzytkownikMenadzer(nazwaPlikuZUzytkownikami){
        uzytkownikMenadzer.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();

    void dodajAdresata();

};

#endif // KSIAZKAADRESOWA_H
