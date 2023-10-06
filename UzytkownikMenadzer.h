#ifndef UZYTKOWNIKMENADZER_H
#define UZYTKOWNIKMENADZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <fstream>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikZUzytkownikami.h"

class UzytkownikMenadzer{

    int idZalogowanegoUzytkownika;
    std::vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(std::string login);
    PlikZUzytkownikami plikZUzytkownikami;


public:

    UzytkownikMenadzer(std::string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {};
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    Uzytkownik pobierzDaneUzytkownika(std::string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();

    void ustawIdZalogowanegoUzytkownika(int idZalogowanego);
    int pobierzIdZalogowanegoUzytkownika();

};

#endif // UZYTKOWNIKMENADZER_H
