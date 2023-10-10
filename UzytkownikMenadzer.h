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
#include "AdresatMenadzer.h"

class UzytkownikMenadzer{

    int idZalogowanegoUzytkownika;
    std::vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(std::string login);


public:

    UzytkownikMenadzer(std::string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {};
    //SETTERY
    void ustawIdZalogowanegoUzytkownika(int idZalogowanego);
    //GETTERY
    int pobierzIdZalogowanegoUzytkownika();
    //METODY
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika(std::vector<Adresat>& adresaci);

};

#endif // UZYTKOWNIKMENADZER_H
