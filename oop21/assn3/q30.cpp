#include <iostream>
using namespace std;

class A{
	public:
		A(){
			cout << "A constructor\n";
		}
};

class B{
	public:
		B(){
			cout << "B constructor\n";
		}
};

class C{
	public:
		C(){
			cout << "C constructor\n";
		}
};

class D: public A, public B{
	public:
		D(){
			cout << "D constructor\n";
		}
};

class E: public B, public C{
	public:
		E(){
			cout << "E constructor\n";
		}
};

class F: public D, public E{
	public:
		F(){
			cout << "F constructor\n";
		}
};

int main(){
	A ob1;
	B ob2;
	C ob3;
	D ob4;
	E ob5;
	return 0;
}
