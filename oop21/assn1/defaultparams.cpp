#include <iostream>
using namespace std;

int add(int a,int b=0,int c=0){
return a+b+c;
}

int main(){
int a,b,c;
cout << "Enter three numbers: ";
cin >> a >>b >>c;
cout << "With 3 parameters: ";
cout << add(a,b,c) << "\n";
cout << "With 2 parameters: ";
cout << add(a,b) << "\n";
cout << "With 1 parameter: ";
cout << add(a) << "\n";
return 0;
}
