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

    for (int i = 0; i < uzytkownicy.size(); i++){
        if (uzytkownicy[i].pobierzLogin() == login){

            std::cout << std::endl << "Istnieje uzytkownik o takim loginie." << std::endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenadzer::wypiszWszystkichUzytkownikow(){

    for (int i = 0; i < uzytkownicy.size(); i++){

            std::cout << uzytkownicy[i].pobierzId() << std::endl;
            std::cout << uzytkownicy[i].pobierzLogin() << std::endl;
            std::cout << uzytkownicy[i].pobierzHaslo() << std::endl;
    }
}

void UzytkownikMenadzer::wczytajUzytkownikowZPliku(){

    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

