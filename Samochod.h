//
// Created by Dell on 07.12.2021.
//

#ifndef SKWARCZENKIJAN_ETAP2_SAMOCHOD_H
#define SKWARCZENKIJAN_ETAP2_SAMOCHOD_H


#include <iostream>
#include <fstream>

#include "PojazdSilnikowy.h"

class Samochod : public PojazdSilnikowy
{
public:
    Samochod(char, std::string, std::string, float, float, int, int, float, float, float, char);
    virtual void jazda();
    virtual void tankuj();

protected:
    virtual void printOn(std::ostream& o) const;
    virtual void saveOn(std::ofstream& o) const;

private:
    char liczbaDrzwi;
};



#endif //SKWARCZENKIJAN_ETAP2_SAMOCHOD_H
