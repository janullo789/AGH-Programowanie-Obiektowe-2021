//
// Created by Dell on 19.12.2021.
//

#include "Komis.h"
#include "Pojazd.h"

using namespace std;

Komis::Komis(float budzetKomis) : budzetKomis(budzetKomis)
{

}

void Komis::kup(std::vector<std::unique_ptr<Pojazd>>& listaPojazdow)
{
    unsigned int ilosc = listaPojazdow.size(); //rozmiar wektora

    if (ilosc == 0)
        cout << "Brak dostepnych aut, mozliwych do zakupu przez komis" << endl;
    else
    {
        for (unsigned int i = 0; i < ilosc; i++)
            cout << i + 1 << ". " << *(listaPojazdow[i]);

        int nr;
        do
        {
            cout << "Podaj nr. pojazdu ktory chcesz kupic: " << endl;
            cin >> nr;
        } while (!sprawdzId(nr, listaPojazdow));

        if(listaPojazdow[nr-1]->zwroc<float>('c') < budzetKomis)
        {
            auto it = next(begin(listaPojazdow), (nr - 1));
            parkingKomis.push_back(move(*it));
            listaPojazdow.erase(it);

            float cena = parkingKomis[(parkingKomis.size())-1]->zwroc<float>('c');
            int przebieg = parkingKomis[(parkingKomis.size())-1]->zwroc<int>('p');
            string model = parkingKomis[(parkingKomis.size())-1]->zwroc<string>('m');

            if(model == "Passat" || model == "Golf" || model == "Junak" || model == "Simson") //dla tych modeli przebieg bedzie krecony
            {
                budzetKomis -= (cena - przebieg);   //przy dużym przebiegu pojazdu to rownanie traci sens, moznaby napisac zaleznosc
                //z uzyciem funkcji wykladniczej, ale by nie zaglebiac sie w najciemniesze otchlania
                //matematyki zastosowalem takie uproszczenie :)

                parkingKomis[(parkingKomis.size())-1]->zmienCene();
                parkingKomis[(parkingKomis.size())-1]->rabatNaPrzebieg();
            }
            else
            {
                budzetKomis -= (cena - przebieg);
                parkingKomis[(parkingKomis.size())-1]->zmienCene();
            }
        }
        else
            cout << "Budzet Twojego komisu nie pozwala na kupno wybranego pojazdu" << endl;
    }
}

void Komis::sprzedaj()
{
    if(!parkingKomis.empty())
    {
        int nr;
        do
        {
            cout << "Podaj nr. miejsca parkingowego auta do sprzedazy (1 - " << parkingKomis.size() << "):" << endl;
            cin >> nr;
        } while (!sprawdzId(nr, parkingKomis));

        budzetKomis+= 1.2*(parkingKomis[(nr - 1)]->zwroc<float>('c'));

        auto it = next(begin(parkingKomis), (nr - 1));
        pojazdDoSprzedazy = move(*it);

        parkingKomis.erase(it);
    }
}

void Komis::pokaz()
{
    unsigned int ilosc = parkingKomis.size();   //rozmiar wektora

    if (ilosc == 0)
        cout << "Twoja fabryka jest pusta" << endl;
    else
        for(unsigned int i = 0; i < ilosc; i++)
            cout << i+1 << ". " <<*(parkingKomis[i]);

    cout << "Budzet komisu " << budzetKomis << "PLN" << endl;
}

void Komis::jazdaPojazdem()
{
    if(!parkingKomis.empty())
    {
        int nr;
        do
        {
            cout << "Podaj nr. miejsca parkingowego pojazdu ktorym chcesz sie przejechac: " << endl;
            cin >> nr;
        } while (!sprawdzId(nr, parkingKomis));


        parkingKomis[(nr - 1)]->jazda();
    }
    else
        cout << "Twoj komis jest pusty" << endl;
}

void Komis::tankowaniePojazdu()
{
    if(!parkingKomis.empty())
    {
        int nr;
        do
        {
            cout << "Podaj nr. miejsca parkingowego pojazdu ktory chcesz zatankowac: " << endl;
            cin >> nr;
        } while (!sprawdzId(nr, parkingKomis));

        parkingKomis[(nr - 1)]->tankuj();
    }
    else
        cout << "Twoj komis jest pusty" << endl;
}

void Komis::zapis()
{
    unsigned int ilosc = parkingKomis.size();

    ofstream plikP;
    plikP.open("parkingKomis.txt", ofstream::out);

    for (unsigned int i = 0; i < ilosc; i++)
        plikP << *(parkingKomis[i]);

    plikP.close();

    ofstream plikB;
    plikB.open("budzetKomis.txt", ofstream::out);

    plikB << budzetKomis;

    plikB.close();
}

void Komis::wczytaj()
{
    ifstream plikP;
    plikP.open("parkingKomis.txt", ios::in);

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
                    parkingKomis.push_back(
                            make_unique<Samochod>(rodzaj, model, kolor, cena, ladownosc, przebieg, pojemnoscBaku,
                                                  paliwo, spalanie, moc, liczbaDrzwi));
                    break;
                case 'M':
                    plikP >> pojemnoscBaku >> paliwo >> spalanie >> moc;
                    parkingKomis.push_back(
                            make_unique<Motocykl>(rodzaj, model, kolor, cena, ladownosc, przebieg, pojemnoscBaku,
                                                  paliwo, spalanie, moc));
                    break;
                default:
                    cout << "Nie mozesz wczytac pojazdow tego typu" << endl;
            }
        }

        plikP.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku parkingKomis" << endl;

    ifstream plikB;
    plikB.open("budzetKomis.txt", ios::in);

    if(plikB.is_open())
    {
        if (!plikB.good())
            cout << "Twoj budzetFabryka zostanie ustawiony na domyslny" << endl;
        else
            plikB >> budzetKomis;

        plikB.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku budzetKomis" << endl;
}

bool Komis::sprawdzId(int nr, vector<unique_ptr<Pojazd>>& sprawdzanyWektor)
{
    if((nr >= 1) && (nr <= sprawdzanyWektor.size()))   //sprawdzanie czy podany numer jest w przedziale ilosci samochodow
        return true;
    return false;
}

unsigned int Komis::zwrocWielkosc()
{
    return parkingKomis.size();
}
