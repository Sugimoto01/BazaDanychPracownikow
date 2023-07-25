#include <iostream>
#include <string>
#include <vector>


class Pracownik {
public:
    std::string imie;
    std::string nazwisko;
    std::string stanowisko;
    int wiek;
    int pensja;

    Pracownik(const std::string& im, const std::string& naz, const std::string& stan, int w, int p)
        : imie(im), nazwisko(naz), stanowisko(stan), wiek(w), pensja(p) {}
};

struct ElementListy {
    Pracownik pracownik;
    ElementListy* next;

    ElementListy(const Pracownik& pr) : pracownik(pr), next(nullptr) {}
};

class ListaPracownikow {
private:
    ElementListy* head;

public:
    ListaPracownikow() : head(nullptr) {}

    void DodajPracownika(const Pracownik& pracownik) {
        ElementListy* newElement = new ElementListy(pracownik);
        newElement->next = head;
        head = newElement;
    }

    void WyswietlListe() {
        ElementListy* current = head;
        while (current != nullptr) {
            std::cout << "Imie: " << current->pracownik.imie << ", Nazwisko: " << current->pracownik.nazwisko
                << ", Stanowisko: " << current->pracownik.stanowisko << ", Wiek: " << current->pracownik.wiek
                << ", Pensja: " << current->pracownik.pensja << std::endl;
            current = current->next;
        }
    }

    void ZnajdzPracownika(const std::string& nazwisko) {
        ElementListy* current = head;
        bool znaleziono = false;

        while (current != nullptr) {
            if (current->pracownik.nazwisko == nazwisko) {
                std::cout << "Znaleziono pracownika:" << std::endl;
                std::cout << "Imie: " << current->pracownik.imie << ", Nazwisko: " << current->pracownik.nazwisko
                    << ", Stanowisko: " << current->pracownik.stanowisko << ", Wiek: " << current->pracownik.wiek
                    << ", Pensja: " << current->pracownik.pensja << std::endl;
                znaleziono = true;
                break;
            }
            current = current->next;
        }

        if (!znaleziono) {
            std::cout << "Pracownik o nazwisku " << nazwisko << " nie istnieje w bazie danych." << std::endl;
        }
    }
};



