//
// Created by Dell on 24.12.2021.
//

#ifndef SKWARCZENSKIJAN_ETAP2_LAKIERNIK_H
#define SKWARCZENSKIJAN_ETAP2_LAKIERNIK_H

#include <memory>
#include "Pojazd.h"


class Lakiernik
{
public:
    Lakiernik();
    Lakiernik(std::unique_ptr<Pojazd>& );
    void malowanie();
    std::unique_ptr<Pojazd> pojazdDoWydania;

private:
    std::unique_ptr<Pojazd> malowanyPojazd;
};


#endif //SKWARCZENSKIJAN_ETAP2_LAKIERNIK_H
