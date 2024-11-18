#include <iostream>
using namespace std;

class Outer{
	int x,y;
	public:
	Outer(int xx=0, int yy=0){
		x=xx;
		y=yy;
	}
	class ZeroDivide{
		const char *c;
		public:
		ZeroDivide(const char* cc="Default message"){
			c=cc;
		}
		void display(){
			cout << "Error: " << c << "\n";
		}
	};

	int divide(int x, int y){
		if(y==0) throw ZeroDivide("Dividing by zero not allowed");
		return x/y;
	}
};

int main(){
	int a,b;
	cout << "Enter the numbers: ";
	cin >> a >> b;
	Outer ob(a,b);
	try{
		cout << ob.divide(a,b) << "\n";
	}
	catch(Outer::ZeroDivide zd){
		zd.display();
	}
	return 0;
}
