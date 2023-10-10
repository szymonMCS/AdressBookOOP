#include "Adresat.h"

    void Adresat::ustawId(int input){
        id = input;
    }

    void Adresat::ustawIdUzytkownika(int input){
        idUzytkownika = input;
    }

    void Adresat::ustawImie(std::string noweImie){
        imie = noweImie;
    }

    void Adresat::ustawNazwisko(std::string noweNazwisko){
        nazwisko = noweNazwisko;
    }

    void Adresat::ustawNumerTelefonu(std::string nowyNumerTelefonu){
        numerTelefonu = nowyNumerTelefonu;
    }

    void Adresat::ustawEmail(std::string nowyEmail){
        email = nowyEmail;
    }

    void Adresat::ustawAdres(std::string nowyAdres){
        adres = nowyAdres;
    }

    ////////////////////////////////////////////////////////////////

    int Adresat::pobierzId(){
        return id;
    }

    int Adresat::pobierzIdUzytkownika(){
        return idUzytkownika;
    }

    std::string Adresat::pobierzImie(){
        return imie;
    }

    std::string Adresat::pobierzNazwisko(){
        return nazwisko;
    }

    std::string Adresat::pobierzNumerTelefonu(){
        return numerTelefonu;
    }

    std::string Adresat::pobierzEmail(){
        return email;
    }

    std::string Adresat::pobierzAdres(){
        return adres;
    }
