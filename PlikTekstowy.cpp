#include "PlikTekstowy.h"

bool PlikTekstowy::czyPlikJestPusty(){
    bool pusty = true;
    std::fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), std::ios::in);

    if (plikTekstowy.good() == true)
    {
        plikTekstowy.seekg(0, std::ios::end);
        if (plikTekstowy.tellg() != 0)
            pusty = false;
    }
    plikTekstowy.close();
    return pusty;
}

std::string PlikTekstowy::pobierzNazwePliku(){
    return NAZWA_PLIKU;
}
