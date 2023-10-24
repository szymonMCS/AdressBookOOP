#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

class MetodyPomocnicze{

public:
    static std::string konwersjaIntNaString(int liczba);
    static int konwersjaStringNaInt(std::string liczba);
    static std::string wczytajLinie();
    static std::string zamienPierwszaLitereNaDuzaAPozostaleNaMale(std::string tekst);
    static char wczytajZnak();
    static std::string pobierzLiczbe(std::string tekst, int pozycjaZnaku);
    static int wczytajLiczbeCalkowita();
};

#endif // METODYPOMOCNICZE_H
