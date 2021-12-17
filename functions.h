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

class StudentasClass
{
private:
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzaminas;
    float galutinis;
public:
    StudentasClass(string vardas, string pavarde, vector<int> nd, int egzaminas)
    {
        this->vardas = vardas;
        this->pavarde = pavarde;
        this->nd = nd;
        this->egzaminas = egzaminas;
        this->galutinis = vidurkis(nd) * 0.4 + 0.6 * egzaminas;
    }

    // 1.copy constructor
    StudentasClass(const StudentasClass& kitas)
    {
        this->vardas = kitas.vardas;
        this->pavarde = kitas.pavarde;
        this->nd = kitas.nd;
        this->egzaminas = kitas.egzaminas;
        this->galutinis = kitas.galutinis;
    }
    // 2.copy assignment constructor
    StudentasClass& operator =(const StudentasClass& kitas)
    {
        this->vardas = kitas.vardas;
        this->pavarde = kitas.pavarde;
        this->nd = kitas.nd;
        this->egzaminas = kitas.egzaminas;
        this->galutinis = kitas.galutinis;
        return *this;
    }
    // 3. Destructor
    ~StudentasClass()
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

};

void dalijimas_struct(list<studentas> studentai);

void dalijimas_class(list<StudentasClass> studentai);

void testuoti(int kiek);
