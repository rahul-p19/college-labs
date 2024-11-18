#include <iostream>
using namespace std;

class Base{
	public:
		Base(){
			cout << "Base constructor\n";
		}
};

class Derived: public Base{
	public:
		Derived(){
			cout << "Derived constructor\n";
		}
};

int main(){
	Base ob1;
	Derived ob2;
}
