#ifndef cj_enters_hpp
#define cj_enters_hpp
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
    struct node {
        node *next, *prev;
        int value;
    };

    node *_first, *_last;
    int _count;

    //PRE: Cert
    //POST: Crea un conjunt a partir del primer node
    void _copy(node *first);

    //PRE: Cert
    //POST: Borra i allibera la memòria de tots els nodes del conjunt
    void _delete();

    //PRE: El node n no pot ser NULL
    //POST: Enllaça el anterior i següent a n entre ells i allibera la memòria del
    //node n
    void _delete_node(node *n);

    //PRE: El valor e no ha d'estar en el conjunt.
    //POST: Crea i afegeix un node nou i l'afegeix d'avant del conjunt.
    void _add_front(int e);

    //PRE: El valor e no ha d'estar en el conjunt.
    //POST: Crea i afegeix un node nou i l'afegeix al final del conjunt.
    void _add_back(int e);

    //PRE: Prev no ha de ser null i new_node tampoc
    //POST: Crea i afegeix entre la posició 2 i la n-1 del conjunt
    void _add(node *prev, node *new_node);
};

#endif
