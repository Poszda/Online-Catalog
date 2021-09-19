#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <vector>
#include "Persoana.h"
#include "Materie.h"
#include "Elev.h"
#include "Profesor.h"
using namespace std;
bool ok_prof = false;
bool ok_elev = false;
string global_username;
string global_parola;

void stergere_id_prof(int id)
{
    ifstream coduri_prof("coduriprof.txt");
    ofstream temp("temp.txt");

    int id_existent;

    while (coduri_prof >> id_existent)
    {
        if (id_existent != id)
        {
            temp << id_existent << endl;
        }
    }

    coduri_prof.close();
    temp.close();
    remove("coduriprof.txt");
    rename("temp.txt", "coduriprof.txt");
}

void stergere_id_elev(int id)
{
    ifstream coduri_elev("codurielev.txt");
    ofstream temp("temp.txt");

    int id_existent;        // toate codurile care sunt in fisier

    while (coduri_elev >> id_existent)
    {
        if (id_existent != id)
        {
            temp << id_existent << endl;        // scriem in fisierul temp toate codurile - inafara de cel folosit
        }
    }

    coduri_elev.close();
    temp.close();
    remove("codurielev.txt");
    rename("temp.txt", "codurielev.txt");        // redenumim temp pentru a nu fi observata diferenta

}

bool verificare_username_elev(string username)
{
    char username_existent[500];
    char rand[500];
    char cuvant[500];
    char* username_introdus = new char[username.length() + 1];
    strcpy(username_introdus, username.c_str());
    char* Token;
    int k;
    int ok;
    ok = 0;


    ifstream fisier_elev("elev.txt");

    while (fisier_elev >> rand)
    {

        strcpy(cuvant, rand);
        Token = strtok(cuvant, ";");
        k = 0;

        while (Token)
        {

            k = k + 1;

            if ((k == 4) && (strcmp(Token, username_introdus) == 0))
            {
                ok = 1;
            }
            else
                if ((k == 4) && (strcmp(Token, username_introdus) != 0))
                    break;

            Token = strtok(NULL, ";");


        }


    }

    fisier_elev.close();

    return ok;

}

bool verificare_username_profesor(string username)
{
    char rand[500];
    char cuvant[500];
    char* username_introdus = new char[username.length() + 1];
    strcpy(username_introdus, username.c_str());
    char* token;
    int k;
    int ok = 0;

    ifstream fisier_prof("prof.txt");

    while (fisier_prof >> rand)
    {
        strcpy(cuvant, rand);
        token = strtok(cuvant, ";");
        k = 0;
        while (token)
        {
            k++;
            if ((k == 4) && (strcmp(token, username_introdus) == 0))
            {
                ok = 1;
            }
            token = strtok(NULL, ";");
        }
    }
    fisier_prof.close();
    return ok;

}


void scriere_fisier_elev()
{
    ofstream myfile;
    myfile.open("elev.txt", std::ios_base::app);

    string nume_elev;
    string prenume_elev;
    string parola;
    string username;
    int id;
    int id2;
    int ok = 0;
    bool username_folosit = 0;

    cout << "Introduceti nume:";
    cin >> nume_elev;
    cout << "Introduceti prenume: ";
    cin >> prenume_elev;
    cout << "Introduceti ID: ";
    cin >> id;

    //  myfile.close();
    do
    {
        cout << "Introduceti un username: ";
        cin >> username;



        username_folosit = verificare_username_elev(username);

        if (username_folosit == 1)
        {
            cout << "Username-ul este folosit deja de catre un alt utilizator." << endl;
        }

    } while (username_folosit == 1);

    cout << "Introduceti parola dvs: ";
    cin >> parola;
    ifstream coduri_elev("codurielev.txt");
    while (coduri_elev >> id2) {
        if (id2 == id) { ok = 1; break; }
    }
    if (ok == 1)
    {
        myfile << nume_elev << ";" << prenume_elev << ";" << id << ";" << username << ";" << parola << ";";
        myfile << "Informatica;0;0;0;0;0;Matematica;0;0;0;0;0;ASD;0;0;0;0;0;SP;0;0;0;0;0;Programare;0;0;0;0;0;" << endl;
        coduri_elev.close();
        myfile.close();

        stergere_id_elev(id);
        cout << "Contul a fost creat cu succes"<<endl<< endl;
    }
    else cout << "Nu ai dreptul sa te autetifici ca elev   -  ID incorect" << endl;

}

void scriere_fisier_profesor()
{
    ofstream myfile;
    myfile.open("prof.txt", std::ios_base::app);

    string nume_prof;
    string prenume_prof;
    string username;
    string parola;
    string materie_prof;
    int id;
    int id2;
    int ok = 0;
    bool username_folosit;

    cout << "Introduceti nume:";
    cin >> nume_prof;
    cout << "Introduceti prenume: ";
    cin >> prenume_prof;
    cout << "Introduceti ID: ";
    cin >> id;
    //  myfile.close();
    do
    {
        cout << "Introduceti un username: ";
        cin >> username;


        username_folosit = verificare_username_profesor(username);
        if (username_folosit == 1)
        {
            cout << "Username-ul este folosit deja de catre un alt utilizator." << endl;
        }

    } while (username_folosit == 1);

    cout << "Introduceti parola dvs: ";
    cin >> parola;
    cout << "Introduceti materia pe care o predati:";
    cin >> materie_prof;

    ifstream coduri_prof("coduriprof.txt");
    while (coduri_prof >> id2) {
        if (id2 == id) { ok = 1; break; }
    }
    if (ok == 1)
    {
        myfile << nume_prof << ";" << prenume_prof << ";" << id << ";" << username << ";" << parola << ";" << materie_prof << ";" << endl;

        coduri_prof.close();
        myfile.close();

        stergere_id_prof(id);
        cout<< "Contul a fost creat cu succes"<<endl<<endl;
    }
    else cout << "Nu ai dreptul sa te autetifici ca profesor   -   ID incorect" << endl;

}

void scriere_fisier() {
    cout << "1 - creati cont de profesor" << endl;
    cout << "2 - creati un cont de elev" << endl;
    int optiune;
    cin >> optiune;
    if (optiune == 1) scriere_fisier_profesor();
    else if (optiune == 2) scriere_fisier_elev();
}

Elev login_elev() {
    Elev x;
    string username;
    string parola;
    if (ok_elev == false)
    {
        cout << "Introduceti username-ul: ";
        cin >> username;
        cout << "Introduceti parola: ";
        cin >> parola;
        cout << endl;
    }
    else
    {
        username = global_username;
        parola = global_parola;
    }
    string line;
    ifstream myfile("elev.txt");
    while (myfile >> line) {
        Materie materii[5];
        vector <string> tokens;
        stringstream check1(line);
        string intermediate;
        while (getline(check1, intermediate, ';'))
            tokens.push_back(intermediate);

        if (tokens[3] == username && tokens[4] == parola)
        {
            global_username = username;
            global_parola = parola;
            ok_elev = true; // deci este logat (modific variabila globala)
            for (int j = 0; j < 5; j++) // citesc cele 5 materii
            {
                int note[3];
                note[0] = stoi(tokens[7 + 6 * j]);
                note[1] = stoi(tokens[8 + 6 * j]);
                note[2] = stoi(tokens[9 + 6 * j]);
                materii[j] = Materie(tokens[5 + 6 * j], stoi(tokens[6 + 6 * j]), note, stod(tokens[10 + 6 * j]));
            }
            x = Elev(tokens[0], tokens[1], stoi(tokens[2]), tokens[3], tokens[4], materii); //creez elevul
            break;
        }
    }
    myfile.close();
    return x;
}

void user_elev() {
    Elev x = login_elev();
    if (ok_elev == false) {
        cout << "Username-ul si parola sunt incorecte. Reincercati?" << endl;
    }
    if (ok_elev == true) {
        cout << "0 - Log out" << endl;
        cout << "1 - Afiseaza datele contului" << endl;
        cout << "2 - Afiseaza situatia scolara" << endl << endl;

        int optiune;
        cin >> optiune;
        if (optiune == 0) {}
        else if (optiune == 1)
        {
            cout << "Nume: " << x.getNume() << endl;
            cout << "Prenume: " << x.getPrenume() << endl;
            cout << "ID: " << x.getID() << endl;
            cout << "Username: " << x.getUsername() << endl;
            cout << "Parola:" << x.getParola() << endl;
            cout << endl;
            user_elev();
        }
        else if (optiune == 2)
        {
            for (int i = 0; i < 5; i++)
            {
                //cout << "Materie: " << x.getVect(i).getMaterie() << "\tNota 1: " << x.getVect(i).getNota(0) << "\tNota 2: " << x.getVect(i).getNota(1) << "\tNota 3: " << x.getVect(i).getNota(2) << endl;
                for (int j = 1; j < (15 - x.getVect(i).getMaterie().length()) / 2; j++)
                    cout << " ";
                cout << x.getVect(i).getMaterie();
                for (int j = 1; j < (15 - x.getVect(i).getMaterie().length()) / 2; j++)
                    cout << " ";
                cout << "\tNota 1: " << x.getVect(i).getNota(0) << "\tNota 2: " << x.getVect(i).getNota(1) << "\tNota 3: " << x.getVect(i).getNota(2) << " \t Media: " << x.getVect(i).getMedia() << endl;
            }

            cout << endl;
            user_elev();
        }
    }
}


int nr_linii_fisier() {
    int nr = 0;
    string line;
    ifstream myfile("elev.txt");
    while (myfile >> line) {
        nr++;
    }
    myfile.close();
    return nr;
}




void istoric_note(string nume, string prenume, int nota, string mat)
{
    ofstream myFile;
    myFile.open("istoric.txt", std::ios_base::app);

    myFile << nume << " " << prenume << " a primit nota " << nota << " la materia " << mat << ";" << endl;

    myFile.close();
}

void istoric_schimbare_note(string nume, string prenume, int nota_veche, int nota_noua, string mat)
{
    ofstream myFile;
    myFile.open("istoric.txt", std::ios_base::app);


    myFile << nume << " " << prenume << " a primit nota " << nota_noua << " in locul notei " << nota_veche << " la materia " << mat << ";" << endl;

    myFile.close();
}

void istoric_prezente(string nume, string prenume, int prezente, string mat)
{
    ofstream myFile;
    myFile.open("istoric.txt", std::ios_base::app);


    myFile << nume << " " << prenume << " are " << prezente << " prezente la materia " << mat << ";" << endl;

    myFile.close();
}

void vizualizare_istoric()
{
    ifstream myFile;
    myFile.open("istoric.txt");
    string line;

    while (getline(myFile, line))
    {
        cout << line << endl;

    }
    cout << endl;

}


void cauta_elev(string materie_profesor) {
    int n = nr_linii_fisier(), i = -1;
    Elev* all; // vectorul de elevi
    all = new Elev[n];
    string line;
    ifstream myfile("elev.txt");

    while (myfile >> line)
    {
        vector <string> tokens;
        stringstream check1(line);
        string intermediate;

        while (getline(check1, intermediate, ';'))
        {
            tokens.push_back(intermediate);
        }

        i++;
        Materie x[5];

        for (int j = 0; j < 5; j++) // citesc cele 5 materii
        {
            int note[3];
            note[0] = stoi(tokens[7 + 6 * j]);
            note[1] = stoi(tokens[8 + 6 * j]);
            note[2] = stoi(tokens[9 + 6 * j]);
            x[j] = Materie(tokens[5 + 6 * j], stoi(tokens[6 + 6 * j]), note, stod(tokens[10 + 6 * j]));
        }

        all[i] = Elev(tokens[0], tokens[1], stoi(tokens[2]), tokens[3], tokens[4], x); //creez elevii
    }

    myfile.close();
    string nume_elev, prenume_elev;
    bool ok = false;
    int k;
    cout << "Numele elevului: ";
    cin >> nume_elev;
    cout << "Prenumele elevului: ";
    cin >> prenume_elev;
    for (i = 0; i < n; i++)
        if (nume_elev == all[i].getNume() && prenume_elev == all[i].getPrenume()) { ok = true; k = i; }
    if (ok == false) {
        cout << "Elev inexistent" << endl;
        cauta_elev(materie_profesor);
    }
    else if (ok == true)
    {

        all[k].print2(materie_profesor);


        //all[k].print();
        int optiune;
        do {
            cout << "1 - Adauga o nota studentului" << endl;
            cout << "2 - Modifica o nota a studentului" << endl;
            cout << "3 - Adauga numarul de prezente" << endl;
            cout << "4 - Inapoi la meniul tau" << endl;
            cin >> optiune; // aici am de adaugat
            if (optiune == 1)
            {
                int nota_noua, poz = -1;
                cout << "Introduceti o nota: ";
                cin >> nota_noua;
                for (i = 0; i < 5; i++)
                {
                    if (all[k].getVect(i).getMaterie() == materie_profesor)
                    {
                        if (all[k].getVect(i).getNota(0) == 0) { poz = 0; break; }
                        if (all[k].getVect(i).getNota(1) == 0) { poz = 1; break; }
                        if (all[k].getVect(i).getNota(2) == 0) { poz = 2; break; }
                    }
                }
                // i este indicele materiei si poz e indicele notei
                if (poz != -1)
                {
                    all[k].setVect(i, poz, nota_noua); // am modificat nota
                    all[k].setVectMedia(i);
                    //  all[k].print();
                    all[k].print2(materie_profesor);

                    istoric_note(nume_elev, prenume_elev, nota_noua, materie_profesor);



                    cout << "Nota a fost acordata cu succes" << endl;
                    ofstream myfile("elev.txt"); // pun in fisier
                    for (i = 0; i < n; i++)
                        myfile << all[i];
                    myfile.close();
                }
                else { cout << "Nu puteti acorda mai mult de 3 note" << endl; }


            }


            else if (optiune == 2)
            {
                int nota_noua, nota_veche, poz = -1;
                cout << "Introduceti nota pe care doriti sa o modificati: ";
                cin >> nota_veche;
                cout << "Introduceti nota noua: ";
                cin >> nota_noua;
                for (i = 0; i < 5; i++)
                    if (all[k].getVect(i).getMaterie() == materie_profesor)
                    {
                        if (all[k].getVect(i).getNota(0) == nota_veche) { poz = 0; break; }
                        if (all[k].getVect(i).getNota(1) == nota_veche) { poz = 1; break; }
                        if (all[k].getVect(i).getNota(2) == nota_veche) { poz = 2; break; }
                    }
                if (poz != -1)
                {
                    all[k].setVect(i, poz, nota_noua);
                    all[k].setVectMedia(i);
                    cout << "Nota a fost modificata cu succes" << endl;
                    //all[k].print();
                    all[k].print2(materie_profesor);

                    istoric_schimbare_note(nume_elev, prenume_elev, nota_veche, nota_noua, materie_profesor);

                    ofstream myfile("elev.txt");
                    for (i = 0; i < n; i++)
                        myfile << all[i];
                    myfile.close();

                }
                else { cout << "Modificarea nu a avut succes" << endl; }
            }


            else if (optiune == 3)
            {
                int prezente;
                cout << "Introduceti numarul de prezente ale studentului" << endl;
                cin >> prezente;
                for (i = 0; i < 5; i++)
                    if (all[k].getVect(i).getMaterie() == materie_profesor)
                    {
                        all[k].setVectPrezente(i, prezente);
                        //all[k].print();
                        all[k].print2(materie_profesor);
                        istoric_prezente(nume_elev, prenume_elev, prezente, materie_profesor);

                        cout << "Modificarea a avut succes" << endl;

                    }
            }


            else if (optiune == 4) {

            }
        } while (optiune != 4);
    }
}



Profesor login_profesor() // cauta in baza de date profesorul si il returneaza daca il gaseste
{
    Profesor x;
    string username;
    string parola;
    if (ok_prof == false)//global_username == "" && global_parola == "" // daca nu esti conectat
    {
        cout << "Introduceti username-ul: ";
        cin >> username;
        cout << "Introduceti parola: ";
        cin >> parola;
    }
    else
    {
        username = global_username;
        parola = global_parola;
    }
    string line;
    ifstream myfile("prof.txt");
    while (myfile >> line) {
        vector <string> tokens;
        stringstream check1(line);
        string intermediate;
        while (getline(check1, intermediate, ';'))
            tokens.push_back(intermediate);

        if (tokens[3] == username && tokens[4] == parola)
        {
            global_username = username;
            global_parola = parola;
            ok_prof = true; // deci este logat (modific variabila globala)
            x = Profesor(tokens[0], tokens[1], stoi(tokens[2]), tokens[3], tokens[4], tokens[5]);
            break;
        }
    }
    myfile.close();
    return x;
}



void user_profesor() {

    Profesor x = login_profesor();
    if (ok_prof == false) {
        cout << "Username-ul si parola sunt incorecte. Reincercati?" << endl;
    }
    if (ok_prof == true) {
        cout << "0 - Log out" << endl;
        cout << "1 - Informatiile mele" << endl;
        cout << "2 - Cauta un elev" << endl;
        cout << "3 - Vizualizare istoric general" << endl;
        int optiune;
        cin >> optiune;
        switch (optiune)
        {
        case 0:
            break;
        case 1:
            cout << "Nume: " << x.getNume() << endl;
            cout << "Prenume: " << x.getPrenume() << endl;
            cout << "ID: " << x.getID() << endl;
            cout << "Username: " << x.getUsername() << endl;
            cout << "Parola: " << x.getParola() << endl;
            cout << endl;
            user_profesor();
            break;

        case 2:
            cauta_elev(x.getMaterie());
            user_profesor();
            break;

        case 3:
            vizualizare_istoric();
            user_profesor();
        default:
            break;
        }

    }
}



int main() {
    int optiune;
    do {
        cout << "Conecteaza-te ca: " << endl;
        cout << "1 - Elev" << endl;
        cout << "2 - Profesor" << endl;
        cout << "3 - Creeaza cont" << endl;
        cout << "0 - Exit" << endl;

        cin >> optiune;
        if (optiune == 1)
        {
            ok_elev = false;
            user_elev();
        }
        else if (optiune == 2)
        {
            ok_prof = false;
            user_profesor();
        }
        else if (optiune == 3)
        {
            scriere_fisier();
        }

    } while (optiune != 0);
}