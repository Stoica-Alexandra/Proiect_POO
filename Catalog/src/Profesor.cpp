#include "Profesor.h"
#include "Persoana.h"
#include <iostream>
#include <cstring>
using namespace std;
Profesor::Profesor(const Profesor &prof):Persoana(prof,2)
{
    titlu=new char[strlen(prof.titlu)+1];
    strcpy(titlu,prof.titlu);
}
Profesor::Profesor(char *_nume,char *_prenume,char *_CNP,char *_numar_telefon,
                   char _titlu[]):Persoana(_nume,_prenume,_CNP,_numar_telefon,2)
{
    titlu=new char[strlen(_titlu)+1];
    strcpy(titlu,_titlu);
}
Profesor::Profesor(Persoana &p,char _titlu[]):Persoana(p,2)
{
    delete []titlu;
    titlu=new char[strlen(_titlu)+1];
    strcpy(titlu,_titlu);
}
Profesor::~Profesor()
{
    delete []titlu;
}
ostream& operator<<(ostream &ostr, Profesor &n )
{
    n.tip=2;
    ostr<<(Persoana &)n<<"\nTitlu : "<<n.titlu<<endl<<endl;
    n.tip=0;
    return ostr;
}
istream& operator>>(istream &istr, Profesor &n )
{
    Titlu e_titlu;
    n.tip=2;

    int opt;
    istr>>(Persoana &)n;
    cout<<"1 profesor\n2 conferentiar\n3 s.l.\n4 asistent\n";
    do
    {   cout<<"Alegeti titlul:";
        istr>>opt;
    }
    while(opt<1||opt>4);
    e_titlu=static_cast<Titlu>(opt);
    n.SetenumtitluToString(e_titlu);
    istr.ignore();
    cout<<endl;
    return istr;
}
Profesor &Profesor::operator=(const Profesor &prof)
{
    if(this!=&prof)
    {
        tip=2;
        Persoana::operator=(prof);
        delete []titlu;
        titlu=new char[strlen(prof.titlu)+1];
        strcpy(titlu,prof.titlu);
    }
    return *this;
}
 void Profesor::SetenumtitluToString(Titlu t)
{
    char enum_titlu[20];
    switch (t)
    {
    case profesor:
        strcpy(enum_titlu,"profesor");
    case conferentiar:
        strcpy(enum_titlu,"conferentiar");
    case s_l:
        strcpy(enum_titlu,"s.l.");
    case asistent:
        strcpy(enum_titlu,"asistent");
    default:
        strcpy(enum_titlu,"nedefinit");
    }
    delete []titlu;
    titlu=new char[strlen(enum_titlu)+1];
    strcpy(titlu,enum_titlu);
}
