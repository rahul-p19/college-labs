#include <iostream>
using namespace std;

class shape2D{
	public:

		virtual void area()=0;
		virtual void perimeter()=0;
};

class Circle: public shape2D{
	double radius;
	public:

	Circle(double r=0){
		radius=r;
	}

	void area(){
		cout << "Area of circle: " << 3.142 * radius * radius << "\n";
	}

	void perimeter(){
		cout << "Perimeter of circle: " << 2 * 3.142 * radius << "\n";
	}
};

class Rectangle: public shape2D{
	double length, breadth;
	public:

	Rectangle(double l=0, double b=0){
		length=l;
		breadth=b;
	}

	void area(){
		cout << "Area of rectangle: " << length*breadth << "\n";
	}

	void perimeter(){
		cout << "Perimeter of rectangle: " << 2*(length+breadth) << "\n";
	}
};

int main(){
	shape2D* arr[5];

	// 3 circles
	for(int i=0;i<3;i++){
		double r;
		cout << "Enter radius of circle: ";
		cin >> r;
		arr[i] = new Circle(r);
	}

	// 2 rectangles
	for(int i=3;i<5;i++){
		double l,b;
		cout << "Enter length and breadth of rectangle: ";
		cin >> l >> b;
		arr[i] = new Rectangle(l,b);
	}

	// displaying all
	for(int i=0;i<5;i++){
		arr[i]->area();
		arr[i]->perimeter();
		delete(arr[i]);
	}
	return 0;
}
