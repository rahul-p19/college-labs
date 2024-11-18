#include <iostream>
using namespace std;

class INT{
int i;
public:
INT(int a):i(a){}
~INT(){}

INT operator++(){
INT t(0);
t.i = (this->i)++;
return t;
}

INT operator++(int){
INT t(0);
t.i = ++(this->i);
return t;
}

INT operator=(int){
return this->i;
}

operator int(){
return i;
}

};

int main(){
int x = 3;
INT y = x;
y++ = ++y;
x= y;
cout << "x: " << x << "\n";
return 0;
}
