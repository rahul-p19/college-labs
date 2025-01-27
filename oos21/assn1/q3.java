class Stack{
	int arr[];
	int top, size;
	Stack(int s){
		size = s;
		top=-1;
		arr = new int[s];
	}
	void push(int val){
		if(top>=size-1){
			System.out.println("Stack overflow.");
			return;
		}
		arr[++top]=val;
	}
	int pop(){
		if(top==-1){
			System.out.println("Stack empty. Cannot delete");
			return -999;		
		}
		return arr[top--];
	}
	void print(){
		System.out.println("Stack: ");
		for(int i=top;i>=0;i--){
			System.out.println(arr[i]);
		}
	}

	public static void main(String args[]){
		Stack s = new Stack(30);
		s.push(10);
		s.push(20);
		s.push(30);
		s.push(15);
		s.push(9);
		s.print();
		s.pop();
		s.pop();
		s.pop();
		s.print();
	}

}
