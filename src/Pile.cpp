
#include "./include/Pile.h"

using namespace std;


// Constructeur par défaut
template <class T>
//Pile <T>::Pile() : container(NULL), size(0), p_first(nullptr), p_next(nullptr) {
Pile<T>::Pile() {
    this->container = 0;
    this->size = 0;
    this->p_first = nullptr;
    this->p_next = nullptr;
}


// Constructeur surchargé
template <class T>
Pile<T>::Pile(Pile* first, T container): Pile<T>::Pile(){
    // On initialise les valeurs de notre objet
    this->container = container;
    this->p_first = first;
    this->p_next = nullptr;

    if (this->p_first != nullptr)
        this->size = (this->p_first->getSize()) + 1;
    else
        this->size = 1;

    cout << "- this  : " << this << endl;
    cout << "- first : " << first << endl;

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
    this->size = this->getSize() - 1;
}

template <class T>
void Pile<T>::piler(T newContainer) {
    Pile* newPile = new Pile(this, newContainer);

    cout << "this   : " << this << endl;
    cout << "Tcont  : " << this->container << endl;
    cout << "Tsize  : " << this->size << endl;
    cout << "Tfirst : " << this->p_first << endl;
    cout << "Tnext  : " << this->p_next << endl << endl;

    cout << "new    : " << newPile << endl;
    cout << "Ncont  : " << newPile->container << endl;
    cout << "Nsize  : " << newPile->size << endl;
    cout << "Nfirst : " << newPile->p_first << endl;
    cout << "Nnext  : " << newPile->p_next << endl;

/*
    if(newPile){
        newPile->container = newContainer;

        if(this->getSize() > 0) {
            *(newPile->getNext()) = *(this->getFirst());
        }
        else {
            *(newPile->getNext()) = nullptr;
            this->getFirst()->getNext()->setContainer(newContainer);
        }
    }

    *(this->getFirst()) = newContainer;
    this->setSize(*(this->getSize())++);
*/
}

template <class T>
void Pile<T>::display(){
    Pile* lecture = new Pile();

    // On se replace sur la tête de liste
    if (this->p_first != nullptr){
        lecture = this->p_first;
    }
    else
    {
        lecture = this;
    }

    // On se promène à travers la liste pour afficher tous les éléments
    cout << "pile = { ";
    for (int i = 0; i < this->getSize() - 1; i++){
        if (strcmp(typeid(lecture).name(),"Point") == 0)
            //cout << lecture->getContainer().toString() << ", ";
            cout << lecture->getContainer() << ", ";
        else
            cout << lecture->getContainer() << ", ";
        lecture = lecture->p_next;
    }

    if (strcmp(typeid(lecture).name(), "Point") == 0)
        //cout << lecture->getContainer().toString() << " }" << endl;
        cout << lecture->getContainer() << " }" << endl;
    else
        cout << lecture->getContainer() << " }" << endl;

    delete lecture;
}

template Pile<int>::Pile(Pile<int>*, int);
template void Pile<int>::piler(int);
template void Pile<int>::display(void);
template void Pile<int>::depiler(void);