#ifndef PROFESOR_H
#define PROFESOR_H
#include "Persoana.h"
#include <iostream>
#include <cstring>
using namespace std;
enum Titlu
{
    nedefinit=0,
    profesor=1,
    conferentiar=2,
    s_l=3,
    asistent=4
};
class Profesor:public Persoana
{
    private:
        char buf[50];
        Titlu e_titlu;/* profesor / conferentiar / s.l. / asistent */
        //char titlu[20];
    public:
        Profesor();
        Profesor(const Profesor &prof);
        Profesor(char *_nume=(char *)"_nedefinit_",char *_prenume=(char *)"_nedefinit_",
                char *_CNP=(char *)"_nedefinit_",char *_numar_telefon=(char *)"_nedefinit_",
                Titlu _titlu=Titlu::nedefinit);
        Profesor(Persoana &p,Titlu _titlu);
        virtual ~Profesor();
        friend ostream& operator<<(ostream &ostr, Profesor &n );
        friend istream& operator>>(istream &istr, Profesor &n );
        Profesor &operator=(const Profesor &prof);
        char* enumtitluToString(Titlu t);
};

#endif // PROFESOR_H
