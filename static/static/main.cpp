#include <iostream>
#include "Circle.h"
using namespace std;

int main(void){
	cout<<"对象数目："<< Circle::getNumofObjects() << endl;
	Circle c1;
	cout<<"对象数目："<< Circle::getNumofObjects() << endl;
	cout<<"c1面积"<< c1.getArea() << endl;
	c1.setRadius(2.5);
	cout<<"c1面积"<< c1.getArea() << endl;
	Circle c2(5.0);
	cout<<"c2面积"<< c2.getArea() << endl;
	c2.setRadius(2.5);
	cout<<"c2面积"<< c2.getArea() << endl;
	cout<<"对象数目："<< Circle::getNumofObjects() << endl;
	
}
