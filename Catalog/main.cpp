#include "Student.h"
#include "Persoana.h"
#include "Profesor.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    Persoana p("Pop","A Maria","6030318330253","0743334544");
    cout<<p<< endl;
    cout<<"\n"<<p.Get_parola()<<"\n\n";
    Student s("Pop","A Maria","6030318330253","0743334544","C","FIESC",1);
    cout<<s;
    cout<<"\n"<<s.Get_parola()<<"\n\n";
    cin>>s;
    cout<<s;
    cout<<"\n"<<s.Get_parola()<<"\n\n";
    Student ss(p,"a","a",2);
    cout<<ss;
    cout<<"\n"<<ss.Get_parola()<<"\n\n";
    Profesor pr(p,Titlu::profesor);
    cout<<pr;
    cout<<"\n"<<pr.Get_parola()<<"\n\n";
    cin>>pr;
    cout<<pr;
    cout<<"\n"<<pr.Get_parola()<<"\n\n";
    return 0;
}
