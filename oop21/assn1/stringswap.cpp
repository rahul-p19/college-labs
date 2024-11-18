#include <iostream>
using namespace std;
void swap(string *a, string *b){
string temp=*a;
*a=*b;
*b=temp;
}

int main(){
string x,y;
cout << "Enter the two strings (separated by a space) : ";
cin >> x >> y;
swap(&x,&y);
cout << "After swapping: " << x << " " << y << "\n";
return 0;
}
