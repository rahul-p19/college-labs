#include<iostream>
using namespace std;

class Stack {
	int *buffer, top,size;
	public :
	Stack(int size):size(size),buffer(new int[size]),top(-1) {

	}; //create a stack with specified size
	void push(int x){
		if(top>=size){
			cout << "Stack overflow!" <<  endl;
		}
		else{
			top++;
			buffer[top]=x;}
	} //push the specified item
	int pop(){
		if(top==-1){
			return -1;
		}
		else{
			return buffer[top--];
		}}
		void disp(){
			for (int i = top; i >= 0; --i) {
				cout << buffer[i] << " ";
			}
			cout <<  endl;
		}

	//displays elements in the stack in top to bottom order

};
int main() {
	Stack s(10);

	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	s.disp();

	s.pop();
	s.disp();

	return 0;
}
