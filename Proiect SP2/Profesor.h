#pragma once
#include <iostream>
#include <string>
#include "Persoana.h"
class Profesor : public Persoana
{
private:
    string materie_prof;
public:
    Profesor();
    Profesor(string, string, int, string, string, string);
    string getMaterie();
    void afisare();
};

