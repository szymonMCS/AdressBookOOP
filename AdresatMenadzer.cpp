#include "AdresatMenadzer.h"

void AdresatMenadzer::ustawIdZalogowanegoUzytkownika(int idZalogowanego){

    idZalogowanegoUzytkownika = idZalogowanego;
}
int AdresatMenadzer::pobierzIdZalogowanegoUzytkownika(){

    return idZalogowanegoUzytkownika;
}

void AdresatMenadzer::pobierzAdresatowZalogowanegoUzytkownikaZPliku(){

    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(pobierzIdZalogowanegoUzytkownika());

}

int AdresatMenadzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    std::cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << std::endl << std::endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return plikZAdresatami.pobierzIdOstatniegoAdresata() + 1;
}

Adresat AdresatMenadzer::podajDaneNowegoAdresata()
{
    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata());
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    std::cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    std::cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    std::cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    std::cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    std::cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatMenadzer::wyswietlWszystkichAdresatow()
{
    system("cls");

    if (!adresaci.empty())
    {
        std::cout << "                 >>> ADRESACI <<<"               << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        for (int i = 0; i < adresaci.size(); i++){

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

void AdresatMenadzer::wyswietlDaneAdresata(int input)
{
    std::cout << std::endl << "Id:                 " << adresaci[input].pobierzId() << std::endl;
    std::cout <<              "Imie:               " << adresaci[input].pobierzImie() << std::endl;
    std::cout <<              "Nazwisko:           " << adresaci[input].pobierzNazwisko() << std::endl;
    std::cout <<              "Numer telefonu:     " << adresaci[input].pobierzNumerTelefonu() << std::endl;
    std::cout <<              "Email:              " << adresaci[input].pobierzEmail() << std::endl;
    std::cout <<              "Adres:              " << adresaci[input].pobierzAdres() << std::endl;
}

std::vector<Adresat>& AdresatMenadzer::pobierzWektorAdresatow() {
    return wektorAdresatow;
}

