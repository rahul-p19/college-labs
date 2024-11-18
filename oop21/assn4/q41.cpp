#include <iostream>
using namespace std;

// post inc overload
class Integer{
int x;
public:

Integer(int xx=0){
x=xx;
}

operator int(){
return x;
}

friend ostream& operator<<(ostream& os, Integer ob){
os << ob.x << "\n";
return os;
}

Integer operator++(int){
Integer t;
t.x = x++;
return t;
}

};

int main() {
Integer a = 4, b = a, c;
c = a+b++;
int i = a;
cout << a << b << c;
return 0;
}
