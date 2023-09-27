#include "MetodyPomocnicze.h"

std::string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    std::ostringstream ss;
    ss << liczba;
    std::string str = ss.str();
    return str;
}

std::string MetodyPomocnicze::wczytajLinie()
{
    std::string wejscie = "";
    getline(std::cin, wejscie);
    return wejscie;
}
