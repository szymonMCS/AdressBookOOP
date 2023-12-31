#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "PlikTekstowy.h"
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

class PlikZUzytkownikami : public PlikTekstowy{

    std::string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(std::string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:

    PlikZUzytkownikami(std::string nazwaPlikuZUzytkownikami) : PlikTekstowy(nazwaPlikuZUzytkownikami) {};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    std::vector <Uzytkownik>  wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(std::vector<Uzytkownik>& uzytkownicy);
};

#endif // PLIKZUZYTKOWNIKAMI_H
