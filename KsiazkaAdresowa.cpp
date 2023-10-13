#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika(){

    uzytkownikMenadzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata() {
    adresatMenadzer.dodajAdresata();
}

void KsiazkaAdresowa::logowanieUzytkownika(){

    uzytkownikMenadzer.logowanieUzytkownika();
    adresatMenadzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
    adresatMenadzer.pobierzAdresatowZalogowanegoUzytkownikaZPliku();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){

    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika() {

    uzytkownikMenadzer.wylogujUzytkownika();
    adresatMenadzer.wyczyscWektor();
}


void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){

    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}


void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresatMenadzer.wyswietlWszystkichAdresatow();
}


