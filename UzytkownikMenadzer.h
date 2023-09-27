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

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};

#endif // UZYTKOWNIKMENADZER_H
