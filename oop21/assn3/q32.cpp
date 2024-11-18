#include <iostream>
using namespace std;

class Employee{
	string name;
	double salary;
	public:
	Employee(string n="",double sal=0){
		name=n;
		salary=sal;
	}

	virtual void setDetails(string n, double sal){
		name=n;
		salary=sal;
	}

	virtual double getSalary(){
		return salary;
	}

	virtual void printDetails(){
		cout << "Name: " << name << "\n";
		cout << "Salary: " << salary << "\n";
	}
};

class Manager: public Employee{
	string type;
	double allowance;
	public:
	Manager(string n="",double sal=0,string t="",double a=0):Employee(n,sal){
		type=t;
		allowance=a;
	}

	void setDetails(string n, double sal, string t, double a){
		Employee::setDetails(n,sal);
		type=t;
		allowance=a;
	}

	double getSalary(){
		return Employee::getSalary();
	}

	void printDetails(){
		Employee::printDetails();
		cout << "Type: " << type << "\n";
		cout << "Allowance: " << allowance << "\n";
	}
};

class Clerk: public Employee{
	string type;
	double allowance;
	public:
	Clerk(string n="",double sal=0,string t="",double a=0):Employee(n,sal){
		type=t;
		allowance=a;
	}

	void setDetails(string n, double sal, string t, double a){
		Employee::setDetails(n,sal);
		type=t;
		allowance=a;
	}

	double getsalary(){
		return Employee::getSalary();
	}

	void printDetails(){
		Employee::printDetails();
		cout << "Type: " << type << "\n";
		cout << "Allowance: " << allowance << "\n";
	}
};

int main(){

	// creating a manager and a clerk object and printing details
	Manager m = Manager("John",10000,"Sales",1000);
	Clerk c = Clerk("Jane",7000,"Research",4000);
	m.printDetails();
	c.printDetails();

	// creating array of pointers and displaying details
	Employee* arr[6];

	for(int i=0;i<2;i++){
		string n; double sal;
		cout << "Enter Employee name and salary: ";
		cin >> n >> sal;
		arr[i] = new Employee(n,sal);
	}

	for(int i=2;i<4;i++){
		string n,t; double s,a;
		cout << "Enter Manager name, salary, type and allowance: ";
		cin >> n >> s >> t >> a;
		arr[i] = new Manager(n,s,t,a);
	}

	for(int i=4;i<6;i++){
		string n,t; double s,a;
		cout << "Enter Clerk name, salary, type and allowance: ";
		cin >> n >> s >> t >> a;
		arr[i] = new Clerk(n,s,t,a);
	}
	
	double totalSal = 0;
	for(int i=0;i<6;i++){
		totalSal+=arr[i]->getSalary();
		arr[i]->printDetails();
		delete(arr[i]);
	}
	cout << "Total salary: " << totalSal << "\n";
	
	return 0;
}
