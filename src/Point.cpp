#include "./include/Point.h"

Point::Point(int x, int y){
    this->X = x;
    this->Y = y;
}

int Point::getX(){return this->X;}
int Point::getY(){return this->Y;}

void Point::setX(int x){this->X = x;}
void Point::setY(int y){this->Y = y;}

string Point::toString() {
	stringstream ss;
	ss << "[" << getX() << ", " << getY() << "]" << endl;
	return ss.str();
}