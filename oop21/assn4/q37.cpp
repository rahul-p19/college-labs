#include <iostream>
using namespace std;

class Complex{
	double x, y;
	public:
	Complex(double xx=0, double yy=0){
		x=xx;
		y=yy;
	}

	bool operator==(Complex ob){
		return (x==ob.x && y==ob.y);
	}

	Complex operator+(Complex ob){
		Complex t;
		t.x = x + ob.x;
		t.y = y + ob.y;
		return t;
	}

	Complex operator-(Complex ob){
		Complex t;
		t.x = x - ob.x;
		t.y = y - ob.y;
		return t;
	}

	Complex operator*(Complex ob){
		Complex t;
		t.x = x*ob.x - y*ob.y;
		t.y = x*ob.y + y*ob.x;
		return t;
	}

	Complex operator/(Complex ob){
		Complex t;
		t.x = (x*ob.x+y*ob.y)/(ob.x*ob.x - ob.y*ob.y);
		t.y = (y*ob.x - x*ob.y)/(ob.x*ob.x - ob.y*ob.y);
		return t;
	}

	void display(){
		cout << x;
		y>0? cout << " + " << y << "i\n" : cout << " " << y << "i\n";
	}
};

int main(){
	double xx,yy;
	cout << "Enter real and imaginary part of 1st complex number: ";
	cin >> xx >> yy;
	Complex ob1(xx,yy);
	cout << "Enter real and imaginary part of 2nd complex number: ";
	cin >> xx >> yy;
	Complex ob2(xx,yy);
	Complex ob3;
	ob1.display();
	ob2.display();
	ob1==ob2? cout << "ob1 and ob2 are equal\n" : cout << "ob1 and ob2 are not equal\n";
	ob3 = ob1+ob2;
	cout << "Sum: ";
	ob3.display();
	ob3 = ob1-ob2;
	cout << "Difference: ";
	ob3.display();
	ob3= ob1*ob2;
	cout << "Product: ";
	ob3.display();
	ob3=ob1/ob2;
	cout << "Dividing ob1 by ob2: ";
	ob3.display();
	return 0;
}
