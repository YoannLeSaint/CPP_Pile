/*
créer une pile :
    - depiler
    - empiler
    - afficher

la pile doit fonctionner avec des scalaire et avec
type Point que vous aurez créé (int x, int y)
*/

#include <iostream>
#include <string>
#include <random>

#include "./include/Pile.h"
#include "./include/Point.h"

using namespace std;

int main(){
    cout << "Start" << endl;
    Pile<int>* p1 = new Pile<int>(nullptr, 5);
    // Pile* p2 = new Pile(p1, 7);

    cout << "Avant : " << endl;
    p1->display();
    p1->piler(3);

    cout << endl << "Apres : " << endl;
    p1->display();


    return 0;
}