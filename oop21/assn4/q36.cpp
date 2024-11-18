#include <iostream>
#include <math.h>
using namespace std;

class Point{
	double x,y;
	public:
	Point(double xx=0, double yy=0){
		x=xx;
		y=yy;
	}

	~Point(){
	}

	void showPoint(){
		cout << "Coordinates: (" << x << "," << y << ")\n";
	}

	double operator-(Point ob){
		double dist=0;
		dist =  pow(this->x-ob.x,2) + pow(this->y - ob.y,2);
		dist = sqrt(dist);
		return dist;
	}
};

int main(){
	double xx,yy;
	cout << "Enter x and y coordinates of point 1: ";
	cin >> xx >> yy;
	Point p1(xx,yy);
	cout << "Enter x and y coordinates of point 2: ";
	cin >> xx >> yy;
	Point p2(xx,yy);
	cout << "Point 1: ";
	p1.showPoint();
	cout << "Point 2: ";
	p2.showPoint();
	cout << "Distance between points p1 and p2: " << p1-p2 << "\n";
	return 0;
}
