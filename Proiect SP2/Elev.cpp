#include "Elev.h"
Elev::Elev() :Persoana()
{

}
Elev::Elev(string num, string pren, int idd, string user, string par, Materie* v) :Persoana(num, pren, idd, user, par) {
    vect[0] = v[0];
    vect[1] = v[1];
    vect[2] = v[2];
    vect[3] = v[3];
    vect[4] = v[4];
}
ostream& operator << (ostream& out, const Elev& x) {
    out << x.nume << ";" << x.prenume << ";" << x.id << ";" << x.username << ";" << x.parola << ";";
    out << x.vect[0] << ";" << x.vect[1] << ";" << x.vect[2] << ";" << x.vect[3] << ";" << x.vect[4] << ";" << endl;
    return out;

}
void Elev::print() { //doar pt teste
    cout << nume << " " << prenume << " " << id << " " << username << " " << parola;
    vect[0].print();
    vect[1].print();
    vect[2].print();
    vect[3].print();
    vect[4].print();
    cout << endl;
}

void Elev::print2(string mat)
{
    for (int i = 1; i < 5; i++)
        if (vect[i].getMaterie() == mat)
            vect[i].print2();
}

Materie Elev::getVect(int i) {
    return vect[i];
}
void Elev::setVect(int i, int poz, int x) {
    vect[i].setNota(poz, x);
}
void Elev::setVectMedia(int i) {
    vect[i].setMedia();
}
void Elev::setVectPrezente(int i, int x) {
    vect[i].setPrezente(x);
}
