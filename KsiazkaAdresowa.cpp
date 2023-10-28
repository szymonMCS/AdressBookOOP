#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenadzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata() {
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer -> dodajAdresata();
    }
    else{
        std::cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << std::endl;
        system("pause");
    }
}

void KsiazkaAdresowa::usunAdresata() {
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer -> usunAdresata();
    }
    else{
        std::cout << "Aby usunac adresata, nalezy najpierw sie zalogowac" << std::endl;
        system("pause");
    }
}

void KsiazkaAdresowa::edytujAdresata() {
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer -> edytujAdresata();
    }
    else{
        std::cout << "Aby edytowac adresata, nalezy najpierw sie zalogowac" << std::endl;
        system("pause");
    }
}

void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMenadzer.logowanieUzytkownika();
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer = new AdresatMenadzer(NAZWA_PLIKU, NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    uzytkownikMenadzer.wylogujUzytkownika();
    delete adresatMenadzer;
    adresatMenadzer = NULL;
}


void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}


void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer -> wyswietlWszystkichAdresatow();
    }
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu(){
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer -> wyszukajAdresatowPoImieniu();
    }
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku(){
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer -> wyszukajAdresatowPoNazwisku();
    }
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany(){
    return uzytkownikMenadzer.czyUzytkownikJestZalogowany();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    std::cout << "    >>> MENU  GLOWNE <<<" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "1. Rejestracja" << std::endl;
    std::cout << "2. Logowanie" << std::endl;
    std::cout << "9. Koniec programu" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    std::cout << " >>> MENU UZYTKOWNIKA <<<" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "1. Dodaj adresata" << std::endl;
    std::cout << "2. Wyszukaj po imieniu" << std::endl;
    std::cout << "3. Wyszukaj po nazwisku" << std::endl;
    std::cout << "4. Wyswietl adresatow" << std::endl;
    std::cout << "5. Usun adresata" << std::endl;
    std::cout << "6. Edytuj adresata" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "7. Zmien haslo" << std::endl;
    std::cout << "8. Wyloguj sie" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void KsiazkaAdresowa::menu(){

    char wybor;

    while (true)
    {
        if (!czyUzytkownikJestZalogowany())
        {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                rejestracjaUzytkownika();
                break;
            case '2':
                logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                std::cout << std::endl << "Nie ma takiej opcji w menu." << std::endl << std::endl;
                system("pause");
                break;
            }
        }
        else
        {
            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                dodajAdresata();
                break;
            case '2':
                wyszukajAdresatowPoImieniu();
                break;
            case '3':
                wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                wyswietlWszystkichAdresatow();
                break;
            case '5':
                usunAdresata();
                break;
            case '6':
                edytujAdresata();
                break;
            case '7':
                zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                wylogujUzytkownika();
                break;
            }
        }
    }
}

