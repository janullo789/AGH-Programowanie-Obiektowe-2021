//
// Created by Dell on 18.12.2021.
//

#include "PojazdSilnikowy.h"

using namespace std;

PojazdSilnikowy::PojazdSilnikowy(char rodzaj, string model, string kolor, float cena, float ladownosc, int przebieg, int pojemnoscBaku,
                                 float paliwo, float spalanie, float moc) : Pojazd(rodzaj, model, kolor, cena, ladownosc, przebieg),
                                 pojemnoscBaku(pojemnoscBaku), paliwo(paliwo), spalanie(spalanie), moc(moc)
{

}

int PojazdSilnikowy::kontrolaJazdyPS(int &k, float &s, float &p)
{
    if(k >= 0)
    {
        if((p - s * k) < 0)
        {
            BladWartosciZaDuzo wysylanie;
            wysylanie.wiadomosc = "Nie mozesz przejechac calego dystansu";
            throw wysylanie;
        }
        else
        {
            return k;
        }
    }
    else
    {
        BladWartosciZaMalo wysylanie;
        wysylanie.wiadomosc = "Nie mozesz przejechac ujemnej ilosci km";
        throw wysylanie;
    }
}

int PojazdSilnikowy::kontrolaTankowania(int &l, int &pB, float &p)
{
    if(l >= 0)
    {
        if ((pB - p) < l)
        {
            BladWartosciZaDuzo wysylanie;
            wysylanie.wiadomosc = "Nie mozesz zatankowac tyle paliwa";
            throw wysylanie;
        } else
        {
            p += l;
            return p;
        }
    }
    else
    {
        BladWartosciZaMalo wysylanie;
        wysylanie.wiadomosc = "Nie mozesz przejechac ujemnej ilosci km";
        throw wysylanie;
    }
}
