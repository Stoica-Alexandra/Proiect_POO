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
    Student s("Pop","A Maria","6030318330253","0743334544","C","FIESC",1);
    cout<<s;
    cin>>s;
    cout<<s;
    Profesor pr(p,Titlu::profesor);
    cout<<pr;
    cin>>pr;
    cout<<pr;
    return 0;
}
