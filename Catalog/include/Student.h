#ifndef STUDENT_H
#define STUDENT_H
#include "Persoana.h"
#include <iostream>
#include <cstring>
using namespace std;

class Student:public Persoana
{   private:
        char buf[50];
        int An_Studiu,note[50];
        char *specializare=nullptr,*facultate=nullptr;

    public:
        Student();
        Student(const Student &stud);
        Student(char *_nume=(char *)"_nedefinit_",char *_prenume=(char *)"_nedefinit_",
                char *_CNP=(char *)"_nedefinit_",char *_numar_telefon=(char *)"_nedefinit_",
                char *_specializare=(char *)"_nedefinit_",char *_facultate=(char *)"_nedefinit_",
                int _An_Studiu=0);
        Student(Persoana &p,char *_specializare,char *_facultate,int _An_Studiu);
        virtual ~Student();
        friend ostream& operator<<(ostream &ostr, Student &n );
        friend istream& operator>>(istream &istr, Student &n );
        Student &operator=(const Student &stud);

};

#endif // STUDENT_H
