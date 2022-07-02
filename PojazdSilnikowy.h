//
// Created by Dell on 18.12.2021.
//

#ifndef SKWARCZENSKIJAN_ETAP2_POJAZDSILNIKOWY_H
#define SKWARCZENSKIJAN_ETAP2_POJAZDSILNIKOWY_H

#include "Pojazd.h"

class PojazdSilnikowy : public Pojazd
{
public:
    PojazdSilnikowy(char, std::string, std::string, float, float, int, int, float, float, float);
    int kontrolaJazdyPS(int &k, float &s, float &p);
    int kontrolaTankowania(int &l, int &pB, float &p);

protected:
    int pojemnoscBaku;
    float paliwo, spalanie, moc;


};

struct BladWartosciZaDuzo
{
    std::string wiadomosc;
};

struct BladWartosciZaMalo
{
    std::string wiadomosc;
};

#endif //SKWARCZENSKIJAN_ETAP2_POJAZDSILNIKOWY_H
