#include <iostream>
#include "Circle.h"
using namespace std;

int main(void){
	cout<<"������Ŀ��"<< Circle::getNumofObjects() << endl;
	Circle c1;
	cout<<"������Ŀ��"<< Circle::getNumofObjects() << endl;
	cout<<"c1���"<< c1.getArea() << endl;
	c1.setRadius(2.5);
	cout<<"c1���"<< c1.getArea() << endl;
	Circle c2(5.0);
	cout<<"c2���"<< c2.getArea() << endl;
	c2.setRadius(2.5);
	cout<<"c2���"<< c2.getArea() << endl;
	cout<<"������Ŀ��"<< Circle::getNumofObjects() << endl;
	
}
