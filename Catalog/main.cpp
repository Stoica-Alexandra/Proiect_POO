#include "Student.h"
#include "Persoana.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Persoana p("Pop","A Maria","6030318330253","0743334544");
    cout<<p<< endl;
    Persoana a("Pop","Ana-Maria","6030318330253","0743334544");
    cout<<a<< endl;
    cin>>a;
    cout<<a<< endl;
    Student s("Pop","A Maria","6030318330253","0743334544","C","FIESC",1);
    cout<<s;
    Student ss("Popa","A Maria","6030318330253","0743334544","C","FIESC",1);
    cout<<ss;
    cout<<a<< endl;
    s=ss;
    cout<<s;
    Student fv(s);
    cout<<fv;
    cin>>s;
    cout<<s;
    return 0;
}
