//
// Created by Dell on 19.12.2021.
//

#ifndef SKWARCZENSKIJAN_ETAP2_KOMIS_H
#define SKWARCZENSKIJAN_ETAP2_KOMIS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include "Pojazd.h"
#include "Samochod.h"
#include "Motocykl.h"
#include "Rower.h"

class Komis
{
public:
    Komis(float = 200000);
    void kup(std::vector<std::unique_ptr<Pojazd>>& listaPojazdow);
    void sprzedaj();
    void pokaz();
    void jazdaPojazdem();
    void tankowaniePojazdu();
    void zapis();
    void wczytaj();
    bool sprawdzId(int nr, std::vector<std::unique_ptr<Pojazd>>& sprawdzanyWektor);
    std::unique_ptr<Pojazd> pojazdDoSprzedazy;
    unsigned int zwrocWielkosc();

private:
    float budzetKomis;
    std::vector<std::unique_ptr<Pojazd>> parkingKomis;
};


#endif //SKWARCZENSKIJAN_ETAP2_KOMIS_H
