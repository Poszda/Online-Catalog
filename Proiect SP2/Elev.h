#pragma once
#include "Persoana.h"
#include <iostream>
#include "Materie.h"
#include <string>

class Elev : public Persoana
{
private:
    Materie vect[5];
public:
    Elev();
    Elev(string, string, int, string, string, Materie*);
    friend ostream& operator << (ostream&, const Elev&);
    void print();//doar pt teste

    void print2(string);

    Materie getVect(int);
    void setVect(int, int, int);
    void setVectMedia(int);
    void setVectPrezente(int, int);
};

