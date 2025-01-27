import java.util.Scanner;
class Student{
	String name;
	int marks[] = new int[3];
	Student(String n, int m[]){
		name = n;
		marks = m;
	}
	void average(){
		double avg = 0;
		for(int i=0;i<marks.length;i++){
			avg += marks[i];
		}
		avg /= marks.length;
		System.out.println("Average marks for "+this.name+" = "+avg);
	}
	void display(){
		System.out.println("Student details: ");
		System.out.println("Name: "+name);
		int sum = 0;
		System.out.print("Marks: ");
		for(int i=0;i<marks.length;i++){
			sum += marks[i];
			System.out.println(marks[i]);
		}
		System.out.println("Total marks: "+sum);
	}

	public static void main(String args[]){
		String n;
		System.out.print("Enter name: ");
		Scanner sc = new Scanner(System.in);
		n = sc.nextLine();
		int m[] = new int[3];
		for(int i=0;i<m.length;i++){
			System.out.print("Enter marks for subject "+(i+1)+": ");
			m[i] = sc.nextInt();
		}
		Student s = new Student(n,m);
		s.average();
		s.display();
	}

}
