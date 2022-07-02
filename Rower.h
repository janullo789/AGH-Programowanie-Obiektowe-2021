//
// Created by Dell on 18.12.2021.
//

#ifndef SKWARCZENSKIJAN_ETAP2_ROWER_H
#define SKWARCZENSKIJAN_ETAP2_ROWER_H

#include "Pojazd.h"
#include <fstream>

class Rower : public Pojazd
{
public:
    Rower(char, std::string, std::string, float, float, int, bool);
    virtual void jazda();
    virtual void tankuj();
    int kontrolaJazdyR(int &k);

protected:
    virtual void printOn(std::ostream& o) const;
    virtual void saveOn(std::ofstream& o) const;

private:
    bool bagaznik;

};

struct BladWartosci
{
    std::string wiadomosc;
};

#endif //SKWARCZENSKIJAN_ETAP2_ROWER_H
