#include <iostream>
#include "complex.h"
using namespace std;

template<class T>
class Stack{
    int top,size;
    T *arr;

    public:
    Stack(int ss=5){
        size=ss;
        top=-1;
        arr = new T[size];
    }

    void push(T x){
        if(top==size-1) cout << "Stack overflow\n";
        arr[++top]=x;
    }

    T pop(){
        if(top==-1) cout << "Stack underflow\n";
        return arr[top--];
    }

    friend ostream& operator<<(ostream &os, Stack s){
        for(int i=0;i<=s.top;i++){
            cout << s.arr[i] << " ";
        }
        cout << "\n";
        return os;
    }
};

int main(){
    Stack<int> s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.pop();
    s1.pop();
    cout << s1;

    Stack<Complex> s2(5);
    s2.push(Complex(1,2));
    s2.push(Complex(3,4));
    s2.push(Complex(5,6));
    s2.push(Complex(7,8));
    s2.push(Complex(9,10));
    s2.pop();
    s2.pop();
    cout << s2;

    return 0;
}