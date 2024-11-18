#include <iostream>
#include "complex.h"
using namespace std;

template<class T>
T maxm(T x, T y){
    if(x>y) return x;
    return y;
}

template<>
char* maxm(char* x, char* y){
    return sizeof(x)>sizeof(y)? x : y;
    return y;
}

int main(){
    int a,b;
    cout << "Enter integers: ";
    cin >> a >> b;
    cout << maxm(a,b);
    cout << "Enter real and imaginary part of 1st complex number: ";
    cin >> a >> b;

    Complex c1(a,b);
    cout << "Enter real and imaginary part of 2nd complex number: ";
    cin >> a >> b;
    Complex c2(a,b);
    Complex result = maxm<Complex>(c1,c2);
    cout << result << "\n";

    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;
    cout << maxm<string>(s1,s2) << "\n";
    return 0;
}
