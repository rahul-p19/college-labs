#include <iostream>
using namespace std;

class Index{
int x;
public:
Index(int xx=0){
x=xx;
}

operator int(){
return x;
}
};

class Integer{
int x;
public:
Integer(int xx=0){
x=xx;
}

void show(){
cout << "x in Integer: " << x << "\n";
}
};

int main(){
Index in(4), out(10);
int x = in;
int y = in + out;
in = 2;
cout << "in: " << in << "\n";
cout << "out: " << out << "\n";
cout << "x: " << x << "\n";
cout << "y: " << y << "\n";
Integer i;
i = (int)in;
i.show();
return 0;
}
