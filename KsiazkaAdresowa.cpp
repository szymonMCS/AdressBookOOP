#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika(){

    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    //dopiszUzytkownikaDoPliku(uzytkownik);

    std::cout << std::endl << "Konto zalozono pomyslnie" << std::endl << std::endl;
    system("pause");
}

Uzytkownik KsiazkaAdresowa::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do
    {
        std::cout << "Podaj login: ";
        uzytkownik.ustawLogin(wczytajLinie());
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    std::cout << "Podaj haslo: ";
    uzytkownik.ustawHaslo(wczytajLinie());

    return uzytkownik;
}

int KsiazkaAdresowa::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool KsiazkaAdresowa::czyIstniejeLogin(std::string login)
{
    for (int i = 0; i < uzytkownicy.size(); i++){
        if (uzytkownicy[i].pobierzLogin() == login){
            std::cout << std::endl << "Istnieje uzytkownik o takim loginie." << std::endl;
            return true;
        }
    }
    return false;
}

std::string KsiazkaAdresowa::wczytajLinie()
{
    std::string wejscie = "";
    getline(std::cin, wejscie);
    return wejscie;
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){

    for (int i = 0; i < uzytkownicy.size(); i++){
            std::cout << uzytkownicy[i].pobierzId() << std::endl;
            std::cout << uzytkownicy[i].pobierzLogin() << std::endl;
            std::cout << uzytkownicy[i].pobierzHaslo() << std::endl;
    }
}
