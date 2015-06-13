#ifndef CIRCLE_H
#define CIRCLE_H

class Circle{
	public:
		//Circle();
		//CIrcle(double);
		Circle(){
			radius=1;
			numofObjiects++;
		}
		Circle(double newRadius){
			radius=newRadius;
			numofObjiects++;
		}
		double getArea() const;
		double getRadius() const;
		void setRadius(double);
		static int getNumofObjects();
		
	private:
		double radius;
		static int numofObjiects;
};

#endif
