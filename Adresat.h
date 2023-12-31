#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

class Adresat{
    int id;
    int idUzytkownika;
    std::string imie;
    std::string nazwisko;
    std::string numerTelefonu;
    std::string email;
    std::string adres;


public:
    Adresat(int id = 0,int idUzytkownika = 0, std::string imie = "", std::string nazwisko = "", std::string numerTelefonu = "", std::string email = "", std::string adres = ""){
        this->id = id;
        this->idUzytkownika = idUzytkownika;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->numerTelefonu = numerTelefonu;
        this->email = email;
        this->adres = adres;
    }
    //SETTERY
    void ustawId(int input);
    void ustawIdUzytkownika(int input);
    void ustawImie(std::string input);
    void ustawNazwisko(std::string input);
    void ustawNumerTelefonu(std::string input);
    void ustawEmail(std::string input);
    void ustawAdres(std::string input);
    //GETTERY
    int pobierzId();
    int pobierzIdUzytkownika();
    std::string pobierzImie();
    std::string pobierzNazwisko();
    std::string pobierzNumerTelefonu();
    std::string pobierzEmail();
    std::string pobierzAdres();
};

#endif // ADRESAT
