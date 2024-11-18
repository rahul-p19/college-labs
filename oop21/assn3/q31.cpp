#include <iostream>
using namespace std;

class Person{
	string name;
	int age;
	double height;
	public:
	Person(string n="",int a=0,double h=0){
		name=n;
		age=a;
		height=h;
	}
	virtual void setDetails(string s,int a, double h){
		name=s;
		age=a;
		height=h;
	}

	virtual void printDetails(){
		cout << "Name: " << name << "\n";
		cout << "Age: " << age << "\n";
		cout << "Height: " << height << "\n";
	}
};

class Student: public Person {
	int roll;
	int year;
	public:
	Student(string n="", int a=0, double h=0, int r=0, int y=0):Person(n,a,h){
		roll=r;
		year=y;
	}

	void setDetails(string n, int a, double h, int r, int y){
		Person::setDetails(n,a,h);
		roll=r;
		year=y;
	}
	void printDetails(){
		Person::printDetails();
		cout << "Roll Number: " << roll << "\n";
		cout << "Year of admission: " << year << "\n";
	}
};

int main(){
	// creating two objects and calling printDetails() using them

	cout << "Creating 2 objects and calling printDetails():\n";
	Person p("Rahul",19,186);
	Student s("John",18,180,21,2023);
	p.printDetails();
	s.printDetails();

	// creating array of pointers to Person class and calling printDetails()

	cout << "Creating array of pointers and calling printDetails():\n";
	Person* arr[4];
	for(int i=0;i<2;i++){
		// input two persons
		string n; int a; double h;
		cout << "Enter name, age and height: ";
		cin >> n >> a >> h;
		arr[i]= new Person(n,a,h);
		//arr[i]->setDetails(n,a,h);
	}
	for(int i=2;i<4;i++){
		// input two students
		string n; double h; int a,r,y;
		cout << "Enter name, age, height, roll number and year of admission: ";
		cin >> n >> a >> h >> r >> y;
		arr[i] = new Student(n,a,h,r,y);
		//arr[i]->setDetails(n,a,h,r,y);
	}

	for(int i=0;i<4;i++){
		arr[i]->printDetails();
		delete(arr[i]);
	}
	return 0;
}
