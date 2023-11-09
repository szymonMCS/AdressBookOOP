#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>

class PlikTekstowy{

const std::string NAZWA_PLIKU;

protected:
    PlikTekstowy(std::string nazwaPliku) : NAZWA_PLIKU(nazwaPliku){};
    bool czyPlikJestPusty();
    std::string pobierzNazwePliku();

};

#endif // PLIKTEKSTOWY_H
