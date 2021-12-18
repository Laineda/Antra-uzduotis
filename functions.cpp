#include "functions.h"

using namespace std;

double vidurkis(vector<int> nd)
{
    int suma = 0;
    for (int i : nd)
    {
        suma += i;
    }
    return suma / nd.size();
}



list<studentas> stud_generavimas(int kiek, list<Studentas>& studentaiClass)
{
    list<studentas> studentai;
    for (int i = 0; i < kiek; i++)
    {
        studentas temp;
        string vardas = "Vardas" + to_string(i + 1);
        string pavarde = "Pavarde" + to_string(i + 1);
        int egzaminas = egzaminas = rand() % 10 + 1;
        int ND1 = rand() % 10 + 1;
        int ND2 = rand() % 10 + 1;
        int ND3 = rand() % 10 + 1;
        int ND4 = rand() % 10 + 1;
        int ND5 = rand() % 10 + 1;
        vector<int> nd;
        nd.push_back(ND1);
        nd.push_back(ND2);
        nd.push_back(ND3);
        nd.push_back(ND4);
        nd.push_back(ND5);

        temp.vardas = vardas;
        temp.pavarde = pavarde;
        temp.nd = nd;
        temp.egzaminas = egzaminas;
        temp.galutinis = 0.4 * vidurkis(nd) + 0.6 * temp.egzaminas;
        studentai.push_back(temp);

        Studentas studClass(vardas, pavarde, nd, egzaminas);
        studentaiClass.push_back(studClass);
    }
    return studentai;
}

void dalijimas_struct(list<studentas> studentai)
{
    auto start_time = std::chrono::high_resolution_clock::now();
    int dydis = studentai.size();
    vector<studentas> vargšiukai;
    vector<studentas> kietiakiai;
    for (studentas stud : studentai)
    {
        if (stud.galutinis < 5)
        {
            vargšiukai.push_back(stud);
        }
        else
        {
            kietiakiai.push_back(stud);
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout << dydis << " STRUCT dalijimas: " << time / std::chrono::milliseconds(1) / 1000.0 << " sec" << endl;
}

void dalijimas_class(list<Studentas> studentai)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int dydis = studentai.size();
    vector<Studentas> vargšiukai;
    vector<Studentas> kietiakiai;
    for (Studentas stud : studentai)
    {
        if (stud.getRezultatas() < 5)
        {
            vargšiukai.push_back(stud);
        }
        else
        {
            kietiakiai.push_back(stud);
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    cout << dydis << " CLASS dalijimas: " << time / std::chrono::milliseconds(1) / 1000.0 << " sec" << endl;
}

void testuoti(int kiek)
{
    list<studentas> studentai;
    list<Studentas> studentaiClass;
    studentai = stud_generavimas(kiek, studentaiClass);
    dalijimas_struct(studentai);
    dalijimas_class(studentaiClass);
    cout << endl;
}