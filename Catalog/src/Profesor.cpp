#include "Profesor.h"
#include "Persoana.h"
#include <iostream>
#include <cstring>
using namespace std;
Profesor::Profesor(const Profesor &prof):Persoana(prof,2),e_titlu(prof.e_titlu) {}
Profesor::Profesor(char *_nume,char *_prenume,char *_CNP,char *_numar_telefon,
                   Titlu _titlu):Persoana(_nume,_prenume,_CNP,_numar_telefon,2),
    e_titlu(_titlu) {}
Profesor::Profesor(Persoana &p,Titlu _titlu):Persoana(p,2),e_titlu(_titlu) {}
Profesor::~Profesor() {}
ostream& operator<<(ostream &ostr, Profesor &n )
{
    n.tip=2;
    ostr<<(Persoana &)n<<"\nTitlu : "<<n.enumtitluToString(n.e_titlu)<<endl<<endl;
    n.tip=0;
    return ostr;
}
istream& operator>>(istream &istr, Profesor &n )
{
    n.tip=2;

    int opt;
    istr>>(Persoana &)n;
    cout<<"1 profesor\n2 conferentiar\n3 s.l.\n4 asistent\n";
    do
    {   cout<<"Alegeti titlul:";
        istr>>opt;
    }
    while(opt<1||opt>4);
    n.e_titlu=static_cast<Titlu>(opt);
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
        e_titlu=prof.e_titlu;
    }
    return *this;
}
char* Profesor::enumtitluToString(Titlu t)
{
    switch (t)
    {
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
