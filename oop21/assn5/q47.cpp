#include <iostream>
using namespace std;

class Overflow{
public:
Overflow(){
cout << "Stack is full\n";
}
};

class Underflow{
public:
Underflow(){
cout << "No elements to delete\n";
}
};

class Stack{
int top,size;
int *arr;
public:
Stack(int s=0){
size=s;
top=-1;
arr = new int[size];
}

void push(int val){
	if(top>=size-1) throw Overflow();
	arr[++top]=val;
}

int pop(){
if(top==-1) throw Underflow();
return arr[top--];
}
};

int main(){
// try catch block to display overflow error
Stack s(5);
try{
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);
s.push(6);
}
catch(Underflow u){}
catch(Overflow o){}

// another block to display underflow error
Stack st(5);
try{
st.pop();
}
catch(Underflow u){}
catch(Overflow o){}
return 0;
}
