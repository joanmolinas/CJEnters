#include <iostream>
#include "cj_enters.hpp"
using namespace std;

int main() {
	cj_enters a;

	a.insereix(4);
	a.insereix(5);

	cj_enters b;
	b.insereix(5);
	b.insereix(6);
	b.insereix(7);
	a.print(cout);
	a.print_reversed(cout);

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
	f.print_reversed(cout);

	bool equals = d!=e;
	cout<<"Differents "<<equals<<endl;


	return 0;
}
