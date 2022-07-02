//
// Created by Dell on 18.12.2021.
//

#include "Pojazd.h"

using namespace std;

Pojazd::Pojazd(char rodzaj, string model, string kolor, float cena, float ladownosc, int przebieg) : rodzaj(rodzaj), model(model), kolor(kolor),
cena(cena), ladownosc(ladownosc), przebieg(przebieg)
{

}

void Pojazd::zmienCene()
{
    cena *= 0.9;
}

void Pojazd::rabatNaPrzebieg()
{
    przebieg /= 2;
}

void Pojazd::maluj(string wybranyKolor)
{
    kolor = wybranyKolor;
}

std::ostream& operator<< (ostream& o, Pojazd const& b)
{
    b.printOn(o);
    return o;
}

std::ostream& operator<< (ofstream& o, Pojazd const& b)
{
    b.saveOn(o);
    return o;
}

int Pojazd::kontrolaTypuINT(string &k)
{
    try
    {
        size_t idx= 0;
        int x = stoi(k, &idx);
        return x;
    }
    catch(invalid_argument)
    {
        BladTypu wysylanie;
        wysylanie.wiadomosc = "Podana wartosc musi byc INT";
        throw wysylanie;
    }
    catch(out_of_range)
    {
        BladTypu wysylanie;
        wysylanie.wiadomosc = "Wartosc wykracza poza zakres wartosci tego typu zmiennej";
        throw wysylanie;
    }

}
