#ifndef PERSOANA_H
#define PERSOANA_H
#include <iostream>
#include <cstring>
using namespace std;
class Persoana
{
    private:
        char buf[50];
    protected:
        char *nume=nullptr,*prenume=nullptr,*CNP=nullptr,*numar_telefon=nullptr;
        char *email=nullptr;
        char *parola=nullptr;
        char email_personal[30];
        char adresa[30];

    public:
        int tip=0;
        Persoana();
        Persoana(const Persoana &pers,int _tip=0);
        Persoana(char *_nume=(char *)"_nedefinit_",char *_prenume=(char *)"_nedefinit_",
                 char *_CNP=(char *)"_nedefinit_",char *_numar_telefon=(char *)"_nedefinit_",
                 int _tip=0);
        virtual ~Persoana();
        friend ostream& operator<<(ostream &ostr, Persoana &n );
        friend istream& operator>>(istream &istr, Persoana &n );
        void Set_email(char *_nume,char *_prenume);
        void Set_nume(char *_nume);
        void Set_prenume(char *_prenume);
        void Set_CNP(char *_CNP);
        void Set_parola(char *_CNP);
        char * Get_parola();
        void Set_numar_telefon(char *_numar_telefon);
        Persoana &operator=(const Persoana &pers);
};

#endif // PERSOANA_H
