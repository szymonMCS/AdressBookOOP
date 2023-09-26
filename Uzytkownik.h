#include <iostream>

class Uzytkownik{

    int id;
    std::string login;
    std::string haslo;

    public:
    void ustawId(int input);
    void ustawLogin(std::string input);
    void ustawHaslo(std::string input);

    int pobierzId();
    std::string pobierzLogin();
    std::string pobierzHaslo();


};
