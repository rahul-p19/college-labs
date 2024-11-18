#include <iostream>
using namespace std;

int fact(const int &a){
if(a<=1) return 1;
return a*fact(a-1);
}

int main(){
int n;
cout << "Enter n: ";
cin >> n;
cout << "Factorial: " << fact(n) << "\n";
return 0;
}
