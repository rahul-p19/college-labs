#include <iostream>
using namespace std;
void swap(int &a, int &b){
int t = a;
a= b;
b=t;
}

int main(){
int a,b;
cout << "Enter two variables: ";
cin >> a >>b;
swap(a,b);
cout << "After swapping: " << a << " " << b << "\n";
return 0;
}
