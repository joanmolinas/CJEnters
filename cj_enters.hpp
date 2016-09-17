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

    //Borrar
    void print_reversed(ostream& os)const;

private:
    struct node {
        node *next, *prev;
        int value;
    };

    node *_first, *_last;
    int _count;

    //PRE:
    //POST:
    void _copy(const node *first);

    //PRE:
    //POST:
    void _delete();

    //PRE:
    //POST:
    void _delete_node(int e);

    //PRE:
    //POST:
    void _add_front(int e);

    //PRE:
    //POST:
    void _add_back(int e);

    //PRE:
    //POST:
    void _add(node *prev, node *new_node);
};

#endif
