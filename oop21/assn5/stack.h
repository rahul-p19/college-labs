#include <iostream>
using namespace std;

class Overflow {
   public:
    Overflow() {
        cout << "Stack is full\n";
    }
};

class Underflow {
   public:
    Underflow() {
        cout << "No elements to delete\n";
    }
};

class Stack {
   public:
    int top, size;
    int *arr;
    Stack(int s = 0) {
        size = s;
        top = -1;
        arr = new int[size];
    }

    void push(int val) {
        if (top >= size - 1) throw Overflow();
        arr[++top] = val;
    }

    int pop() {
        if (top == -1) throw Underflow();
        return arr[top--];
    }

    friend ostream &operator<<(ostream &os, Stack s) {
        for (int i = 0; i <= s.top; i++) {
            cout << s.arr[i] << " ";
        }
        cout << "\n";
		return os;
    }
};