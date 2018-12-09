#include <iostream>
#include <vector>
#include <random>

using namespace std;

void photon_print(int f, int s)
{
    if (f == 1) {
        cout << "(+, ";

        if (s == 1)
            cout << "->) ; ";
        else
            cout << "|) ; ";
    }   
    else {
        cout << "(x, ";

        if (s == 1)
            cout << "|r) ; ";
        else
            cout << "|l) ; ";
    }
}

vector < pair <int, int> > photons_0;

default_random_engine generator;

void Alice_0()
{
    uniform_int_distribution <int> distribution(1, 2);

    auto dice = bind ( distribution, generator );

    cout << "Photons are generating: \n";

    for (int i = 0; i < 10; i++) {
        pair <int, int> photon;

        photon.first = dice();
        photon.second = dice();

        photons_0.push_back(photon);

        photon_print(photon.first, photon.second);
    }
    
    cout << endl;
}

void Eve_0()
{
    ;
}

void Bob_0()
{
    ;
}

int main()
{
    Alice_0();
    Eve_0();
    Bob_0();
    return 0;
}