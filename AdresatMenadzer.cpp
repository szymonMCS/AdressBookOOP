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

void AdresatMenadzer::usunAdresata(){
    int idUsuwanegoAdresata = 0;

    system("cls");
    std::cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << std::endl << std::endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (std::vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            std::cout << std::endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                plikZAdresatami.usunWybranegoAdresataZPlikuTekstowego(idUsuwanegoAdresata);
                adresaci.erase(itr);
                std::cout << std::endl << std::endl << "Szukany adresat zostal USUNIETY" << std::endl << std::endl;
                system("pause");
            }
            else
            {
                std::cout << std::endl << std::endl << "Wybrany adresat NIE zostal usuniety" << std::endl << std::endl;
                system("pause");
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        std::cout << std::endl << "Nie ma takiego adresata w ksiazce adresowej" << std::endl << std::endl;
        system("pause");
    }
}

int AdresatMenadzer::podajIdWybranegoAdresata(){
    int idWybranegoAdresata = 0;
    std::cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatMenadzer::edytujAdresata(){
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    std::string liniaZDanymiAdresata = "";

    std::cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << std::endl << std::endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (std::string::size_type i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                std::cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzImie()));
                plikZAdresatami.edytujWybranegoAdresataZPlikuTekstowego(adresaci[i], idEdytowanegoAdresata);
                break;
            case '2':
                std::cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko()));
                plikZAdresatami.edytujWybranegoAdresataZPlikuTekstowego(adresaci[i], idEdytowanegoAdresata);
                break;
            case '3':
                std::cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.edytujWybranegoAdresataZPlikuTekstowego(adresaci[i], idEdytowanegoAdresata);
                break;
            case '4':
                std::cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.edytujWybranegoAdresataZPlikuTekstowego(adresaci[i], idEdytowanegoAdresata);
                break;
            case '5':
                std::cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.edytujWybranegoAdresataZPlikuTekstowego(adresaci[i], idEdytowanegoAdresata);
                break;
            case '6':
                std::cout << std::endl << "Powrot do menu uzytkownika" << std::endl << std::endl;
                break;
            default:
                std::cout << std::endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << std::endl << std::endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        std::cout << std::endl << "Nie ma takiego adresata." << std::endl << std::endl;
    }
    system("pause");
}



char AdresatMenadzer::wybierzOpcjeZMenuEdycja(){
    char wybor;

    std::cout << std::endl << "   >>> MENU  EDYCJA <<<" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Ktore dane zaktualizowac: " << std::endl;
    std::cout << "1 - Imie" << std::endl;
    std::cout << "2 - Nazwisko" << std::endl;
    std::cout << "3 - Numer telefonu" << std::endl;
    std::cout << "4 - Email" << std::endl;
    std::cout << "5 - Adres" << std::endl;
    std::cout << "6 - Powrot " << std::endl;
    std::cout << std::endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
