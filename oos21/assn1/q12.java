import java.util.Scanner;

class Student {
	String name;
	int rollNo;
	static String[] subjects = new String[5];

	Student(String name, int rollNo, String[] subjects) {
		this.name = name;
		this.rollNo = rollNo;
		this.subjects = subjects;
	}

	void setName(String name) {
		this.name = name;
	}

	String getName() {
		return name;
	}

	void setRollNo(int rollNo) {
		this.rollNo = rollNo;
	}

	int getRollNo() {
		return rollNo;
	}

	void setSubjects(String[] subjects) {
		this.subjects = subjects;
	}

	String[] getSubjects() {
		return subjects;
	}
}

class TabulationSheet {
	int[] rollNo = new int[3];
	int[] marks = new int[3];

	void addMarks(int rollNo, int marks, int ind) {
		this.rollNo[ind] = rollNo;
		this.marks[ind] = marks;
	}

	void printTabulation() {
		for (int i = 0; i < marks.length; i++) {
			System.out.print("Roll No: " + rollNo[i] + " Marks: ");
			System.out.print(marks[i] + " ");
		}
		System.out.println();
	}
}

class MarkSheet {
	String name;
	int[] marks = new int[5];

	void addMarkSheet(String name, int marks, int ind) {
		this.name = name;
		this.marks[ind] = marks;
	}

	void printMarkSheet() {
		System.out.print("Name: " + name + " Marks: ");
		for (int i = 0; i < 5; i++) {
			System.out.print(marks[i] + " ");
		}
		System.out.println();
	}
}

class Main {
	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		Student[] students = new Student[3];
		String[] subjects = new String[5];

		for (int j = 0; j < 5; j++) {
			System.out.print("Enter subject " + (j + 1) + ": ");
			subjects[j] = scanner.nextLine();
		}

		for (int i = 0; i < 3; i++) {
			System.out.print("Enter name of student " + (i + 1) + ": ");
			String name = scanner.nextLine();
			System.out.print("Enter roll number of student " + (i + 1) + ": ");
			int rollNo = scanner.nextInt();
			scanner.nextLine();
			students[i] = new Student(name, rollNo, subjects);
		}

		TabulationSheet[] tabulationSheets = new TabulationSheet[5];

		for (int i = 0; i < 5; i++) {
			tabulationSheets[i] = new TabulationSheet();
			System.out.println("Enter marks for " + subjects[i] + ": ");

			for (int j = 0; j < 3; j++) {
				System.out.print("Enter marks for student " + (j + 1) + ": ");
				int marks; 
				marks = scanner.nextInt();
				tabulationSheets[i].addMarks(students[j].getRollNo(), marks,j);
			}
		}

		MarkSheet[] markSheets = new MarkSheet[3];

		for (int i = 0; i < 3; i++) {
			markSheets[i] = new MarkSheet();
			for(int j=0;j<5;j++){
				markSheets[i].addMarkSheet(students[i].getName(), tabulationSheets[j].marks[i], j);
			}
		}

		for (int i = 0; i < 3; i++) {
			markSheets[i].printMarkSheet();
		}
	}
}
