#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <fcntl.h>


#include "Fabryka.h"
#include "Komis.h"
#include "Lakiernik.h"
#include "Pojazd.h"
#include "Motocykl.h"
#include "Samochod.h"

using namespace std;

void zapisParkingMiasto(vector<unique_ptr<Pojazd>>& zpm);
void wczytajParkingMiasto(vector<unique_ptr<Pojazd>>& wpm);
void malowanie(Fabryka &f);

template<typename T>
void wielkoscParkingu(T &obiekt);

int main(int argc, char* argv[])
{
    Fabryka f1;
    Komis k1;

    vector<unique_ptr<Pojazd>> parkingMiasto; //vector przechowujacy pojazdy sprzedane przez fabryke, ktore moze kupic komis

    cout << "Wczytac stan fabryki z pliku? [T/N]" << endl;
    char odp;
    cin >> odp;
    if (odp == 'T' || odp == 't')
    {
        f1.wczytaj();
        k1.wczytaj();
        wczytajParkingMiasto(parkingMiasto);
    }

    char czynnosc1;
    char czynnosc2;
    bool sprawdzanie;
    do
    {
        cout <<"Menu" << endl;
        cout <<"Zdecyduj czy chcesz pracowac na Fabryce czy na Komisie" << endl;
        cout <<"1. Fabryka" << endl <<
             "2. Komis" << endl <<
             "0. Wylacz program" << endl;
        cout << "Wybor: ";
        cin >> czynnosc1;

        if(czynnosc1 == '1')
        {
            do
            {
                cerr.flush();
                cout <<"1. Wyprodukuj pojazd" << endl <<
                     "2. Sprzedaj pojazd" << endl <<
                     "3. Pokaz stan fabryki" << endl <<
                     "4. Jedz wybranym pojazdem" << endl <<
                     "5. Tankuj wybrany pojazd" << endl <<
                     "6. Maluj wybrany pojazd" << endl <<
                     "0. Zakoncz prace na fabryce" << endl;
                cout << "Wybor: ";
                cin >> czynnosc2;

                switch (czynnosc2)
                {
                    case '0':
                        break;
                    case '1':
                        f1.zamownie();
                        break;
                    case '2':
                        sprawdzanie = f1.sprzedaj();
                        if(sprawdzanie) //jesli sprawdzenie = true to ze fabryka sprzedala pojazd silnikowy (a nie rower)
                        {               //ktory trzeba dopisac do wektora parkingMiasto
                            parkingMiasto.push_back(move(f1.pojazdWyjezdzajacy));
                        }
                        break;
                    case '3':
                        f1.pokaz();
                        wielkoscParkingu(f1);
                        break;
                    case '4':
                        f1.jazdaPojazdem();
                        break;
                    case '5':
                        f1.tankowaniePojazdu();
                        break;
                    case '6':
                        malowanie(f1);
                        break;
                    default:
                        cout << "Prosze podaj liczbe z przedzialu 0 - 5 :)\n";
                        break;
                }
            }while(czynnosc2 != '0');
        }
        else if(czynnosc1 == '2')
        {
            do
            {
                cerr.flush();
                cout <<"1. Kup pojazd" << endl <<
                     "2. Sprzedaj pojazd" << endl <<
                     "3. Pokaz stan komisu" << endl <<
                     "4. Jedz wybranym pojazdem" << endl <<
                     "5. Tankuj wybrany pojazd" << endl <<
                     "6. Maluj wybrany pojazd" << endl <<
                     "0. Zakoncz prac na komisie" << endl;
                cout << "Wybor: ";
                cin >> czynnosc2;

                switch (czynnosc2)
                {
                    case '0':
                        break;
                    case '1':
                        k1.kup(parkingMiasto);
                        break;
                    case '2':
                        k1.sprzedaj();
                        parkingMiasto.push_back(move(k1.pojazdDoSprzedazy));
                        break;
                    case '3':
                        k1.pokaz();
                        wielkoscParkingu(k1);
                        break;
                    case '4':
                        k1.jazdaPojazdem();
                        break;
                    case '5':
                        k1.tankowaniePojazdu();
                        break;
                    default:
                        cout << "Prosze podaj liczbe z przedzialu 0 - 5 :)\n";
                        break;
                }
            }while(czynnosc2 != '0');
        }
        else if(czynnosc1 != '0')
            cout << "Prosze podaj liczbe z przedzialu 0 - 2 :)" << endl;

    }while(czynnosc1 != '0');

    f1.zapis();
    k1.zapis();
    zapisParkingMiasto(parkingMiasto);

    return 0;
}

void zapisParkingMiasto(vector<unique_ptr<Pojazd>>& zpm)
{
    unsigned int ilosc = zpm.size(); //funkcja size() zwraca wartość w unsigned. Gdyby ilosc byla typem int,
                                        //zachodzilaby, niejawna konwersja
    ofstream plikP;
    plikP.open("parkingMiasto.txt", ofstream::out);

    for (unsigned int i = 0; i < ilosc; i++)
        plikP << *(zpm[i]);

    plikP.close();
}

void wczytajParkingMiasto(vector<unique_ptr<Pojazd>>& wpm)
{
    ifstream plikP;
    plikP.open("parkingMiasto.txt", ios::in);

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

        while (plikP >> rodzaj >> model >> kolor >> cena >> ladownosc >> przebieg)
        {
            switch(rodzaj)
            {
                case 'S':
                    plikP >> pojemnoscBaku >> paliwo >> spalanie >> moc >> liczbaDrzwi;
                    wpm.push_back(
                            make_unique<Samochod>(rodzaj, model, kolor, cena, ladownosc, przebieg, pojemnoscBaku,
                                                  paliwo, spalanie, moc, liczbaDrzwi));
                    break;
                case 'M':
                    plikP >> pojemnoscBaku >> paliwo >> spalanie >> moc;
                    wpm.push_back(
                            make_unique<Motocykl>(rodzaj, model, kolor, cena, ladownosc, przebieg, pojemnoscBaku,
                                                  paliwo, spalanie, moc));
                    break;
                default:
                    cout << "Nie mozesz wczytac pojazdow tego typu" << endl;
                    break;
            }
        }
        plikP.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku parkingMiasto" << endl;
}

void malowanie(Fabryka &f)
{
    unique_ptr<Pojazd> pojazdDoMalowania;               //fabryka wysyla pojazd do lakiernika, musi on najpierw wyjechac na "miasto"
    f.wyslanieDoMalowania();                            //potem zostaje przyjety u lekiernika, ktory zmienia mu kolor
    pojazdDoMalowania = move(f.pojazdWyjezdzajacy);   //po czym lakernik odsyla pojazd z powrotem do "miasta" gdzie fabryka go odbiera
    Lakiernik l1(pojazdDoMalowania);                 //pomalowany pojazd trafia na ostanie miejsce parkingowe (koniec wektora)
    l1.malowanie();
    f.oddebranieZMalowania(l1.pojazdDoWydania);
}

template<typename T>
void wielkoscParkingu(T &obiekt) //przyjmuje obiekt klasy Fabryka lub Komis
{
    cout << "Ilosc pojazdow: " << obiekt.zwrocWielkosc() << endl;
}


//    OPIS TEGO PONIZEJ W PLIKU .TXT
//    include <unistd.h>
//    if (argumStdin(argc, argv) < 0)
//    {
//        cerr << "Nie mozna zainicjalizowac wejscia/wyjscia..." << endl; //wykonuje sie gdy nie ma pliku
//        return 1;
//    }

//int argumStdin(int argc, char* argv[])
//{
//    int i;
//    int fd;
//
//    for (i = 1; i < argc; ++i) //nie zaczynamy od i = 0, poniewaz argv[0] to sciezka do programu
//    {
//        if (strcmp("-i", argv[i]) == 0 && argc > i + 1) //sprawdzenie czy analizowany element jest rowny ciagowi "-i" oraz sprawdzamy czy istnieje jeszcze jeden emement za nim
//        {
//            if (strcmp("\n", argv[++i]) == 0) //sprawdzamy czy argument za "-i" jest znakiem "\n"
//                continue;
//            fd = open(argv[i], O_RDONLY); //otwarcie pliku w trybie tylko do czytania
//            if (fd < 0) //sprawdzamy czy udalo sie otworzyc plik
//                return -1;
//            if (dup2(fd, 0) != 0) //dub2() powoduje ze nowy deskryptor staje sie kopia starego
//                return -2;
//            close(fd);
//        } else if (strcmp("-o", argv[i]) == 0 && argc > i + 1)
//        {
//            if (strcmp("\n", argv[++i]) == 0)
//                continue;
//            fd = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0666); //otwarty w trybie zapisu, badz utworzony, badz wyczyszczony
//            if (fd < 0)
//                return -1;
//            if (dup2(fd, 1) != 1)
//                return -2;
//            close(fd);
//        } else if (strcmp("-q", argv[i]) == 0)
//        {
//            fd = open("/dev/null", O_WRONLY); //skopiowanie deskrpyotra pliku zwroconego przez wywolanie "/dev/null"
//            dup2(fd, 2);
//            close(fd);
//        }
//    }
//    return 0;
//}
