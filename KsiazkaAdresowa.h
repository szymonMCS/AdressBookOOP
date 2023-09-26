#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include <windows.h>

class KsiazkaAdresowa {

    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    std::vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(std::string login);
    std::string wczytajLinie();

public:

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();


};
