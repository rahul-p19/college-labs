// question 17
#include <iostream>
using namespace std;

class Rectangle{
double b,h;

public: 
Rectangle(int bb=0, int hh=0){
b=bb;
h=hh;
}

double area(){
return this->b * this->h;
}
};

int main(){
double a,b;
for(int i=0;i<4;i++){
cout << "Enter rectangle " << i+1 << " breadth and height: ";
cin >> a >> b;
Rectangle r(a,b);
cout << "Area: " << r.area() << "\n";
}
return 0;
}
