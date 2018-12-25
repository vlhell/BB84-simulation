#include <iostream>
#include <vector>
#include <random>
#include <string>

using namespace std;

/* need to rename parameters */

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

void pol_on_print(int pol_on)
{
    if (pol_on == 1)
        cout << "+, ";
    else
        cout << "x, ";
}

vector < pair <int, int> > photons_0;
vector <int> pol_ons_0;
vector <bool> comp_on_0;
string RAWKEY;

default_random_engine generator;

string RAWKEY_FIND()
{
    string key = "";

    for (int i = 0; i < comp_on_0.size(); i++) {
        if (comp_on_0[i]) {
            if (photons_0[i].second == 2) {
                key += '0';
            }
            else {
                key += '1';
            }
        }
    }

    return key;
}

void Comparison_0()
{
    cout << "Alice:\n";
    cout << "\tCorrect polarization checking (1 - correct, 0 - not):\n";
    for (int i = 0; i < photons_0.size(); i++) {
        if (photons_0[i].first == pol_ons_0[i])
            comp_on_0.push_back(1);
        else
            comp_on_0.push_back(0);
    }

    cout << "\t";
    for (int i = 0; i < comp_on_0.size(); i++) {
        cout << comp_on_0[i] << ", ";
    }

    RAWKEY = RAWKEY_FIND();
}

void Bob_0()
{
    uniform_int_distribution <int> distribution(1, 2);

    auto dice = bind ( distribution, generator );

    cout << "Bob:\n";
    cout << "\tFor each photon Bob chooses polarization:\n";

    for (int i = 0; i < photons_0.size(); i++) {
        int pol_on = dice();

        pol_ons_0.push_back(pol_on);
    }

    cout << "\t";
    for (int i = 0; i < pol_ons_0.size(); i++) {
        pol_on_print(pol_ons_0[i]);
    }
    cout << "\n";

    Comparison_0();
}

void Alice_0()
{
    uniform_int_distribution <int> distribution(1, 2);

    auto dice = bind ( distribution, generator );

    cout << "Alice:\n";
    cout << "\tPhotons are generating:\n";

    for (int i = 0; i < 10; i++) {
        pair <int, int> photon;

        photon.first = dice();
        photon.second = dice();

        photons_0.push_back(photon);
    }
    
    /*  structure of this code must be refactored
    to be simple and logical;
    in particular, there must be printing
    of the whole vector, during which
    information about each photon is displayed */

    cout << "\t";
    for (int i = 0; i < photons_0.size(); i++) {
        photon_print(photons_0[i].first, photons_0[i].second);
    }
    cout << "\n";

    Bob_0();
}

void Eve_0()
{
    //interceptor job description
    ;
}

int main()
{
    Alice_0();
    cout << "\n\n RAW KEY (key's first version) = " << RAWKEY << "\n\n";
    return 0;
}