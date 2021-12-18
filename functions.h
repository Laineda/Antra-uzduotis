#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <numeric>
#include <random>
#include <list>
using namespace std;
struct studentas
{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzaminas;
    float galutinis;
};


double vidurkis(vector<int> nd);

class žmogus
{
protected:
    žmogus() {}
    string vardas;
    string pavarde;
};
class Studentas : public žmogus
{
private:
    vector<int> nd;
    int egzaminas;
    float galutinis;
public:
    Studentas(string vardas, string pavarde, vector<int> nd, int egzaminas)
    {
        this->vardas = vardas;
        this->pavarde = pavarde;
        this->nd = nd;
        this->egzaminas = egzaminas;
        this->galutinis = vidurkis(nd) * 0.4 + 0.6 * egzaminas;
    }

    // 1. Destructor
    ~Studentas()
    {

    }
    float getRezultatas() const
    {
        return galutinis;
    }
    void spausdinti()
    {
        cout << vardas << " " << pavarde << " " << galutinis << endl;
    }

    void spausdinti_pilnai()
    {
        cout << vardas << " " << pavarde << " " << nd[0] << " " << nd[1] << " " << nd[2] << " " << nd[3] << " " << nd[4] << " | " << egzaminas << " " << galutinis << endl;
    }

    // 1.copy constructor
    Studentas(const Studentas& kitas)
    {
        this->vardas = kitas.vardas;
        this->pavarde = kitas.pavarde;
        this->nd = kitas.nd;
        this->egzaminas = kitas.egzaminas;
        this->galutinis = kitas.galutinis;
    }
    // 2.copy assignment operator
    Studentas& operator =(const Studentas& kitas)
    {
        this->vardas = kitas.vardas;
        this->pavarde = kitas.pavarde;
        this->nd = kitas.nd;
        this->egzaminas = kitas.egzaminas;
        this->galutinis = kitas.galutinis;
        return *this;
    }

};

void dalijimas_struct(list<studentas> studentai);

void dalijimas_class(list<Studentas> studentai);

void testuoti(int kiek);

