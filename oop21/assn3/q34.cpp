#include <iostream>
#include <vector>
using namespace std;

class Shape{
	public:
		virtual double getArea()=0;
		virtual double getVolume()=0;
		virtual int getDimensions()=0;
		virtual void showShape()=0;
};

class TwoDShape: public Shape{
public:
		virtual double getArea()=0;
		virtual double getVolume()=0;
		virtual int getDimensions()=0;
		virtual void showShape()=0;
};

class ThreeDShape: public Shape{
public:
		virtual double getArea()=0;
		virtual double getVolume()=0;
		virtual int getDimensions()=0;
		virtual void showShape()=0;
};

class Circle: public TwoDShape{
	double radius;
	public:
	Circle(double r=0){
		radius=r;
	}
	int getDimensions(){
		return 2;
	}void showShape(){
		cout << "Shape: Circle\n";
	}
	double getArea(){
		return 3.142*radius*radius;
	}
	double getVolume(){
return 0;}	
};

class Triangle: public TwoDShape{
	double height,breadth;
	public:
	Triangle(double h=0,double b=0){
		height=h;
		breadth=b;
	}
	void showShape(){
		cout << "Shape: Triangle\n";
	}
	int getDimensions(){
		return 2;
	}double getArea(){
		return 0.5 * height * breadth;
	}
	double getVolume(){
return 0;}
};

class Ellipse: public TwoDShape{
	double major, minor;
	public:
	Ellipse(double maj=0, double min=0){
		major=maj;
		minor=min;
	}
	int getDimensions(){
		return 2;
	}void showShape(){
		cout << "Shape: Ellipse\n";
	}
	double getArea(){
		return 3.142*major*minor;
	}
	double getVolume(){
return 0;}
};

class Sphere: public ThreeDShape{
	double radius;
	public:
	Sphere(double r=0){
		radius=r;
	}
	void showShape(){
		cout << "Shape: Sphere\n";
	}
	double getArea(){
		return 4 * 3.142 * radius * radius;
	}
	int getDimensions(){
		return 3;
	}double getVolume(){
		return 4 * 3.142 * radius * radius * radius / 3;
	}
};

class Cube: public ThreeDShape{
	double side;
	public:
	Cube(double s=0){
		side=s;
	}
	int getDimensions(){
		return 3;
	}void showShape(){
		cout << "Shape: Cube\n";
	}
	double getArea(){
		return 6 * side * side;
	}

	double getVolume(){
		return side*side*side;
	}
};

int main(){
	vector<Shape*> shapes(5);
	double r,h,b,maj,min,s;
	cout << "Enter radius of circle: ";
	cin >> r;
	shapes[0] = new Circle(r);
	cout << "Enter height and breadth of triangle: ";
	cin >> h >> b;
	shapes[1] = new Triangle(h,b);
	cout << "Enter length of major and minor axis of ellipse: ";
	cin >> maj >> min;
	shapes[2] = new Ellipse(maj,min);
	cout << "Enter radius of sphere: ";
	cin >> r;
	shapes[3] = new Sphere(r);
	cout << "Enter side length of cube: ";
	cin >> s;
	shapes[4] = new Cube(s);

	for(int i=0;i<5;i++){
		shapes[i]->showShape();
		cout << "Area= " << shapes[i]->getArea() << "\n";
		if(shapes[i]->getDimensions()==3) cout << "Volume= " << shapes[i]->getVolume() << "\n";

	}
	return 0;
}
