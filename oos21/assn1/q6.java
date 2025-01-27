import java.util.Scanner;
class Employee{
	String name, address;
	int id;
	double salary;
	Employee(String n, String a, int i, double s){
		name=n;
		address=a;
		id=i;
		salary=s;
	}
	void getEmployeeDetails(Employee ob){
		System.out.println("Employee Details: ");
		System.out.println("Employee ID: "+ob.id);
		System.out.println("Employee Name: "+ob.name);
		System.out.println("Employee Address: "+ob.address);
		System.out.println("Employee Salary: "+ob.salary);
	}
}

class Dept{
	Employee arr[];
	Dept(int s){
		arr = new Employee[s];
	}
	void add(int ind){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Employee Name: ");
		String n = sc.next();
		System.out.print("Enter Employee Address: ");
		String a = sc.next();
		System.out.print("Enter Employee Salary: ");
		Double s = sc.nextDouble();
		arr[ind] = new Employee(n,a,ind+1,s);
	}
	void delete(int ind){
		arr[ind] = null;
	}
	public static void main(String args[]){
		Dept InfoTech = new Dept(5);
		for(int i=0;i<5;i++){
			InfoTech.add(i);
		}
		double expenditure = 0;
		for(int i=0;i<5;i++){
			expenditure += InfoTech.arr[i].salary;
		}
		System.out.println("Total yearly expenditure of the department: "+expenditure);
	}
}
