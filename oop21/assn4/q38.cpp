#include <iostream>
#include <math.h>
using namespace std;

class Complex{
double x, y;
public:
Complex(double xx=0, double yy=0){
x=xx;
y=yy;
}

friend ostream& operator<<(ostream& os, Complex ob){
os << ob.x;
if(ob.y > 0){
os << " + ";
os << ob.y;
os << "i\n";
}
else{
os << " ";
os << ob.y;
os << "i\n";
}
return os;
}
};

class Quadratic{
double a,b,c;
public:
Quadratic(double aa=0, double bb=0, double cc=0){
a=aa;
b=bb;
c=cc;
}

Quadratic operator+(Quadratic ob){
Quadratic t;
t.a = a + ob.a;
t.b = b + ob.b;
t.c = c + ob.c;
return t;
}

friend ostream& operator<<(ostream& os, const Quadratic ob){
os << ob.a << "x^2";
ob.b > 0 ? os << " + " << ob.b : os << " " << ob.b;
os << "x";
ob.c > 0 ? os << " + " << ob.c : os << " " << ob.c;
return os;
}

friend istream& operator>>(istream& is, Quadratic &ob){
is >> ob.a;
is >> ob.b;
is >> ob.c;
//cout << ob.a << " " << ob.b << " " << ob.c << "\n";
return is;
}

double evaluate(double x){
return this->a*x*x + this->b*x + this->c;
}

double* getRoots(){
double *arr = new double[4];
cout << "determinant: " << b*b - 4*a*c << "\n";
if(b*b - 4*a*c >= 0){
arr[1]=0;
arr[3]=0;
arr[0] = (-1*b + sqrt(b*b - 4*a*c)) / (2*a);
arr[2] = (-1*b - sqrt(b*b - 4*a*c)) / (2*a);
}
else{
arr[0] = (-1*b) / (2*a);
arr[2] = (-1*b) / (2*a);
arr[1] = sqrt(-1 * (b*b - 4*a*c)) / (2*a);
arr[3] = -1 *  sqrt(-1 * (b*b - 4*a*c)) / (2*a) ;
}
//cout << arr[0] << " " << arr[1] << " " << arr[2] << arr[3] << "\n";
return arr;
//return {1,2,3,4};
}

};

int main(){
Quadratic q1,q2;
cout << "Enter a,b,c for 1st quadratic: ";
cin >> q1;
cout << "Enter a,b,c for 2nd quadratic: ";
cin >> q2;
Quadratic sum = q1 + q2;
cout << "Sum of the given polynomials: ";
cout << sum << "\n";

int x;
cout << "Enter a value of x to evalate the given polynomials: ";
cin >> x;
cout << "Quadratic 1: " << q1.evaluate(x) << "\n";
cout << "Quadratic 2: " << q2.evaluate(x) << "\n";
cout << "Sum: " << sum.evaluate(x) << "\n";

double *rootArr = sum.getRoots();
Complex root1 = Complex(rootArr[0], rootArr[1]);
Complex root2 = Complex(rootArr[2], rootArr[3]);
delete[] rootArr;
cout << "Roots: ";
cout << root1;
cout << root2;
return 0;
}
