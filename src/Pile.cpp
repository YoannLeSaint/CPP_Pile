
#include "./include/Pile.h"

using namespace std;


// Constructeur par défaut
template <class T>
Pile <T>::Pile() : size(0), container(NULL), p_first(nullptr), p_next(nullptr) {}


// Constructeur surchargé
template <class T>
Pile<T>::Pile(Pile* first, T container) {
    // On initialise les valeurs de notre objet
    this->p_first = first;
    this->size = this->p_first->getSize() + 1;
    this->container = container;
    this->p_next = nullptr;

    // On se replace sur la tête de liste
    Pile* lecture = new Pile();
    lecture = this->p_first;

    // On se promène à travers la liste pour changer la taille
    while(lecture != nullptr)
    {
        lecture->setSize(this->size);

        if (lecture->getNext() == nullptr)
        {
            lecture->setNext(this);
            lecture = nullptr;
        }
        else
        {
            lecture = lecture->getNext();
        }
    }

    delete lecture;
}

// getters
template <class T>
int Pile<T>::getSize() { return this->size; }

template <class T>
T Pile<T>::getContainer() { return this->container; }

template <class T>
Pile<T>* Pile<T>::getFirst() { return this->p_first; }

template <class T>
Pile<T>* Pile<T>::getNext() { return this->p_next; }

// Setters
template <class T>
void Pile<T>::setContainer(T container) { this->container = container; }

template <class T>
void Pile<T>::setFirst(Pile* first) { this->p_first = first; }

template <class T>
void Pile<T>::setNext(Pile* next) { this->p_next = next; }

template <class T>
void Pile<T>::setSize(int size){ this->size = size; }


// Destructeur
template <class T>
Pile<T>::~Pile() {
    this->p_first = nullptr;
    this->p_next = nullptr;

    //delete this->container;
}


template <class T>
void Pile<T>::depiler(){
    Pile* lecture = new Pile();

    // On se replace sur la tête de liste
    if (this->p_first != nullptr){
        lecture = this->p_first;
    }

    // On se promène à travers la liste
    for (int i = 0; i < this->getSize() - 1; i++){
        lecture = lecture->p_next;
    }

    // On supprime le dernier element
    delete lecture-> p_next;
    setNext(nullptr);
    delete lecture;
    setSize(getSize()--);
}

template <class T>
void Pile<T>::piler(T newContainer) {
    Pile* newPile = new Pile();

    if(newPile){
        newPile->container = newContainer;

        if(this->getSize() > 0) {
            *(newPile->getNext()) = *(this->getFirst());
        }
        else {
            *(newPile->getNext()) = nullptr;
            *(this->getFirst()->getNext()) = newContainer;
        }
    }

    *(this->getFirst()) = newContainer;
    this->setSize(*(this->getSize())++);
}

template <class T>
void Pile<T>::display(){
    Pile* lecture = new Pile();

    // On se replace sur la tête de liste
    if (this->p_first != nullptr){
        lecture = this->p_first;
    }

    // On se promène à travers la liste pour afficher tous les éléments
    cout << "pile = { ";
    for (int i = 0; i < this->getSize() - 1; i++){
        if (strcmp(typeid(lecture).name(),"Point") == 0)
            cout << lecture->T.toString() << ", ";
        else
            cout << lecture->T << ", ";
        lecture = lecture->p_next;
    }

    if (strcmp(typeid(lecture).name(), "Point") == 0)
        cout << lecture->T.toString() << " }" << endl;
    else
        cout << lecture->T << " }" << endl;

    delete lecture;
}

template Pile<int>::Pile(Pile<int>*, int);
template void Pile<int>::piler(int);
template void Pile<int>::display(void);
template void Pile<int>::depiler(void);