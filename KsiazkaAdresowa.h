#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenadzer.h"
#include "MetodyPomocnicze.h"

class KsiazkaAdresowa {

    UzytkownikMenadzer uzytkownikMenadzer;
public:

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

};

#endif // KSIAZKAADRESOWA_H
