#include "Student.h"
#include "Persoana.h"
#include <iostream>
#include <cstring>
using namespace std;
Student::~Student()
{
    delete []facultate;
    delete []specializare;
}
Student::Student(const Student &stud):Persoana(stud,1),An_Studiu(stud.An_Studiu)
{
    delete []facultate;
    delete []specializare;
    facultate=new char[strlen(stud.facultate)+1];
    strcpy(facultate,stud.facultate);
    specializare=new char[strlen(stud.specializare)+1];
    strcpy(specializare,stud.specializare);
}
Student::Student(char *_nume,char *_prenume,char *_CNP,char *_numar_telefon,
                 char *_specializare,char *_facultate,int _An_Studiu):
            Persoana(_nume,_prenume,_CNP,_numar_telefon,1),An_Studiu(_An_Studiu)
{
    facultate=new char[strlen(_facultate)+1];
    strcpy(facultate,_facultate);
    specializare=new char[strlen(_specializare)+1];
    strcpy(specializare,_specializare);
}
Student::Student(Persoana &p,char *_specializare,char *_facultate,int _An_Studiu): Persoana(p,1),An_Studiu(_An_Studiu)
{
    facultate=new char[strlen(_facultate)+1];
    strcpy(facultate,_facultate);
    specializare=new char[strlen(_specializare)+1];
    strcpy(specializare,_specializare);
}
ostream& operator<<(ostream &ostr, Student &n )
{
    n.tip=1;
    ostr<<(Persoana &)n<<"\nAn studiu : "
        <<n.An_Studiu<<"\nSpecializare : "<<n.specializare<<"\nFacultate : "<<
        n.facultate<<endl<<endl;
    n.tip=0;
    return ostr;
}
istream& operator>>(istream &istr, Student &n )
{
    n.tip=1;

    istr>>(Persoana &)n;
    cout<<"Introduceti specializarea:";
    istr.getline(n.buf,51);
    delete []n.facultate;
    n.facultate=new char[strlen(n.buf)+1];
    strcpy(n.facultate,n.buf);

    cout<<"Introduceti facultatea:";
    istr.getline(n.buf,51);
    delete []n.specializare;
    n.specializare=new char[strlen(n.buf)+1];
    strcpy(n.specializare,n.buf);

    cout<<"Introduceti anul de studiu:";
    istr>>n.An_Studiu;
    cout<<endl;
    istr.ignore();
    return istr;
}
Student &Student::operator=(const Student &stud)
{
    if(this!=&stud)
    {
        tip=1;
        Persoana::operator=(stud);
        An_Studiu=stud.An_Studiu;
        delete []facultate;
        delete []specializare;
        facultate=new char[strlen(stud.facultate)+1];
        strcpy(facultate,stud.facultate);
        specializare=new char[strlen(stud.specializare)+1];
        strcpy(specializare,stud.specializare);
    }
    return *this;
}
