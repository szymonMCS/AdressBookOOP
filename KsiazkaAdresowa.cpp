#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika(){

    uzytkownikMenadzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata() {
    adresatMenadzer.dodajAdresata();
}

int KsiazkaAdresowa::logowanieUzytkownika(){

    uzytkownikMenadzer.logowanieUzytkownika();
    adresatMenadzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
    adresatMenadzer.pobierzAdresatowZalogowanegoUzytkownikaZPliku();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){

    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    std::vector<Adresat>& wektorAdresatow = adresatMenadzer.pobierzWektorAdresatow();
    uzytkownikMenadzer.wylogujUzytkownika(wektorAdresatow);
}


void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){

    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}


void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresatMenadzer.wyswietlWszystkichAdresatow();
}


