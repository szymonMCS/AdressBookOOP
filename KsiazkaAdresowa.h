#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenadzer.h"
#include "AdresatMenadzer.h"
#include "MetodyPomocnicze.h"

class KsiazkaAdresowa {
    UzytkownikMenadzer uzytkownikMenadzer;
    AdresatMenadzer *adresatMenadzer;
    const std::string NAZWA_PLIKU;
    const std::string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI;

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wylogujUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void usunAdresata();
    void edytujAdresata();

public:
    KsiazkaAdresowa(std::string nazwaPlikuZUzytkownikami, std::string nazwaPlikuZAdresatami, std::string nazwaTymczasowegoPlikuZAdresatami)
     : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU(nazwaPlikuZAdresatami), NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI(nazwaTymczasowegoPlikuZAdresatami)
     {
         adresatMenadzer = NULL;
     };
     ~KsiazkaAdresowa()
     {
         delete adresatMenadzer;
         adresatMenadzer = NULL;
     };

     void menu();
};

#endif // KSIAZKAADRESOWA_H
