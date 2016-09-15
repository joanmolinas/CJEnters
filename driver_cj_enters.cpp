/*driver_cj_enters (basat en GenDriver) 
  Modificacio amd data: 24-9-2015
*/

#include <string>
#include <iostream>

#include <esin/error>
#include <esin/gen_driver>
#include <esin/util>

#include "cj_enters.hpp"

using namespace std;

// imprimir cj_enters

ostream& operator<<(ostream& os, const cj_enters& cj) {
  cj.print(os);
  return os;
}

ostream& operator<=(ostream& os, const bool b) {
  os << (b ? "true" : "false");
  return os;
}

// user init

void* user_init(gen_driver &dr){

  string id= dr.args(1);
  string tid= dr.args(2);

  if (tid == "cj_enters") { 
    if (dr.nargs() != 2)
      throw error(gen_driver::WrongNumArgs,gen_driver::nom_mod,gen_driver::WrongNumArgsMsg);
    return static_cast<void*>(new cj_enters);
  }
  throw error(gen_driver::WrongTypeArgs,gen_driver::nom_mod,gen_driver::WrongTypeArgsMsg);
}

// TypeTraits 

template <>
const char* TypeTraits<cj_enters>::name = "cj_enters";

// Metodes de cj_enters 

void insereix(gen_driver& dr){
  if(dr.object_type()!= "cj_enters")
    throw error(gen_driver::WrongTypeArgs,gen_driver::nom_mod,gen_driver::WrongTypeArgsMsg);
    
  int c = util::toint(dr.args(1));
  dr.object<cj_enters>()->insereix(c); 
}    


void unir(gen_driver& dr){
  if(dr.object_type()!= "cj_enters" or dr.object_type(1) != "cj_enters")
    throw error(gen_driver::WrongTypeArgs,gen_driver::nom_mod,gen_driver::WrongTypeArgsMsg);
    
  dr.object<cj_enters>()->unir(*dr.object<cj_enters>(1));
  dr.get_ostream() << *(dr.object<cj_enters>()) << endl;
}    


void intersectar(gen_driver& dr){
  if(dr.object_type()!= "cj_enters" or dr.object_type(1) != "cj_enters")
    throw error(gen_driver::WrongTypeArgs,gen_driver::nom_mod,gen_driver::WrongTypeArgsMsg);
    
  dr.object<cj_enters>()->intersectar(*dr.object<cj_enters>(1)); 
  dr.get_ostream() << *(dr.object<cj_enters>()) << endl;
} 

void restar(gen_driver& dr){
  if(dr.object_type()!= "cj_enters" or dr.object_type(1) != "cj_enters")
    throw error(gen_driver::WrongTypeArgs,gen_driver::nom_mod,gen_driver::WrongTypeArgsMsg);
    
  dr.object<cj_enters>()->restar(*dr.object<cj_enters>(1));
  dr.get_ostream() << *(dr.object<cj_enters>()) << endl;
} 

void conte(gen_driver& dr){
  if(dr.object_type()!= "cj_enters")
    throw error(gen_driver::WrongTypeArgs,gen_driver::nom_mod,gen_driver::WrongTypeArgsMsg);
   
  int c = util::toint(dr.args(1));
  (dr.get_ostream() <= dr.object<cj_enters>()->conte(c))<< endl;
}

void max(gen_driver& dr){
  if(dr.object_type()!= "cj_enters")
    throw error(gen_driver::WrongTypeArgs,gen_driver::nom_mod,gen_driver::WrongTypeArgsMsg);
   
  dr.get_ostream() << dr.object<cj_enters>()->max() << endl;
}    

void min(gen_driver& dr){
  if(dr.object_type()!= "cj_enters")
    throw error(gen_driver::WrongTypeArgs,gen_driver::nom_mod,gen_driver::WrongTypeArgsMsg);
  
  dr.get_ostream() << dr.object<cj_enters>()->min() << endl;
}    

void card(gen_driver& dr){
  if(dr.object_type()!= "cj_enters")
    throw error(gen_driver::WrongTypeArgs,gen_driver::nom_mod,gen_driver::WrongTypeArgsMsg);
  
  dr.get_ostream() << dr.object<cj_enters>()->card() << endl;
}  

void iguals(gen_driver &dr){
  if(dr.object_type() != "cj_enters" or dr.object_type(1) != "cj_enters")
    throw error(gen_driver::WrongTypeArgs,gen_driver::nom_mod,gen_driver::WrongTypeArgsMsg);
  
  dr.get_ostream() <= dr.object<cj_enters>()->operator==(*dr.object<cj_enters>(1)); 
  dr.get_ostream() << endl;
}

void diferents(gen_driver &dr){
  if(dr.object_type() != "cj_enters" or dr.object_type(1) != "cj_enters")
    throw error(gen_driver::WrongTypeArgs,gen_driver::nom_mod,gen_driver::WrongTypeArgsMsg);
  
  dr.get_ostream() <= dr.object<cj_enters>()->operator!=(*dr.object<cj_enters>(1)); 
  dr.get_ostream() << endl;
}

void suma(gen_driver &dr){
  if(dr.object_type() != "cj_enters" or dr.object_type(1) != "cj_enters")
    throw error(gen_driver::WrongTypeArgs,gen_driver::nom_mod,gen_driver::WrongTypeArgsMsg);
  
  dr.get_ostream() << dr.object<cj_enters>()->operator+(*dr.object<cj_enters>(1)) << endl;
}

void producte(gen_driver &dr){
  if(dr.object_type() != "cj_enters" or dr.object_type(1) != "cj_enters")
    throw error(gen_driver::WrongTypeArgs,gen_driver::nom_mod,gen_driver::WrongTypeArgsMsg);
  
  dr.get_ostream() << dr.object<cj_enters>()->operator*(*dr.object<cj_enters>(1)) << endl;
}

void resta(gen_driver &dr){
  if(dr.object_type() != "cj_enters" or dr.object_type(1) != "cj_enters")
    throw error(gen_driver::WrongTypeArgs,gen_driver::nom_mod,gen_driver::WrongTypeArgsMsg);
  
  dr.get_ostream() << dr.object<cj_enters>()->operator-(*dr.object<cj_enters>(1)) << endl;
}



/*--------------------------< MAIN >--------------------------*/

int main() {
  gen_driver d;

  d.add_call("insereix", insereix, "cj_enters", "int");
  d.add_call("unir", unir, "cj_enters", "cj_enters");
  d.add_call("intersectar", intersectar, "cj_enters", "cj_enters");
  d.add_call("restar", restar, "cj_enters", "cj_enters");
  
  d.add_call("conte", conte, "cj_enters", "int");
  d.add_call("min", min, "cj_enters");
  d.add_call("max", max, "cj_enters");
  d.add_call("card", card, "cj_enters");
  
  d.add_call("==", iguals, "cj_enters", "cj_enters");
  d.add_call("!=", diferents, "cj_enters", "cj_enters");

  d.add_call("+", suma, "cj_enters", "cj_enters");
  d.add_call("*", producte, "cj_enters", "cj_enters");
  d.add_call("-", resta, "cj_enters", "cj_enters");

  d.install_type<cj_enters>("cj_enters");

  d.go(); 
} 

