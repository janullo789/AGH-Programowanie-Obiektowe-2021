//
// Created by Dell on 07.12.2021.
//

#include "Samochod.h"
#include <iostream>

using namespace std;

Samochod::Samochod(char rodzaj, string model, string kolor, float cena, float ladownosc, int przebieg, int pojemnoscBaku, float paliwo,
                   float spalanie, float moc, char liczbaDrzwi) : PojazdSilnikowy(rodzaj, model, kolor, cena, ladownosc, przebieg,
                                                                pojemnoscBaku,paliwo, spalanie, moc), liczbaDrzwi(liczbaDrzwi)
{

}

void Samochod::jazda()
{
    string km;
    float s= spalanie/100;
    cout << "Ile kilometow chcesz przejechac? " << endl;

    cin >> km;

    try
    {
        int zamiana = kontrolaTypuINT(km);
        int wartosc = kontrolaJazdyPS(zamiana, s, paliwo);
        cout << "Dojecheles do celu, spaliles " << wartosc * s << "l paliwa" << endl;
        przebieg += wartosc;
        paliwo -= s*wartosc;
    }
    catch(BladWartosciZaMalo &w)
    {
        cerr << "Nieodpowiednia wartosc" << endl;
        cerr << w.wiadomosc << endl;
    }
    catch(BladWartosciZaDuzo &w)
    {
        cerr << "Koniec paliwa, przejechales " << paliwo / s << "km." << endl;
        cerr << w.wiadomosc << endl;
        przebieg += paliwo / s;
        paliwo = 0;
    }
    catch(BladTypu &w)
    {
        cerr << "Nieodpowiednia wartosc" << endl;
        cerr << w.wiadomosc << endl;
    }

    cout << "Koniec jazdy samochodem" << endl;
}

void Samochod::tankuj()
{
    string l;
    cout << "Ile litrow chcesz zatankowac? " << endl;
    cin >> l;

    try
    {
        int zamiana = kontrolaTypuINT(l);
        int wartosc = kontrolaTankowania(zamiana, pojemnoscBaku, paliwo);
        paliwo += wartosc;
        cout << "Zatankowales  " << wartosc << "l paliwa" << endl;
    }
    catch(BladWartosciZaDuzo &w)
    {
        cerr << "Bak pelny. Zatankowales  " << pojemnoscBaku-paliwo << "l paliwa" << endl;
        cerr << w.wiadomosc << endl;
        paliwo = pojemnoscBaku;
    }
    catch(BladWartosciZaMalo &w)
    {
        cerr << "Nie prawidlowa wartosc" << endl;
        cerr << w.wiadomosc << endl;
        paliwo = pojemnoscBaku;
    }
    catch(BladTypu &w)
    {
        cerr << "Nieodpowiednia wartosc" << endl;
        cerr << w.wiadomosc << endl;
    }

    cout << "Koniec tankowania samochodu" << endl;
}

void Samochod::printOn(ostream &o) const
{
    o << "Model: " << model << " Kolor: " << kolor << " Cena: " << cena << " Ladownosc: " << ladownosc << " Przebieg: " <<
    przebieg << " Pojemnosc baku: " << pojemnoscBaku << " Paliwo: " << paliwo << " Spalanie: " << spalanie << " Moc: " <<
    moc << " Liczba drzwi: " << liczbaDrzwi << endl;
}

void Samochod::saveOn(ofstream &o) const
{
    o << rodzaj << " " << model << " " << kolor << " " << cena << " " << ladownosc << " " << przebieg << " " << pojemnoscBaku <<
    " " << paliwo << " " << spalanie << " " << moc << " " << liczbaDrzwi << endl;
}

