#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

class Uzytkownik{

    int id;
    std::string login;
    std::string haslo;

    public:

    //SETTERY
    void ustawId(int input);
    void ustawLogin(std::string input);
    void ustawHaslo(std::string input);
    //GETTERY
    int pobierzId();
    std::string pobierzLogin();
    std::string pobierzHaslo();
};

#endif // UZYTKOWNIK_H
