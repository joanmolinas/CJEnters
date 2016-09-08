#ifndef _CJ_ENTERS_HPP_
#define _CJ_ENTERS_HPP_
#include <iostream>

using namespace std;

class cj_enters {

public:

  cj_enters();

  cj_enters(const cj_enters &cj);
  ~cj_enters();
  cj_enters& operator=(const cj_enters &cj);
  
  void insereix(int e);
  
  void unir(const cj_enters& B); 
  void intersectar(const cj_enters& B);
  void restar(const cj_enters& B);

  cj_enters operator+(const cj_enters& B) const;
  cj_enters operator*(const cj_enters& B) const;
  cj_enters operator-(const cj_enters& B) const;

  bool conte(int e) const;

  int max() const;
  int min() const;

  int card() const;

  bool operator==(const cj_enters& B) const;
  bool operator!=(const cj_enters& B) const;

  void print(ostream& os) const;

private:
  
};
#endif
