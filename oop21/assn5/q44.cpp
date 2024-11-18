#include <iostream>
using namespace std;

int main(){
	try{
		int a,b;
		cout << "Enter the numbers: ";
		cin >> a >> b;
		if(b==0)
			throw "Division by zero not allowed";
		cout << (double)a/b << "\n";
	}
	catch(const char *msg){
		cout << msg << "\n";
	}
	return 0;
}
