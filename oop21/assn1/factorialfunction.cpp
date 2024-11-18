#include <iostream>
using namespace std;

int fact(const int n){
	if(n<=1) return 1;
	return n*fact(n-1);
}
int main(){
	int n;
	cout << "Enter n: ";
	cin >> n;
	cout << "Factorial: " << fact(n) << "\n";
	return 0;
}
