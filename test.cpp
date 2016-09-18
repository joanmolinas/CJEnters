#include <iostream>
#include "cj_enters.hpp"
using namespace std;

string show_bool(bool b) {
    return b ? "true" : "false";
}

int main() {
    cj_enters a;
    a.insereix(1);
    a.insereix(2);
    a.print(cout);

    cout<<show_bool(a.conte(2))<<endl;
    cout<<show_bool(a.conte(-1))<<endl;
    cout<<show_bool(a.conte(5))<<endl;
    cout<<a.card()<<endl;

    cj_enters b;
    b.insereix(2);
    b.insereix(3);
    b.insereix(4);
    a.print(cout);

    cj_enters c = a + b;
    cj_enters c2 = a - b;
    cj_enters c3 = a * b;
    c.print(cout);
    c2.print(cout);
    c3.print(cout);


     cj_enters d;
     d.insereix(1);
     d.insereix(2);
     d.insereix(3);

     cj_enters e;
     e.insereix(1);
     e.insereix(2);
     e.insereix(4);

     cj_enters f = e;
     f.print(cout);

     bool equals = d!=e;
     cout<<"Differents "<<equals<<endl;


    return 0;
}
