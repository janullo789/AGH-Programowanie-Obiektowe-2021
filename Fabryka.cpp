////
//// Created by Dell on 07.12.2021.
////
//
#include "Fabryka.h"
#include "Pojazd.h"
#include "Samochod.h"
#include "Motocykl.h"
#include "Rower.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Fabryka::Fabryka(float budzetFabryka) : budzetFabryka(budzetFabryka)
{

}

void Fabryka::zamownie()
{
    char wybor1;
    char wybor2;
    char wybor3;
    int wybor4;
    char rodzaj;
    string model;
    string kolor = "Bialy";
    float ladownosc = 0;
    int przebieg = 0;
    int pojemnoscBaku;
    float paliwo;
    float cena;
    float moc;
    float spalanie;
    char liczbaDrzwi;
    bool bagaznik = false;

    do
    {
        cout << "Kategoria pojazdu:" << endl <<
             "1. Samochod" << endl <<
             "2. Motocykl" << endl <<
             "3. Rower" << endl;

        cin >> wybor1;

        switch (wybor1)
        {
            case '1':
                do
                {
                    cout << "Wybierz model samochodu:" << endl <<
                         "1. Passat" << endl <<
                         "2. Golf" << endl <<
                         "3. Polo" << endl <<
                         "4. Tiguan" << endl;

                    cin >> wybor2;

                    switch (wybor2)
                    {
                        case '1':
                            model = "Passat";
                            pojemnoscBaku = 55;
                            cena = 80000;
                            ladownosc = 565;
                            break;
                        case '2':
                            model = "Golf";
                            pojemnoscBaku = 50;
                            cena = 70000;
                            ladownosc = 380;
                            break;
                        case '3':
                            model = "Polo";
                            pojemnoscBaku = 45;
                            cena = 60000;
                            ladownosc = 320;
                            break;
                        case '4':
                            model = "Tiguan";
                            pojemnoscBaku = 65;
                            cena = 95000;
                            ladownosc = 655;
                            break;
                        default:
                            cout << "Prosze podaj liczbe z przedzialu 1 - 4" << endl;
                            break;
                    }

                    paliwo = 10;

                } while (wybor2 != '1' && wybor2 != '2' && wybor2 != '3' && wybor2 != '4');

                do
                {
                    cout << "Nasza fabryka tworzy silniki o mocy z przedzialu 90 - 250 [KM]" << endl <<
                         "Wybierz moc samochodu" << endl;
                    cin >> moc;

                } while (moc < 90 || moc > 250);

                spalanie = (moc / 100) * 6;
                cena += (moc / 10);
                budzetFabryka -= cena * 0.7;

                cout << "Wybierz nr. koloru pojazdu: " << endl;
                cout << "1. Bialy" << endl <<
                        "2. Czarny" << endl <<
                        "3. Srebny" << endl <<
                        "4. Czerwony" << endl;
                cin >> wybor4;

                switch (wybor4)
                {
                    case 1:
                        kolor = "Bialy";
                        break;
                    case 2:
                        kolor = "Czarny";
                        break;
                    case 3:
                        kolor = "Srebny";
                        break;
                    case 4:
                        kolor = "Czerwony";
                        break;
                    default:
                        cout << "Nie podales prawidlowej cyfry, twoj pojazd bedzie mial kolor domyslny (bialy)" << endl;
                        break;
                }

                do
                {
                    cout << "Podaj liczbe drzwi (3/5): " << endl;
                    cin >> liczbaDrzwi;
                } while (liczbaDrzwi != '3' && liczbaDrzwi != '5');

                rodzaj = 'S';

                if ((budzetFabryka - cena) > 0)
                {
                    parkingFabryka.push_back(
                            make_unique<Samochod>(rodzaj, model, kolor, cena, ladownosc, przebieg, pojemnoscBaku,
                                                  paliwo, spalanie, moc, liczbaDrzwi));
                } else
                    cout << "Budzet Twojej fabryki nie pozwala na wyprodukowanie wybranego pojazdu." << endl <<
                         "Sprzedaj swoje aktualne pojazdy lub zaloz nowa fabryke!" << endl;

                break;

            case '2':
                do
                {
                    cout << "Wybierz model motocyklu:" << endl <<
                         "1. Simson" << endl <<
                         "2. Junak" << endl <<
                         "3. Yamaha" << endl <<
                         "4. Harley Davidson" << endl;

                    cin >> wybor2;

                    switch (wybor2)
                    {
                        case '1':
                            model = "Simson";
                            pojemnoscBaku = 7;
                            cena = 5000;
                            ladownosc = 10;
                            break;
                        case '2':
                            model = "Junak";
                            pojemnoscBaku = 10;
                            cena = 9000;
                            ladownosc = 20;
                            break;
                        case '3':
                            model = "Yamaha";
                            pojemnoscBaku = 12;
                            cena = 16000;
                            ladownosc = 25;
                            break;
                        case '4':
                            model = "Harley Davidson";
                            pojemnoscBaku = 15;
                            cena = 23000;
                            ladownosc = 40;
                            break;
                        default:
                            cout << "Prosze podaj liczbe z przedzialu 1 - 4" << endl;
                            break;
                    }

                    paliwo = 4;

                } while (wybor2 != '1' && wybor2 != '2' && wybor2 != '3' && wybor2 != '4');

                do
                {
                    cout << "Nasza fabryka tworzy silniki o mocy z przedzialu 10 - 55 [KM]" << endl <<
                         "Wybierz moc motocykla" << endl;
                    cin >> moc;
                } while (moc < 10 || moc > 55);

                spalanie = (moc / 100) * 6;
                cena += (moc / 10);
                budzetFabryka -= cena * 0.7;

                cout << "Wybierz nr. koloru pojazdu: " << endl;
                cout << "1. Bialy" << endl <<
                     "2. Czarny" << endl <<
                     "3. Srebny" << endl <<
                     "4. Czerwony" << endl;
                cin >> wybor4;

                switch (wybor4)
                {
                    case 1:
                        kolor = "Bialy";
                        break;
                    case 2:
                        kolor = "Czarny";
                        break;
                    case 3:
                        kolor = "Srebny";
                        break;
                    case 4:
                        kolor = "Czerwony";
                        break;
                    default:
                        cout << "Nie podales prawidlowej cyfry, twoj pojazd bedzie mial kolor domyslny" << endl;
                        break;

                }

                rodzaj = 'M';

                if ((budzetFabryka - cena) > 0)
                {
                    parkingFabryka.push_back(
                            make_unique<Motocykl>(rodzaj, model, kolor, cena, ladownosc, przebieg, pojemnoscBaku,
                                                  paliwo, spalanie, moc));
                } else
                    cout << "Budzet Twojej fabryki nie pozwala na wyprodukowanie wybranego pojazdu." << endl <<
                         "Sprzedaj swoje aktualne pojazdy lub zaloz nowa fabryke!" << endl;

                break;

            case '3':
                do
                {
                    cout << "Wybierz model rower:" << endl <<
                         "1. Kross" << endl <<
                         "2. Trek" << endl <<
                         "3. Cannondale " << endl <<
                         "4. Scott" << endl;

                    cin >> wybor2;

                    switch (wybor2)
                    {
                        case '1':
                            model = "Kross";
                            cena = 2000;
                            break;
                        case '2':
                            model = "Trek";
                            cena = 4000;
                            break;
                        case '3':
                            model = "Cannondale";
                            cena = 6000;
                            break;
                        case '4':
                            model = "Scott";
                            cena = 8000;
                            break;
                        default:
                            cout << "Prosze podaj liczbe z przedzialu 1 - 4" << endl;
                            break;
                    }
                } while (wybor2 != '1' && wybor2 != '2' && wybor2 != '3' && wybor2 != '4');

                cout << "Wybierz nr. koloru pojazdu: " << endl;
                cout << "1. Bialy" << endl <<
                     "2. Czarny" << endl <<
                     "3. Srebny" << endl <<
                     "4. Czerwony" << endl;
                cin >> wybor4;

                switch (wybor4)
                {
                    case 1:
                        kolor = "Bialy";
                        break;
                    case 2:
                        kolor = "Czarny";
                        break;
                    case 3:
                        kolor = "Srebny";
                        break;
                    case 4:
                        kolor = "Czerwony";
                        break;
                    default:
                        cout << "Nie podales prawidlowej cyfry, twoj pojazd bedzie mial kolor domyslny" << endl;
                        break;

                }

                cout << "Czy chcesz dolozyc bagaznik rowerowy? [T/N]: " << endl;
                cin >> wybor3;
                if (wybor3 == 'T' || wybor3 == 't')
                    bagaznik = true;

                rodzaj = 'R';

                if ((budzetFabryka - cena) > 0)
                {
                    parkingFabryka.push_back(make_unique<Rower>(rodzaj, model, kolor, cena, ladownosc, przebieg, bagaznik));
                } else
                    cout << "Budzet Twojej fabryki nie pozwala na wyprodukowanie wybranego pojazdu." << endl <<
                         "Sprzedaj swoje aktualne pojazdy lub zaloz nowa fabryke!" << endl;

                break;
            default:
                cout << "Podaj liczbe z przedzialu 1 - 3" << endl;
                break;
        }

    } while (wybor1 != '1' && wybor1 != '2' && wybor1 != '3');
}

void Fabryka::pokaz()
{
    unsigned int ilosc = parkingFabryka.size();   //rozmiar wektora

    if (ilosc == 0)
        cout << "Twoja fabryka jest pusta" << endl;
    else
        for(unsigned int i = 0; i < ilosc; i++)
            cout << i+1 << ". " <<*(parkingFabryka[i]);

    cout << "Budzet firmy " << budzetFabryka << "PLN" << endl;
}

bool Fabryka::sprzedaj()
{
    bool sprawdzanie = false;

    if(!parkingFabryka.empty()) //sprawdza czy wektor nie jest pusty, mozna tez tak: parkingFabryka.size() != 0
    {
        int nr;
        do
        {
            cout << "Podaj nr. miejsca parkingowego auta do sprzedazy (1 - " << parkingFabryka.size() << "):" << endl;
            cin >> nr;
        } while (!sprawdzId(nr));

        budzetFabryka += parkingFabryka[(nr - 1)]->zwroc<float>('c');
        char sprawdzrodzaj = parkingFabryka[(nr - 1)]->zwroc<char>('r');

        auto it = next(begin(parkingFabryka), (nr - 1));

        if(sprawdzrodzaj == 'M' || sprawdzrodzaj == 'S')    //zalezy nam tylko na przeslaniu pojazdu silnikowych do wektora parkingMiasto
        {                                                   //poniewaz komis i tak nie moze kupic roweru
            pojazdWyjezdzajacy = move(*it);
            sprawdzanie = true;     //dzieki temu program po wywolaniu metody wie czy sprzedal pojazd silnikowy czy rower
        }

        parkingFabryka.erase(it);
    }
    else
        cout << "Twoja fabryka jest pusta" << endl;

    return sprawdzanie;
}

bool Fabryka::sprawdzId(int nr)
{
    if((nr >= 1) && (nr <= parkingFabryka.size()))   //sprawdzanie czy podany numer jest w przedziale ilosci pojazdow
        return true;
    return false;
}

void Fabryka::jazdaPojazdem()
{
    if(!parkingFabryka.empty()) //sprawdza czy wektor nie jest pusty, mozna tez tak: parkingFabryka.size() != 0
    {
        int nr;
        do
        {
            cout << "Podaj nr. miejsca parkingowego pojazdu ktorym chcesz sie przejechac: " << endl;
            cin >> nr;
        } while (!sprawdzId(nr));


        parkingFabryka[(nr - 1)]->jazda();
    }
    else
        cout << "Twoja fabryka jest pusta" << endl;
}

void Fabryka::tankowaniePojazdu()
{
    if(!parkingFabryka.empty())
    {
        int nr;
        do
        {
            cout << "Podaj nr. miejsca parkingowego pojazdu ktory chcesz zatankowac: " << endl;
            cin >> nr;
        } while (!sprawdzId(nr));

        parkingFabryka[(nr - 1)]->tankuj();
    }
    else
        cout << "Twoja fabryka jest pusta" << endl;
}

void Fabryka::wyslanieDoMalowania()
{
    if(!parkingFabryka.empty())
    {
        int nr;
        do
        {
            cout << "Podaj nr. miejsca parkingowego pojazdu do malowania (1 - " << parkingFabryka.size() << "):" << endl;
            cin >> nr;
        } while (!sprawdzId(nr));

        auto it = next(begin(parkingFabryka), (nr - 1));
        pojazdWyjezdzajacy = move(*it);
        parkingFabryka.erase(it);

    }
    else
        cout << "Twoja fabryka jest pusta" << endl;
}

void Fabryka::oddebranieZMalowania(std::unique_ptr<Pojazd>& p)
{
    parkingFabryka.push_back(move(p));
}

void Fabryka::zapis()
{
    unsigned int ilosc = parkingFabryka.size();

    ofstream plikP;
    plikP.open("parkingFabryka.txt", ofstream::out);

    for (unsigned int i = 0; i < ilosc; i++)
        plikP << *(parkingFabryka[i]);

    plikP.close();

    ofstream plikB;
    plikB.open("budzetFabryka.txt", ofstream::out);

    plikB << budzetFabryka;

    plikB.close();
}

void Fabryka::wczytaj()
{
    ifstream plikP;
    plikP.open("parkingFabryka.txt", ios::in);

    if(plikP.is_open()) //sprawdzenie czy plik sie otworzyl
    {
        char rodzaj;
        std::string model;
        std::string kolor;
        float cena;
        float ladownosc;
        int przebieg;
        int pojemnoscBaku;
        float paliwo;
        float spalanie;
        float moc;
        char liczbaDrzwi;
        bool bagaznik;

        while (plikP >> rodzaj >> model >> kolor >> cena >> ladownosc >> przebieg)
        {
            switch(rodzaj)
            {
                case 'S':
                    plikP >> pojemnoscBaku >> paliwo >> spalanie >> moc >> liczbaDrzwi;
                    parkingFabryka.push_back(
                            make_unique<Samochod>(rodzaj, model, kolor, cena, ladownosc, przebieg, pojemnoscBaku,
                                              paliwo, spalanie, moc, liczbaDrzwi));
                    break;
                case 'M':
                    plikP >> pojemnoscBaku >> paliwo >> spalanie >> moc;
                    parkingFabryka.push_back(
                            make_unique<Motocykl>(rodzaj, model, kolor, cena, ladownosc, przebieg, pojemnoscBaku,
                                                  paliwo, spalanie, moc));
                    break;
                case 'R':
                    plikP >> bagaznik;
                    parkingFabryka.push_back(
                            make_unique<Rower>(rodzaj, model, kolor, cena, ladownosc, przebieg, bagaznik));
                    break;
                default:
                    cout << "Nie mozesz wczytac pojazdow tego typu" << endl;
            }
        }

        plikP.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku parkingFabryka" << endl;

    ifstream plikB;
    plikB.open("budzetFabryka.txt", ios::in);

    if(plikB.is_open())
    {
        if (!plikB.good()) //mozna tez tak: plikB.good() == false
            cout << "Twoj budzetFabryka zostanie ustawiony na domyslny" << endl;
        else
            plikB >> budzetFabryka;

        plikB.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku budzetFabryka" << endl;
}

unsigned int Fabryka::zwrocWielkosc()
{
    return parkingFabryka.size();
}




