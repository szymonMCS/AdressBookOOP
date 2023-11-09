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
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();

public:
    KsiazkaAdresowa(std::string nazwaPlikuZUzytkownikami, std::string nazwaPlikuZAdresatami)
     : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU(nazwaPlikuZAdresatami)
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
