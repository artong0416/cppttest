#include "Circle.h"
int Circle::numofObjiects=0;

/*Circle::Circle(){
	radius=1;
	numofObjiects++;
}

Circle::Circle(double newRadius){
	radius=newRadius;
	numofObjiects++;
}*/

double Circle::getArea() const {
	return radius*radius*3.14159;
}

double Circle::getRadius() const {
	return radius;
}

void Circle::setRadius(double nradius){
	radius= (nradius>=0)? nradius : 0;
}

int Circle::getNumofObjects(){
	return numofObjiects;
}

