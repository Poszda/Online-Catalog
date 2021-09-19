#pragma once
#include <iostream>
#include <string>
using namespace std;

class Materie {
private:
    string nume_materie;
    int  nr_prezente;
    int note[3];
    float media;
public:
    Materie();
    Materie(string, int, int*, float);
    friend ostream& operator << (ostream&, const Materie&);
    string getMaterie();
    int getPrezente();
    float getMedia();
    int getNota(int i);
    void setNota(int i, int x);
    void setMedia();
    void setPrezente(int x);
    void print();
    void print2();
};
