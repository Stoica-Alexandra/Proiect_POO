#include "Persoana.h"
#include <iostream>
#include <cstring>
using namespace std;
char* mic(char* str);
char * Persoana::Get_parola()
{
    return parola;
}
void Persoana::Set_email(char *_nume,char *_prenume)
{
    char domeniu[50];
    if(tip==2)
        strcpy(domeniu,"usm.ro");
    else if(tip==1)
        strcpy(domeniu,"student.usv.ro");
    else
        strcpy(domeniu,"nedefinit");
    char *copienume=new char[strlen(_nume)+1];
    strcpy(copienume,_nume);
    char *copieprenume=new char[strlen(_prenume)+1];
    strcpy(copieprenume,_prenume);

    char *s=strtok(copieprenume," -");

    sprintf(buf,"%s.%s@%s",mic(s),mic(copienume),domeniu);
    email=new char[strlen(buf)+1];
    strcpy(email,buf);
    delete []copienume;
    delete []copieprenume;
}
void Persoana::Set_parola(char *_CNP)
{
    //Student123456
    char domeniu[50];
    if(tip==2)
        strcpy(domeniu,"Profesor");
    else if(tip==1)
        strcpy(domeniu,"Student");
    else
        strcpy(domeniu,"Nedefinit");

    delete []parola;
    char *copieCNP=new char[7];
    strncpy(copieCNP,_CNP+7,6);
    copieCNP[6] = '\0';

    sprintf(buf,"%s%s",domeniu,copieCNP);
    parola=new char[strlen(buf)+1];
    strcpy(parola,buf);
    delete []copieCNP;
}

Persoana::Persoana(char *_nume,char *_prenume,char *_CNP,char *_numar_telefon,int _tip):tip(_tip)
{
    nume=new char[strlen(_nume)+1];
    strcpy(nume,_nume);
    prenume=new char[strlen(_prenume)+1];
    strcpy(prenume,_prenume);
    CNP=new char[strlen(_CNP)+1];
    strcpy(CNP,_CNP);
    numar_telefon=new char[strlen(_numar_telefon)+1];
    strcpy(numar_telefon,_numar_telefon);
    Set_email(_nume,_prenume);
    Set_parola(_CNP);
}
Persoana::Persoana(const Persoana &pers,int _tip):tip(_tip)
{
    if(this!=&pers)
    {
        delete []nume;
        delete []prenume;
        delete []CNP;
        delete []numar_telefon;
        delete []email;
        delete []parola;
        nume=new char[strlen(pers.nume)+1];
        strcpy(nume,pers.nume);
        prenume=new char[strlen(pers.prenume)+1];
        strcpy(prenume,pers.prenume);
        CNP=new char[strlen(pers.CNP)+1];
        strcpy(CNP,pers.CNP);
        numar_telefon=new char[strlen(pers.numar_telefon)+1];
        strcpy(numar_telefon,pers.numar_telefon);
        Set_email(pers.nume,pers.prenume);
        Set_parola(pers.CNP);
    }
}
Persoana::~Persoana()
{
    delete []nume;
    delete []prenume;
    delete []CNP;
    delete []numar_telefon;
    delete []email;
    delete []parola;
}
Persoana&Persoana:: operator=(const Persoana &pers)
{
    if(this!=&pers)
    {
        delete []nume;
        delete []prenume;
        delete []CNP;
        delete []numar_telefon;
        delete []email;
        delete []parola;
        nume=new char[strlen(pers.nume)+1];
        strcpy(nume,pers.nume);
        prenume=new char[strlen(pers.prenume)+1];
        strcpy(prenume,pers.prenume);
        CNP=new char[strlen(pers.CNP)+1];
        strcpy(CNP,pers.CNP);
        numar_telefon=new char[strlen(pers.numar_telefon)+1];
        strcpy(numar_telefon,pers.numar_telefon);
        Set_email(pers.nume,pers.prenume);
        Set_parola(pers.CNP);
    }
    return *this;
}
ostream& operator<<(ostream &ostr, Persoana &n )
{
    ostr<<"Nume : "<<n.nume<<"\nPrenume : "<<n.prenume<<"\nEmail : "<<n.email<<
        "\nCNP : "<<n.CNP<<"\nNr_telefon : "<<n.numar_telefon;
    if(n.tip==false)
        ostr<<"\n\n";
    return ostr;
}
istream& operator>>(istream &istr, Persoana &n )
{
    cout<<"Introduceti numele:";
    istr.getline(n.buf,51);
    delete []n.nume;
    n.nume=new char[strlen(n.buf)+1];
    strcpy(n.nume,n.buf);

    cout<<"Introduceti prenumele:";
    istr.getline(n.buf,51);
    delete []n.prenume;
    n.prenume=new char[strlen(n.buf)+1];
    strcpy(n.prenume,n.buf);

    do
    {
        cout<<"Introduceti CNP-ul:";
        istr.getline(n.buf,51);
    }
    while(strlen(n.buf)!=13);
    delete []n.CNP;
    n.CNP=new char[strlen(n.buf)+1];
    strcpy(n.CNP,n.buf);

    cout<<"Introduceti numarul de telefon:";
    istr.getline(n.buf,51);
    delete []n.numar_telefon;
    n.numar_telefon=new char[strlen(n.buf)+1];
    strcpy(n.numar_telefon,n.buf);
    delete []n.parola;
    delete []n.email;
    n.Set_email(n.nume,n.prenume);
    n.Set_parola(n.CNP);
    if(n.tip==0)
    {
        cout<<endl;
        istr.ignore();
    }
    return istr;

}
char *mic(char* str)
{
    int n=strlen(str);
    for(int i=0; i<n; i++)
        str[i]=tolower(str[i]);
    return str;
}
void Persoana::Set_nume(char *_nume)
{
    delete []nume;
    nume=new char[strlen(_nume)+1];
    strcpy(nume,_nume);
}
void Persoana::Set_prenume(char *_prenume)
{
    delete []prenume;
    prenume=new char[strlen(_prenume)+1];
    strcpy(prenume,_prenume);
}
void Persoana::Set_CNP(char *_CNP)
{
    delete []CNP;
    CNP=new char[strlen(_CNP)+1];
    strcpy(CNP,_CNP);
}
void Persoana::Set_numar_telefon(char *_numar_telefon)
{
    delete []numar_telefon;
    numar_telefon=new char[strlen(_numar_telefon)+1];
    strcpy(numar_telefon,_numar_telefon);
}
