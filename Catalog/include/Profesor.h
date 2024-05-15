#ifndef PROFESOR_H
#define PROFESOR_H

#include "Persoana.h"
#include <iostream>
#include <cstring>

using namespace std;

enum Titlu {
    nedefinit = 0,
    profesor = 1,
    conferentiar = 2,
    s_l = 3,
    asistent = 4
};

class Profesor : public Persoana {
private:
    char *titlu;
public:
    Profesor();
    Profesor(const Profesor &prof);
    Profesor(char *_nume, char *_prenume, char *_CNP, char *_numar_telefon, const char *_titlu);
    Profesor(Persoana &p, const char *_titlu);
    virtual ~Profesor();
    Profesor& operator=(const Profesor &prof);
    friend ostream& operator<<(ostream &ostr, Profesor &n);
    friend istream& operator>>(istream &istr, Profesor &n);
    static const char* enumtitluToString(Titlu t);
};

#endif // PROFESOR_H
