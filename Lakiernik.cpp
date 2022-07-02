//
// Created by Dell on 24.12.2021.
//

#include "Lakiernik.h"

using namespace std;

Lakiernik::Lakiernik() = default;

Lakiernik::Lakiernik(unique_ptr<Pojazd>& malowanyPojazd) : malowanyPojazd(std::move(malowanyPojazd))
{

}

void Lakiernik::malowanie()
{
    char wybor;
    string kolor;

    do
    {
        cout << "Wybierz kolor na jaki chcesz pomalowac pojazd" << endl;
        cout << "1. Bialy" << endl <<
             "2. Czarny" << endl <<
             "3. Srebny" << endl <<
             "4. Czerwony" << endl <<
             "5. Zloty" << endl <<
             "6. Zielony" << endl;
        cin >> wybor;

        switch (wybor)
        {
            case '1':
                kolor = "Bialy";
                break;
            case '2':
                kolor = "Czarny";
                break;
            case '3':
                kolor = "Srebny";
                break;
            case '4':
                kolor = "Czerwony";
                break;
            case '5':
                kolor = "Zloty";
                break;
            case '6':
                kolor = "Zielony";
            default:
                cout << "Podaj liczbe z przedzialu 1 - 6" << endl;
                break;

        }
    } while(wybor != '1' && wybor != '2' && wybor != '3' && wybor != '4' && wybor != '5' && wybor != '6');

    malowanyPojazd->maluj(kolor);
    pojazdDoWydania = move(malowanyPojazd);
}

