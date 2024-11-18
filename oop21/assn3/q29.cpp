#include <iostream>
using namespace std;

class Base1{
	public:
		Base1(){
			cout << "Base 1 constructor\n";
		}
};

class Base2{
	public:
		Base2(){
			cout << "Base 2 constructor\n";
		}
};

class Derived: public Base1, public Base2{
	public:
		Derived(){
			cout << "Derived constructor\n";
		}
};

int main(){
	Base1 ob1;
	Base2 ob2;
	Derived ob3;
}
