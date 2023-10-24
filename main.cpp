#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt", "Adresaci_temp.txt");
    ksiazkaAdresowa.menu();

    /*ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    ksiazkaAdresowa.logowanieUzytkownika();

    ksiazkaAdresowa.dodajAdresata();

    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    ksiazkaAdresowa.wylogujUzytkownika();*/

    return 0;
}




//TESTY AdresatMenadzer
#include "AdresatMenadzer.h"

int testyAdresata_main(){

    AdresatMenadzer adresatMenadzer("Adresaci.txt", "Adresaci_temp.txt", 2);
    adresatMenadzer.wyswietlWszystkichAdresatow();
    adresatMenadzer.dodajAdresata();
    adresatMenadzer.wyswietlWszystkichAdresatow();

    return 0;
}

//TESTY PlikZAdresatami
#include "Adresat.h"
#include "PlikZAdresatami.h"

int testyPlikuAdr_main(){
    PlikZAdresatami plikZAdresatami("Adresaci-test.txt", "Adresaci_temp.txt");
    Adresat adresat(1, 9, "Janek", "Twardowski", "999 888 333", "janek@o2.pl", "ul. Jankowa 3a");

    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    std::cout << plikZAdresatami.pobierzIdOstatniegoAdresata();

    return 0;
}
