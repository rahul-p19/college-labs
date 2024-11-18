#include <iostream>
using namespace std;
int main(){
const double PI = 3.142;
double radius;
cout << "Enter radius: ";
cin >> radius;
double area = PI * radius * radius;
cout << "Area: " << area << "\n";
return 0;
}
