//
// Created by Dell on 19.12.2021.
//

#ifndef SKWARCZENSKIJAN_ETAP2_MOTOCYKL_H
#define SKWARCZENSKIJAN_ETAP2_MOTOCYKL_H

#include "PojazdSilnikowy.h"

class Motocykl : public PojazdSilnikowy
{
public:
    Motocykl(char rodzaj, std::string, std::string, float, float, int, int, float, float, float);
    virtual void jazda();
    virtual void tankuj();

protected:
    virtual void printOn(std::ostream& o) const;
    virtual void saveOn(std::ofstream& o) const;

};


#endif //SKWARCZENSKIJAN_ETAP2_MOTOCYKL_H
