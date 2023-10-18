#include "AdresatMenadzer.h"

void AdresatMenadzer::dodajAdresata(){
    Adresat adresat;

    system("cls");
    std::cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << std::endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        std::cout << "Nowy adresat zostal dodany" << std::endl;
    else
        std::cout << "Blad. Nie udalo sie dodac nowego adresata do pliku." << std::endl;
    system("pause");
}

Adresat AdresatMenadzer::podajDaneNowegoAdresata(){
    Adresat adresat;
    std::string imie, nazwisko, numerTelefonu, email, adres;

    adresat.ustawId((plikZAdresatami.pobierzIdOstatniegoAdresata() + 1));
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    std::cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);

    std::cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);

    std::cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze::wczytajLinie();

    std::cout << "Podaj email: ";
    email = MetodyPomocnicze::wczytajLinie();

    std::cout << "Podaj adres: ";
    adres = MetodyPomocnicze::wczytajLinie();

    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresatMenadzer::wyswietlWszystkichAdresatow(){
    system("cls");

    if (!adresaci.empty())
    {
        std::cout << "                 >>> ADRESACI <<<"               << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        for (std::string::size_type i = 0; i < adresaci.size(); i++){

            wyswietlDaneAdresata(i);
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << std::endl << "Ksiazka adresowa jest pusta." << std::endl << std::endl;
    }
    system("pause");
}

void AdresatMenadzer::wyswietlDaneAdresata(int input){
    std::cout << std::endl << "Id:                 " << adresaci[input].pobierzId() << std::endl;
    std::cout <<              "Imie:               " << adresaci[input].pobierzImie() << std::endl;
    std::cout <<              "Nazwisko:           " << adresaci[input].pobierzNazwisko() << std::endl;
    std::cout <<              "Numer telefonu:     " << adresaci[input].pobierzNumerTelefonu() << std::endl;
    std::cout <<              "Email:              " << adresaci[input].pobierzEmail() << std::endl;
    std::cout <<              "Adres:              " << adresaci[input].pobierzAdres() << std::endl;
}

