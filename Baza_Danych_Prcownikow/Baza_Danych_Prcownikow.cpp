#include <iostream>
#include <list>
#include "Pracownik.h"

int main()
{
    ListaPracownikow bazaPracownikow;
    std::string imie, nazwisko, stanowisko;
    std::string szukaneNazwisko;

    int wybor, wiek, pensja;
    while(true){
    std::cout << "------------" << std::endl;
    std::cout << "1.Dodaj Pracownika" << std::endl;
    std::cout << "2.Wyświetl listę pracowników" << std::endl;
    std::cout << "3.Szukaj Pracownika"<<std::endl;
    std::cout << "4.Wyjście"<<std::endl;
    std::cout << "------------"<<std::endl;
    std::cout << "Co wybierasz:";
    std::cin >> wybor;
    
        switch (wybor) {
        case 1: {
            std::cout << "Podaj imię pracownika:" << std::endl; std::cin >> imie;
            std::cout << "Podaj nazwisko pracownika:" << std::endl; std::cin >> nazwisko;
            std::cout << "Podaj wiek pracownika:"; std::cin >> wiek;
            std::cout << "Podaj stanowisko pracownika:" << std::endl; std::cin >> stanowisko;
            std::cout << "Podaj pensje pracownika:" << std::endl; std::cin >> pensja;
            Pracownik pracownik(imie, nazwisko, stanowisko, wiek, pensja);
            bazaPracownikow.DodajPracownika(pracownik);
            break;
        }
        case 2:
            std::cout << "----- Lista pracownikow -----" << std::endl;
            bazaPracownikow.WyswietlListe();
            std::cout << "-----------------------------" << std::endl;
            break;
        case 3:

            std::cout << "Podaj nazwisko pracownika do wyszukania: ";
            std::cin >> szukaneNazwisko;

            bazaPracownikow.ZnajdzPracownika(szukaneNazwisko);
            break;
        case 4:
            return 0;
            break;
        default:
            std::cout << "Nie ma takiej opcji w menu.";
            break;
        }
    }
    return 0;
}
