#include "Materie.h"

Materie::Materie() {
    nume_materie = "";
    nr_prezente = 0;
    note[0] = 0;
    note[1] = 0;
    note[2] = 0;
    media = 0;
}
Materie::Materie(string num, int nr_prez, int* no, float med) {
    nume_materie = num;
    nr_prezente = nr_prez;
    note[0] = no[0];
    note[1] = no[1];
    note[2] = no[2];
    media = med;
}
ostream& operator << (ostream& out, const Materie& x) {
    out << x.nume_materie << ";" << x.nr_prezente << ";" << x.note[0] << ";" << x.note[1] << ";" << x.note[2] << ";" << x.media;
    return out;
}
string Materie::getMaterie() {
    return nume_materie;
}
int Materie::getPrezente() {
    return nr_prezente;
}
float Materie::getMedia() {
    return media;
}
int Materie::getNota(int i) {
    return note[i];
}
void Materie::setNota(int i, int x) {
    note[i] = x;
}
void Materie::setMedia() {
    media = (note[0] + note[1] + note[2]) / 3.0;
}
void Materie::setPrezente(int x) {
    nr_prezente = x;
}
void Materie::print() {// doar pt teste
    cout << " " << nume_materie << " " << nr_prezente << " " << note[0] << " " << note[1] << " " << note[2] << " " << media;
}
void Materie::print2()
{
    cout << endl;
    cout << nume_materie << endl;
    cout << "Prezente: " << nr_prezente << endl;
    cout << "Nota 1: " << note[0] << ", Nota 2: " << note[1] << ", Nota 3: " << note[2] << endl;
    cout << "Media: " << media << endl;
    cout << endl;
}