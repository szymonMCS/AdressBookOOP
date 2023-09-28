#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenadzer.h"
#include "MetodyPomocnicze.h"

class KsiazkaAdresowa {

    UzytkownikMenadzer uzytkownikMenadzer;
public:
    KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

};

#endif // KSIAZKAADRESOWA_H
