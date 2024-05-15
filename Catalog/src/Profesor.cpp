#include "Profesor.h"
#include "Persoana.h"
#include <iostream>
#include <cstring>
using namespace std;

Profesor::Profesor(const Profesor &prof) : Persoana(prof, 2) {
    titlu = new char[strlen(prof.titlu) + 1];
    strcpy(titlu, prof.titlu);
}

Profesor::Profesor(char *_nume, char *_prenume, char *_CNP, char *_numar_telefon, const char *_titlu)
    : Persoana(_nume, _prenume, _CNP, _numar_telefon, 2) {
    titlu = new char[strlen(_titlu) + 1];
    strcpy(titlu, _titlu);
}

Profesor::Profesor(Persoana &p, const char *_titlu) : Persoana(p, 2) {
    titlu = new char[strlen(_titlu) + 1];
    strcpy(titlu, _titlu);
}

Profesor::~Profesor() {
    delete[] titlu;
}

ostream& operator<<(ostream &ostr, Profesor &n) {
    n.tip = 2;
    ostr << (Persoana &)n << "\nTitlu : " << n.titlu << endl << endl;
    n.tip = 0;
    return ostr;
}

istream& operator>>(istream &istr, Profesor &n) {
    int opt;
    n.tip = 2;
    istr >> (Persoana &)n;
    cout << "1 profesor\n2 conferentiar\n3 s.l.\n4 asistent\n";
    do {
        cout << "Alegeti titlul:";
        istr >> opt;
    } while (opt < 1 || opt > 4);

    const char* titluStr = Profesor::enumtitluToString(static_cast<Titlu>(opt));
    delete[] n.titlu;
    n.titlu = new char[strlen(titluStr) + 1];
    strcpy(n.titlu, titluStr);
    istr.ignore();
    cout << endl;
    return istr;
}

Profesor& Profesor::operator=(const Profesor &prof) {
    if (this != &prof) {
        tip = 2;
        Persoana::operator=(prof);
        delete[] titlu;
        titlu = new char[strlen(prof.titlu) + 1];
        strcpy(titlu, prof.titlu);
    }
    return *this;
}

const char* Profesor::enumtitluToString(Titlu t) {
    switch (t) {
        case profesor:
            return "profesor";
        case conferentiar:
            return "conferentiar";
        case s_l:
            return "s.l.";
        case asistent:
            return "asistent";
        default:
            return "nedefinit";
    }
}
