#include "cj_enters.hpp"
cj_enters::cj_enters() : _first(NULL), _last(NULL), _count(0) { }
cj_enters::cj_enters(const cj_enters &cj) : _first(NULL), _last(NULL), _count(0) {
    _copy(cj._first);
}

cj_enters::~cj_enters() {
    _delete();
}

void cj_enters::insereix(int e) {
    if (conte(e)) return;
    if (_count == 0) _add_front(e);
    else {
        node *aux = _first;
        bool inserted = false;
        while (aux->next != NULL && !inserted) {
            if (e > aux->value && e < aux->next->value) {
              node *new_node = new node();
              new_node->value = e;
              _add(aux, new_node);
              inserted = true;
            } else {
                aux = aux->next;
            }
        }

        if (!inserted) (e < aux->value) ? _add_front(e) : _add_back(e);

    }
    _count++;
}

 void cj_enters::unir(const cj_enters &B) {
    if (B.card() == 0) return;
    node *aux = B._first;
    while (aux != NULL) {
        insereix(aux->value);
        aux = aux->next;
    }
}

void cj_enters::intersectar(const cj_enters &B) {
    if (B.card() == 0) return;
    node *aux = _first;
    while (aux != NULL) {
        if (!B.conte(aux->value)) {
          int val = aux->value;
          aux = aux->next;
          _delete_node(val);
        } else aux = aux->next;
    }
}

void cj_enters::restar(const cj_enters &B) {
  if (B.card() == 0) return;
  node *aux = _first;
  while (aux != NULL) {
      if (B.conte(aux->value)) {
        int val = aux->value;
        aux = aux->next;
        _delete_node(val);
      } else aux = aux->next;
  }
}

cj_enters cj_enters::operator+(const cj_enters &B) const {
    cj_enters cj = cj_enters(*this);
    cj.unir(B);
    return cj;
}

cj_enters cj_enters::operator-(const cj_enters &B) const {
    cj_enters cj = cj_enters(*this);
    cj.restar(B);
    return cj;
}

cj_enters cj_enters::operator*(const cj_enters &B) const {
    cj_enters cj = cj_enters(*this);
    cj.intersectar(B);
    return cj;
}

bool cj_enters::operator==(const cj_enters &B) const {
    if (_count != B._count) return false;

    node *aNode = _first, *bNode = B._first;
    bool equals = true;
    while (aNode != NULL && equals) {
        if (aNode->value != bNode->value) equals = false;
        else {
            aNode = aNode->next;
            bNode = bNode->next;
        }
    }

    return equals;
}

bool cj_enters::operator!=(const cj_enters &B) const {
    return !(*this==B);
}

cj_enters& cj_enters::operator=(const cj_enters &cj) {
    if (*this != cj) {
        _delete();
        _copy(cj._first);
    }

    return *this;
}

bool cj_enters::conte(int e) const {
    if (_count == 0) return false;

    node *aux = _first;
    bool finded = false;
    while (aux != NULL && !finded) {
      if (aux->value == e) finded = true;
      aux = aux->next;
    }
    return finded;
}

int cj_enters::min() const {
    return (_count == 0) ? ((unsigned int)~0>>1) :  _first->value;
}

int cj_enters::max() const {
    return (_count == 0) ? ((unsigned int)~0>>1) :  _last->value;
}

int cj_enters::card() const {
    return _count;
}

void cj_enters::print(ostream &os) const {
    node *aux = _first;
    os<<"[ ";
    while (aux != NULL) {
        os<<aux->value<<" ";
        aux = aux->next;
    }
    os<<"]"<<endl;
}
void cj_enters::print_reversed(ostream &os) const {
    node *aux = _last;
    os<<"[ ";
    while (aux != NULL) {
        os<<aux->value<<" ";
        aux = aux->prev;
    }
    os<<"]"<<endl;
}

void cj_enters::_add_front(int e) {
    node *new_node = new node();
    new_node->value = e;
    if (_first != NULL) {
        _first->prev = new_node;
        new_node->next = _first;
        _first = new_node;
    } else {
        _first = new_node;
        _last = new_node;
    }
}

void cj_enters::_add_back(int e) {
    node *new_node = new node();
    new_node->value = e;
    new_node->prev = _last;
    _last->next = new_node;
    _last = new_node;
}

void cj_enters::_add(cj_enters::node *prev, node *new_node) {
    new_node->next = prev->next;
    new_node->prev = prev;
    prev->next->prev = new_node;
    prev->next = new_node;
}

void cj_enters::_delete() {
  node *aux = _first;
    while (aux != NULL) {
        _first = _first->next;
        delete aux;
        aux = _first;
    }
    _first = _last = NULL;
    _count = 0;
}

void cj_enters::_delete_node(int e) {
    node *tmp;
    if (_first->value == e) {
      tmp = _first;
      _first = _first->next;
      _first->prev = NULL;
      delete tmp;
    } else if(_last->value == e) {
      tmp = _last;
      _last = _last->prev;
      _last->next = NULL;
      delete tmp;
    } else {
      tmp = _first->next;
      bool deleted = false;
      while (!deleted && tmp->next != NULL) {
         if (tmp->value == e) {
           tmp->prev->next = tmp->next;
           tmp->next->prev = tmp->prev;
           delete tmp;
           deleted = true;
         } else tmp = tmp->next;
      }
    }
    --_count;
}

void cj_enters::_copy(const node *first) {
    if (first == NULL) return;

    while (first != NULL) {
      insereix(first->value);
      first = first->next;
    }
}
