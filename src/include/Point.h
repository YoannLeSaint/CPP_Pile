#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <random>
using namespace std;


class Point
{
private:
    int X;
    int Y;

public:
    // Constructeurs
    Point() = default;
    Point(int x, int y);

    // Destructeur
    ~Point() = default;

    // Getters
    int getX();
    int getY();

    // Setters
    void setX(int x);
    void setY(int y);

    // Méthodes
    string toString();

protected:
    //
};