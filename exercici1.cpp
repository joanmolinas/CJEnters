// File: exercici1.cpp
// Subject: Programa principal de l'exercici 1

#include <iostream>

using namespace std;

#include "cj_enters.hpp"

// Defineix un operador de sortida para cj_enters
ostream& operator<< (ostream& os, cj_enters& cj) {
  cj.print(os);
  return os;
}

// Defineix un operador d'entrada per cj_enters
istream& operator>> (istream& is, cj_enters& cj) {
  int n;
  do {
    is >> n;
    if (n != 0) {
      cj.insereix( n );
    }
  } while (n != 0);
  return is;
}

// Programa principal que demana un cj_enters (una sequencia 
// d'enters acabada en zero) i comprova si un enter donat pertany 
// o no a aquest conjunt.
int main () {
  cj_enters cj;
  cout << "Introdueix el primer conjunt (0 indica el final del cj):" << endl;
  cin >> cj;
  cout << "Introdueix l'element que vols buscar: ";
  int num;
  cin >> num;
  cout << "El conjunt es:" << endl;
  cout << cj;
  cout << "Element " << num << (cj.conte(num)?" SI":" NO");
  cout << " esta present en el conjunt." << endl;
}
