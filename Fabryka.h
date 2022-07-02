//
// Created by Dell on 07.12.2021.
//

#ifndef SKWARCZENKIJAN_ETAP2_FABRYKA_H
#define SKWARCZENKIJAN_ETAP2_FABRYKA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include "Samochod.h"
#include "Pojazd.h"
#include "PojazdSilnikowy.h"


class Fabryka
{
public:
    Fabryka(float = 500000);

    void zamownie();
    void pokaz();
    bool sprzedaj();
    void jazdaPojazdem();
    void tankowaniePojazdu();
    void wyslanieDoMalowania();
    void oddebranieZMalowania(std::unique_ptr<Pojazd>&);
    void zapis();
    void wczytaj();
    bool sprawdzId(int);
    std::unique_ptr<Pojazd> pojazdWyjezdzajacy;
    unsigned int zwrocWielkosc();

private:
    float budzetFabryka;
    std::vector<std::unique_ptr<Pojazd>> parkingFabryka;
};

#endif //SKWARCZENKIJAN_ETAP2_FABRYKA_H
