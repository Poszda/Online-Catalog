#include "Persoana.h"
Persoana::Persoana() {
    nume = "";
    prenume = "";
    parola = "";
    id = 0;
}
Persoana::Persoana(string num, string pren, int idd, string user, string par) {
    nume = num;
    prenume = pren;
    username = user;
    parola = par;
    id = idd;
}
string Persoana::getNume()
{
    return string();
}
string Persoana::getPrenume() {
    return prenume;
}
string Persoana::getUsername() {
    return username;
}
string Persoana::getParola() {
    return parola;
}
int Persoana::getID() {
    return id;
}