#include "Profesor.h"

    Profesor::Profesor() :Persoana() {
    }
    Profesor::Profesor(string num, string pren, int idd, string user, string par, string mat) :Persoana(num, pren, idd, user, par) {
        materie_prof = mat;
    }
    string Profesor::getMaterie() {
        return materie_prof;
    }
    void Profesor::afisare() {
        cout << nume << " " << prenume << " " << id << " " << username << " " << parola << " " << materie_prof << endl;
    }

