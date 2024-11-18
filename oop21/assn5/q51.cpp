#include "complex.h"
#include <iostream>
#include "stack.h"
 
using namespace std;

template<class T>
void swapTwo(T &x, T &y){
    T temp = x;
    x = y;
    y = temp;
}

template<>
void swapTwo(Stack &x, Stack &y){
    Stack temp;
    temp.size = x.size;
    x.size = y.size;
    y.size = temp.size;

    temp.top = x.top;
    x.top = y.top;
    y.top = temp.top;

    temp.arr = x.arr;
    x.arr = y.arr;
    y.arr = temp.arr;
}

int main(){
    int a,b;
    cout << "Enter two variables: ";
    cin >> a >> b;
    swapTwo<int>(a,b);
    cout << "After swapping, a= " << a << " b= " << b << "\n";

    cout << "Enter real and imaginary part of 1st complex number: ";
    cin >> a >> b;
    Complex c1(a,b);

    cout << "Enter real and imaginary part of 2nd complex number: ";
    cin >> a >> b;
    Complex c2(a,b);

    swapTwo(c1,c2);
    cout << "After swapping, first= " << c1 << "Second= " << c2;

    Stack s1(5),s2(4);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s2.push(6);
    s2.push(7);
    s2.push(8);
    s2.push(9);
    cout << "Before swapping:\nStack 1:\n" << s1 << "Stack 2:\n" << s2;
    swapTwo<Stack>(s1,s2);
    cout << "After swapping:\nStack 1:\n" << s1 << "Stack 2:\n" << s2;
    return 0;
}
