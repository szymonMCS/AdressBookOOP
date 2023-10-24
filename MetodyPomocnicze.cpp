#include "MetodyPomocnicze.h"

int MetodyPomocnicze::konwersjaStringNaInt(std::string liczba){
    int liczbaInt;
    std::istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

std::string MetodyPomocnicze::wczytajLinie(){
    std::string wejscie = "";
    getline(std::cin, wejscie);
    return wejscie;
}

std::string MetodyPomocnicze::konwersjaIntNaString(int liczba){
    std::ostringstream ss;
    ss << liczba;
    std::string str = ss.str();
    return str;
}

std::string MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(std::string tekst){
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}


char MetodyPomocnicze::wczytajZnak(){
    std::string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(std::cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        std::cout << "To nie jest pojedynczy znak. Wpisz ponownie." << std::endl;
    }
    return znak;
}

std::string MetodyPomocnicze::pobierzLiczbe(std::string tekst, int pozycjaZnaku){
    std::string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int MetodyPomocnicze::wczytajLiczbeCalkowita()
{
    std::string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(std::cin, wejscie);

        std::stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        std::cout << "To nie jest liczba. Wpisz ponownie. " << std::endl;
    }
    return liczba;
}
