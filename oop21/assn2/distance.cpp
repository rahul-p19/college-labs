// question 16
#include <iostream>
#include <math.h>
using namespace std;

class Point{
double x,y,z;

public:
Point(double xx=0, double yy=0, double zz=0){
x=xx;
y=yy;
z=zz;
}

double distance(Point b){
	double dist = pow(this->x - b.x,2) + pow(this->y - b.y,2) + pow(this->z - b.z,2);
	dist = sqrt(dist);
	return dist;
}
};

int main(){
double x,y,z;
cout << "Enter coordinates of point 1: ";
cin >> x >> y >> z;
Point p1(x,y,z);
cout << "Enter coordinates of point 2: ";
cin >> x >> y >> z;
Point p2(x,y,z);
cout << "Distance: " << p2.distance(p1) << "\n";
return 0;
}
