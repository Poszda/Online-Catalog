#pragma once
#include <iostream>
#include <string>
using namespace std;
class Persoana
{
protected:
    string nume;
    string prenume;
    string username;
    string parola;
    int id;
public:
    Persoana();
    Persoana(string, string, int, string, string);
    string getNume();
    string getPrenume();
    string getUsername();
    string getParola();
    int getID();
};

