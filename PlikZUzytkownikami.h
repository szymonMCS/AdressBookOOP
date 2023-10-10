#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

class PlikZUzytkownikami{

    const std::string nazwaPlikuZUzytkownikami;

    bool czyPlikJestPusty();
    std::string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(std::string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:

    PlikZUzytkownikami(std::string NAZWAPLIKUZUZYTKOWNIKAMI) : nazwaPlikuZUzytkownikami(NAZWAPLIKUZUZYTKOWNIKAMI) {};
    //METODY
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    std::vector <Uzytkownik>  wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(std::vector<Uzytkownik>& uzytkownicy);
};

#endif // PLIKZUZYTKOWNIKAMI_H
