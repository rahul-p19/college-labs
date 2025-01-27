import java.util.Scanner;

class Person{
	int age;
	double weight, height;
	String address, dob, name;

	Person(int a, double w, double h, String add, String d, String n){
		age=a;
		weight=w;
		height=h;
		address=add;
		dob=d;
		name=n;
	}

	void showDetails(){
		System.out.println("\nName: "+name);
		System.out.println("Age: "+age);
		System.out.println("Weight: "+weight);
		System.out.println("Height: "+height);
		System.out.println("Address: "+address);
		System.out.println("Date of Birth: "+dob);
	}
}

class Employee extends Person{
	double salary;
	String joinDate, experience;
	Employee(int a, double w, double h, String add, String d, String n, double sal, String jd, String exp){
		super(a,w,h,add,d,n);
		salary=sal;
		joinDate = jd;
		experience = exp;
	}
}

class Student extends Person{
	int roll;
	String subjects[];
	int marks[];
	Student(int a, double w, double h, String add, String d, String n, int r, String s[], int m[]){
		super(a,w,h,add,d,n);
		roll=r;
		subjects = s;
		marks = m;	
	}

	void calculateGrade(){
		double sum=0;
		for(int i=0;i<marks.length;i++){
			sum += marks[i];
		}
		sum /= marks.length;
		System.out.println("Grade: "+sum);
	}
}

class Technician extends Employee{
	int technicianId;
	Technician(int a, double w, double h, String add, String d, String n, double sal, String jd, String exp, int id){
		super(a,w,h,add,d,n,sal,jd,exp);
		technicianId = id;
	}
}

class Professor extends Employee{
	String courses[], listOfAdvisee[];
	Professor(int a, double w, double h, String add, String d, String n, double sal, String jd, String exp, String c[], String loa[]){
		super(a,w,h,add,d,n,sal,jd,exp);
		courses=c;
		listOfAdvisee = loa;
	}
	void addCourse(int ind, String course){
		courses[ind] = course;
	}
	void deleteCourse(int ind){
		courses[ind] = null;
	}
	void addAdvisee(int ind, String advisee){
		listOfAdvisee[ind] = advisee;
	}
	void deleteAdvisee(int ind){
		listOfAdvisee[ind] = null;
	}
}

class PersonDemo{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter details for Person:");
		System.out.print("Name: ");
		String name = sc.nextLine();
		System.out.print("Age: ");
		int age = sc.nextInt();
		System.out.print("Weight: ");
		double weight = sc.nextDouble();
		System.out.print("Height: ");
		double height = sc.nextDouble();
		sc.nextLine();
		System.out.print("Address: ");
		String address = sc.nextLine();
		System.out.print("Date of Birth: ");
		String dob = sc.nextLine();
		Person person = new Person(age, weight, height, address, dob, name);
		person.showDetails();
		
		System.out.println("\nEnter details for Employee:");
		System.out.println("Enter details for Employee:");
		System.out.print("Name: ");
		name = sc.nextLine();
		System.out.print("Age: ");
		age = sc.nextInt();
		System.out.print("Weight: ");
		weight = sc.nextDouble();
		System.out.print("Height: ");
		height = sc.nextDouble();
		sc.nextLine();
		System.out.print("Address: ");
		address = sc.nextLine();
		System.out.print("Date of Birth: ");
		dob = sc.nextLine();
		System.out.print("Salary: ");
		double salary = sc.nextDouble();
		sc.nextLine();
		System.out.print("Joining Date: ");
		String joinDate = sc.nextLine();
		System.out.print("Experience: ");
		String experience = sc.nextLine();
		Employee employee = new Employee(age, weight, height, address, dob, name, salary, joinDate, experience);
		
		System.out.println("\nEnter details for Technician:");
		System.out.print("Technician ID: ");
		int techId = sc.nextInt();
		Technician technician = new Technician(age, weight, height, address, dob, name, salary, joinDate, experience, techId);
		
		System.out.println("\nEnter details for Student:");
		System.out.print("Name: ");
		name = sc.next();
		System.out.print("Age: ");
		age = sc.nextInt();
		System.out.print("Weight: ");
		weight = sc.nextDouble();
		System.out.print("Height: ");
		height = sc.nextDouble();
		sc.nextLine();
		System.out.print("Address: ");
		address = sc.nextLine();
		System.out.print("Date of Birth: ");
		dob = sc.nextLine();
		System.out.print("Roll Number: ");
		int roll = sc.nextInt();
		sc.nextLine();
		System.out.print("Enter number of subjects: ");
		int numSubjects = sc.nextInt();
		sc.nextLine();
		String[] subjects = new String[numSubjects];
		int[] marks = new int[numSubjects];
		for (int i = 0; i < numSubjects; i++) {
			System.out.print("Subject " + (i + 1) + ": ");
			subjects[i] = sc.nextLine();
			System.out.print("Marks for " + subjects[i] + ": ");
			marks[i] = sc.nextInt();
			sc.nextLine();
		}
		
		Student student = new Student(age, weight, height, address, dob, name, roll, subjects, marks);
		student.showDetails();
		student.calculateGrade();
		System.out.println("\nEnter details for Professor:");
		System.out.print("Number of courses: ");
		int numCourses = sc.nextInt();
		sc.nextLine();
		String[] courses = new String[numCourses];
		String[] advisees = new String[numCourses];
		for (int i = 0; i < numCourses; i++) {
			System.out.print("Course " + (i + 1) + ": ");
			courses[i] = sc.nextLine();
			System.out.print("Advisee " + (i + 1) + ": ");
			advisees[i] = sc.nextLine();
		}
		
		Professor professor = new Professor(age, weight, height, address, dob, name, salary, joinDate, experience, courses, advisees);
		professor.showDetails();
		sc.close();
	}
}
