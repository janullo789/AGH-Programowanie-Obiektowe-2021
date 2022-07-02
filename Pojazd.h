//
// Created by Dell on 18.12.2021.
//

#ifndef SKWARCZENSKIJAN_ETAP2_POJAZD_H
#define SKWARCZENSKIJAN_ETAP2_POJAZD_H

#include <iostream>
#include <fstream>
#include <cassert>

class Pojazd
{
public:
    Pojazd(char, std::string, std::string, float, float, int = 0);
    virtual void jazda() = 0; //czysta funkcja virtual
    virtual void tankuj() = 0;
    void zmienCene();
    void rabatNaPrzebieg();
    void maluj(std::string wybranyKolor);
    friend std::ostream& operator<< (std::ostream& o, Pojazd const& b);
    friend std::ostream& operator<< (std::ofstream& o, Pojazd const& b);
    int kontrolaTypuINT(std::string &k);

    template<typename T>
    T zwroc(char info);

protected:
    virtual void printOn(std::ostream& o) const = 0;
    virtual void saveOn(std::ofstream& o) const = 0;
    char rodzaj;
    std::string model, kolor;
    float cena, ladownosc; // [PLN], [l]
    int przebieg;

};

template <>
inline int Pojazd::zwroc(char info)
{
    assert(info=='p');
    return przebieg;
}

template <>
inline float Pojazd::zwroc(char info)
{
    assert(info=='c'); //jesli nie bedzie to prawda, program zatrzyma sie i pokaze gdzie jest problem
    return cena;        //nie jest to konieczne do poprawnego dzialania programu, ale w tym przypadku przydatne
}                       //poniewaz dzieki temu nie mozna wywolac funkcji z nieodpowiednim charem

template <>
inline char Pojazd::zwroc(char info)
{
    assert(info=='r');
    return rodzaj;
}

template <>
inline std::string Pojazd::zwroc(char info)
{
    assert(info=='m');
    return model;
}

struct BladTypu
{
    std::string wiadomosc;
};

//Ponizej znajuduje sie poczatkowa koncepcja na funkcje zwroc.
//W mojej opinii jest ona bardziej czytelna.
//Program kompilowal sie, ale z ostrzezeniami. Program dzial dlatego ze typy int float char sa konwertowalne miedzy soba
//Gdy chcialem dolozyc string, wystepowal problem
//template<typename T>
//T Pojazd::zwroc(char info)
//{
//    switch (info)
//    {
//        case 'c':
//            return cena;
//        case 'p':
//            return przebieg;
//        case 'r':
//            return rodzaj;
//    }
//}


#endif //SKWARCZENSKIJAN_ETAP2_POJAZD_H
