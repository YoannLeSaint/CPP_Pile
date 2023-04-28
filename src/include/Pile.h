#pragma once
#include <iostream>
#include <string>
#include <random>
#include <typeinfo>
#include <cstring>
using namespace std;

template<class T>
class Pile {
private:
    T container;
    int size;
    Pile* p_first;
    Pile* p_next;

    // Setters privées
    void setFirst(Pile* first);
    void setNext(Pile* next);
    void setSize(int size);

public:
    // Constructeur
    Pile();
    Pile(Pile* first, T container);

    // Destructeur
    ~Pile();

    // Getters
    T getContainer(void);
    int getSize(void);
    Pile* getFirst(void);
    Pile* getNext(void);

    // Setters
    void setContainer(T container);

    // Méthodes
    void piler(T newContainer);
    void depiler(void);
    void display(void);

protected:
    //
};