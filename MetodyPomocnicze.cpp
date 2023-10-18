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
