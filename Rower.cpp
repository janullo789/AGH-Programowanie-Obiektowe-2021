//
// Created by Dell on 18.12.2021.
//

#include "Rower.h"

#include <iostream>
using namespace std;

Rower::Rower(char rodzaj, string model, string kolor, float cena, float ladownosc, int przebieg, bool bagaznik)
: Pojazd(rodzaj, model, kolor,cena, ladownosc, przebieg), bagaznik(bagaznik)
{
    this->ladownosc = 0;
    if(bagaznik)
        this->ladownosc = 10;
}

void Rower::jazda()
{
    string km;
    cout << "Ile kilometow chcesz przejechac? " << endl;
    cin >> km;

    try
    {
        int zamiana = kontrolaTypuINT(km);
        przebieg += kontrolaJazdyR(zamiana);
        cout << "Dojecheles do celu" << endl;
    }
    catch(BladTypu &w)
    {
        cerr << "Nieodpowiednia wartosc" << endl;
        cerr << w.wiadomosc << endl;
    }
    catch(BladWartosci &w)
    {
        cerr << "Nieodpowiednia wartosc" << endl;
        cerr << w.wiadomosc << endl;
    }

    cout << "Koniec jazdy rowerem" << endl;
}

void Rower::tankuj()
{
    cout << "Jestem rowerem! Napedzasz mnie sila swoich miesni, wiec nie musisz martwic sie o tankowanie :)" << endl;
}

void Rower::printOn(ostream &o) const
{
    o << "Model: " << model << " Kolor: " << kolor << " Cena: " << cena << " Ladownosc: " << ladownosc << " Przebieg: " <<
      przebieg << " Bagaznik: " << bagaznik << endl;
}

void Rower::saveOn(ofstream &o) const
{
    o << rodzaj << " " << model << " " << kolor << " " << cena << " " << ladownosc << " " << przebieg << " " << bagaznik << endl;
}

int Rower::kontrolaJazdyR(int &k)
{
    if(k >= 0)
        return k;
    else
    {
        BladWartosci wysylanie;
        wysylanie.wiadomosc = "Nie mozesz przejechac ujemnej ilosci km";
        throw wysylanie;
    }
}



