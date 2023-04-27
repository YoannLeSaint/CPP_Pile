#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

template<class T>

class Point{
private:
    int x;
    int y;

public:
    Point() = default;
    Point(int x, int y);

    ~Point() = default;

    int getX();
    int getY();

    void setX(int x);
    void setY(int y);

protected:
    //
};