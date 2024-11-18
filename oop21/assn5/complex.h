#include <iostream>
using namespace std;

class Complex{
    int x,y;
    public:
    Complex(int xx=0, int yy=0){
        x=xx;
        y=yy;
    }
    bool operator>(Complex &ob){
        if(x>ob.x) return true;
        if(x==ob.x && y>ob.y) return true;
        return false;
    }
    friend ostream& operator<<(ostream &os, Complex &ob){
        os << "(" << ob.x << "," << ob.y << ")\n";
        return os;
    }
};