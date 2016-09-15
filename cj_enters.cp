#include "cj_enters.hh"

#pragma mark - Public API
#pragma mark - Constructors
cj_enters::cj_enters() : _first(NULL), _last(NULL), _count(0) { }
cj_enters::cj_enters(const cj_enters &cj) : _first(NULL), _last(NULL), _count(0) {
    _first = _copy(cj._first);
}

cj_enters::~cj_enters() {
    _delete(_first);
}

#pragma mark - Modifiers
void cj_enters::insereix(int e) {
    if (conte(e)) return;
    
    if (_count == 0) _add_front(e);
    else {
        node *new_node = new node;
        new_node->value = e;
        
        node *aux = _first;
        bool inserted = false;
        while (aux->next != NULL && !inserted) {
            if (e > aux->value && e < aux->next->value) {
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
        if (!B.conte(aux->value)) _delete_node(aux->value);
        aux = aux->next;
    }
}

void cj_enters::restar(const cj_enters &B) {
    if (B.card() == 0) return;
    node *aux = B._first;
    while (aux != NULL) {
        if (conte(aux->value)) _delete_node(aux->value);
        aux = aux->next;
    }
}

#pragma mark - Operators
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
        _delete(_first);
        _first = _copy(cj._first);
    }
    
    return *this;
}

#pragma mark - Consultors

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
    return (_count == 0) ? NULL :  _first->value;
}

int cj_enters::max() const {
    return (_count == 0) ? NULL :  _last->value;
}

int cj_enters::card() const {
    return _count;
}

#pragma mark - Print

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

#pragma mark - Private API
#pragma mark - Adders

void cj_enters::_add_front(int e) {
    node *new_node = new node;
    new_node->value = e;
    if (_first != NULL) {
        new_node->next = _first;
        _first->prev = new_node;
        _first = new_node;
        new_node->prev = NULL;
    } else {
        _first = new_node;
        _last = _first;
    }
}

void cj_enters::_add_back(int e) {
    node *new_node = new node;
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

#pragma mark - Deleters

void cj_enters::_delete(node *n) {
    while (n != NULL) {
        node *aux = n->next;
        n = NULL;
        delete n;
        n = aux;
    }
    _first = NULL;
    _last = NULL;
    _count = 0;
}

void cj_enters::_delete_node(int e) {
    if (_first->value == e) {
        _first = _first->next;
        _first->prev = NULL;
        delete _first->prev;
    } else if (_last->value == e) {
        _last = _last->prev;
        _last->next = NULL;
        delete _last->next;
    } else {
        node *aux = _first->next;
        bool deleted = false;
        while (aux != NULL && !deleted) {
            if (aux->value == e) {
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
                deleted = true;
                delete aux;
            } else {
                aux = aux->next;
            }
        }
    }
    --_count;
}

#pragma mark - Copiers
cj_enters::node* cj_enters::_copy(const node *first) {
    if (first == NULL) return NULL;
    
    node *aux = new node;
    aux->value = first->value;
    _copy_node(first, aux);
    return aux;
}

void cj_enters::_copy_node(const node *a, node *b) {
    if (a == NULL || b == NULL) {
        return;
    }
    ++_count;
    if (b->next == NULL) _last = b;
    
    b->next = a->next;
    b->prev = a->prev;
    _copy_node(a->next, b->next);
}



