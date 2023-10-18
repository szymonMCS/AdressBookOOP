#include "UzytkownikMenadzer.h"

void UzytkownikMenadzer::rejestracjaUzytkownika(){
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    std::cout << std::endl << "Konto zalozono pomyslnie" << std::endl << std::endl;
    system("pause");
}

Uzytkownik UzytkownikMenadzer::podajDaneNowegoUzytkownika(){
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do
    {
        std::cout << "Podaj login: ";
        uzytkownik.ustawLogin(MetodyPomocnicze::wczytajLinie());
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    std::cout << "Podaj haslo: ";
    uzytkownik.ustawHaslo(MetodyPomocnicze::wczytajLinie());

    return uzytkownik;
}

int UzytkownikMenadzer::pobierzIdNowegoUzytkownika(){
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenadzer::czyIstniejeLogin(std::string login){
    for (std::string::size_type i = 0; i < uzytkownicy.size(); i++){
        if (uzytkownicy[i].pobierzLogin() == login){

            std::cout << std::endl << "Istnieje uzytkownik o takim loginie." << std::endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenadzer::wypiszWszystkichUzytkownikow(){
    for (std::string::size_type i = 0; i < uzytkownicy.size(); i++){

            std::cout << uzytkownicy[i].pobierzId() << std::endl;
            std::cout << uzytkownicy[i].pobierzLogin() << std::endl;
            std::cout << uzytkownicy[i].pobierzHaslo() << std::endl;
    }
}

void UzytkownikMenadzer::logowanieUzytkownika(){
    Uzytkownik uzytkownik;
    std::string login = "";
    std::string haslo = "";

    std::cout << std::endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    for (std::string::size_type i = 0; i < uzytkownicy.size(); i++){
        if (uzytkownicy[i].pobierzLogin() == login){
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                std::cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    std::cout << std::endl << "Zalogowales sie." << std::endl << std::endl;
                    system("pause");
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    return;
                }
            }
            std::cout << "Wprowadzono 3 razy bledne haslo." << std::endl;
            system("pause");
            return;
        }
    }
    std::cout << "Nie ma uzytkownika z takim loginem" << std::endl << std::endl;
    system("pause");
}

void UzytkownikMenadzer::zmianaHaslaZalogowanegoUzytkownika(){
    std::string noweHaslo = "";
    std::cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (std::string::size_type i = 0; i < uzytkownicy.size(); i++){

        if (uzytkownicy[i].pobierzId() == pobierzIdZalogowanegoUzytkownika()){
            uzytkownicy[i].ustawHaslo(noweHaslo);
            std::cout << "Haslo zostalo zmienione." << std::endl << std::endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenadzer::wylogujUzytkownika(){
    idZalogowanegoUzytkownika = 0;
}

int UzytkownikMenadzer::pobierzIdZalogowanegoUzytkownika(){
        return idZalogowanegoUzytkownika;
    }

bool UzytkownikMenadzer::czyUzytkownikJestZalogowany(){
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

