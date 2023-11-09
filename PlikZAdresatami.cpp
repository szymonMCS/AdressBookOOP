#include "PlikZAdresatami.h"

int PlikZAdresatami::pobierzIdOstatniegoAdresata(){
    return idOstatniegoAdresata;
}

std::vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika){
    Adresat adresat;
    std::vector <Adresat> adresaci;
    std::string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    std::string daneOstaniegoAdresataWPliku = "";
    std::fstream plikTekstowy;
    plikTekstowy.open(PlikTekstowy::pobierzNazwePliku().c_str(), std::ios::in);

    if (plikTekstowy.good())
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    }
    else{
        std::cout << "Nie udalo sie otworzyc pliku i wczytac danych." << std::endl;
    }
        plikTekstowy.close();
        system("pause");

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return adresaci;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(std::string daneJednegoAdresataOddzielonePionowymiKreskami){
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(std::string daneJednegoAdresataOddzielonePionowymiKreskami){
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(std::string daneAdresataOddzielonePionowymiKreskami){
    Adresat adresat;
    std::string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (std::string::size_type pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1: adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str())); break;
            case 2: adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str())); break;
            case 3: adresat.ustawImie(pojedynczaDanaAdresata); break;
            case 4: adresat.ustawNazwisko(pojedynczaDanaAdresata); break;
            case 5: adresat.ustawNumerTelefonu(pojedynczaDanaAdresata); break;
            case 6: adresat.ustawEmail(pojedynczaDanaAdresata); break;
            case 7: adresat.ustawAdres(pojedynczaDanaAdresata); break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat){
    std::string liniaZDanymiAdresata = "";
    std::fstream plikTekstowy;
    plikTekstowy.open(PlikTekstowy::pobierzNazwePliku().c_str(), std::ios::out | std::ios::app);

    if (plikTekstowy.good())
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (PlikTekstowy::czyPlikJestPusty())
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << std::endl << liniaZDanymiAdresata;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    else
    {
        std::cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << std::endl;
        plikTekstowy.close();
    }
    return false;
}

std::string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat){
    std::string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

void PlikZAdresatami::usunWybranegoAdresataZPlikuTekstowego (int idAdresata){
    bool czyIstniejeAdresat = false;
    int numerWczytanejLiniiZPliku = 1;
    int numerUsuwanejLinii = 0;
    std::string wczytanaLinia = "";
    std::fstream plikTekstowy;
    std::fstream tymczasowyPlikTekstowy;
    plikTekstowy.open(PlikTekstowy::pobierzNazwePliku().c_str(), std::ios::in);
    tymczasowyPlikTekstowy.open("Adresaci_temp.txt", std::ios::out | std::ios::app);

    if (plikTekstowy.good() && idAdresata != 0)
    {
        while(getline(plikTekstowy, wczytanaLinia))
        {
            if(idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia))
            {
                czyIstniejeAdresat = true;
                numerUsuwanejLinii = numerWczytanejLiniiZPliku;
                podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idAdresata);
            }
            else if (numerWczytanejLiniiZPliku == 1 && numerWczytanejLiniiZPliku != numerUsuwanejLinii)
                tymczasowyPlikTekstowy << wczytanaLinia;
            else if (numerWczytanejLiniiZPliku == 2 && numerUsuwanejLinii == 1)
                tymczasowyPlikTekstowy << wczytanaLinia;
            else if (numerWczytanejLiniiZPliku > 2 && numerUsuwanejLinii == 1)
                tymczasowyPlikTekstowy << std::endl << wczytanaLinia;
            else if (numerWczytanejLiniiZPliku > 1 && numerUsuwanejLinii != 1)
                tymczasowyPlikTekstowy << std::endl << wczytanaLinia;
            numerWczytanejLiniiZPliku++;

        }
        if (!czyIstniejeAdresat)
        {
            plikTekstowy.close();
            return;
        }

        plikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(PlikTekstowy::pobierzNazwePliku());
        zmienNazwePliku("Adresaci_temp.txt", PlikTekstowy::pobierzNazwePliku());
    }
}

void PlikZAdresatami::usunPlik(std::string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        std::cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << std::endl;
}

void PlikZAdresatami::zmienNazwePliku(std::string staraNazwa, std::string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        std::cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << std::endl;
}

int PlikZAdresatami::podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata)
{
    if (idUsuwanegoAdresata == idOstatniegoAdresata)
        return pobierzZPlikuIdOstatniegoAdresata();
    else
        return idOstatniegoAdresata;
}

int PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata()
{
    int idOstatniegoAdresata = 0;
    std::string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    std::string daneOstaniegoAdresataWPliku = "";
    std::fstream plikTekstowy;
    plikTekstowy.open(PlikTekstowy::pobierzNazwePliku().c_str(), std::ios::in);

    if (plikTekstowy.good())
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
            plikTekstowy.close();
    }
    else
        std::cout << "Nie udalo sie otworzyc pliku i wczytac danych." << std::endl;

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return idOstatniegoAdresata;
}

void PlikZAdresatami::edytujWybranegoAdresataZPlikuTekstowego(Adresat adresat, int idAdresata){
    bool czyIstniejeAdresat = false;
    int numerWczytanejLiniiZPliku = 1;
    std::string wczytanaLinia = "";
    std::string liniaZDanymiAdresata = "";
    std::fstream plikTekstowy;
    std::fstream tymczasowyPlikTekstowy;
    plikTekstowy.open(PlikTekstowy::pobierzNazwePliku().c_str(), std::ios::in);
    tymczasowyPlikTekstowy.open("Adresaci_temp.txt", std::ios::out | std::ios::app);

    if (plikTekstowy.good() && idAdresata != 0)
    {
        while (getline(plikTekstowy, wczytanaLinia))
        {
            if (idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia)){
                czyIstniejeAdresat = true;
                liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

                if (numerWczytanejLiniiZPliku == 1){
                    tymczasowyPlikTekstowy << liniaZDanymiAdresata;
                }
                else if (numerWczytanejLiniiZPliku > 1)
                    tymczasowyPlikTekstowy << std::endl << liniaZDanymiAdresata;
            }
            else
            {
                if (numerWczytanejLiniiZPliku == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLiniiZPliku > 1)
                    tymczasowyPlikTekstowy << std::endl << wczytanaLinia;
            }
            numerWczytanejLiniiZPliku++;
        }
        if (!czyIstniejeAdresat){
            plikTekstowy.close();
            std::cout << std::endl << "Adresat nie istnieje." << std::endl << std::endl;
            system("pause");
        }

        plikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(PlikTekstowy::pobierzNazwePliku());
        zmienNazwePliku("Adresaci_temp.txt", PlikTekstowy::pobierzNazwePliku());
    }

    std::cout << std::endl << "Dane zostaly zaktualizowane." << std::endl << std::endl;
}
