import java.util.Scanner;

class Date {

	int day, month, year;

	int[] daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	Date() {
		this.day = 1;
		this.month = 1;
		this.year = 1970;
	}

	Date(int day) {
		this.day = day;
		this.month = 1;
		this.year = 1970;
	}

	Date(int day, int month) {
		this.day = day;
		this.month = month;
		this.year = 1970;
	}

	Date(int day, int month, int year) {
		this.day = day;
		this.month = month;
		this.year = year;
	}

	boolean isLeapYear(int year) {
		if (year % 4 == 0) {
			if (year % 100 == 0) {
				if (year % 400 == 0)
					return true;
				else
					return false;
			}
			return true;
		}
		return false;
	}
	
	int getDaysInMonth(int month, int year) {
		if (month == 2 && isLeapYear(year)) {
			return 29;
		}
		return daysInMonth[month - 1];
	}

	void printDate() {
		System.out.printf("%02d/%02d/%04d\n", day, month, year);
	}

	void getPreviousDay() {
		if (day > 1) {
			--day;
		} else {
			if (month > 1) {
				--month;
				day = getDaysInMonth(month, year);
			} else {
				--year;
				month = 12;
				day = getDaysInMonth(month, year);
			}
		}
	}

	void getNextDay() {
		if (day < getDaysInMonth(month, year)) {
			++day;
		} else {
			if (month < 12) {
				++month;
				day = 1;
			} else {
				++year;
				month = 1;
				day = 1;
			}
		}
	}

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		System.out.println("Choose an option to create a date:");
		System.out.println("1. Default date (01/01/1970)");
		System.out.println("2. Date with user-specified day");
		System.out.println("3. Date with user-specified day and month");
		System.out.println("4. Date with user-specified day, month, and year");

		int option = scanner.nextInt();
		Date date;
		switch (option) {
			case 1:
				date = new Date();
				break;
			case 2:
				System.out.print("Enter the day: ");
				int day = scanner.nextInt();
				date = new Date(day);
				break;
			case 3:
				System.out.print("Enter the day: ");
				int day1 = scanner.nextInt();
				System.out.print("Enter the month: ");
				int month1 = scanner.nextInt();
				date = new Date(day1, month1);
				break;
			case 4:
				System.out.print("Enter the day: ");
				int day2 = scanner.nextInt();
				System.out.print("Enter the month: ");
				int month2 = scanner.nextInt();
				System.out.print("Enter the year: ");
				int year2 = scanner.nextInt();
				date = new Date(day2, month2, year2);
				break;
			default:
				System.out.println("Invalid option");
				return;
		}

		System.out.println("Initial Date: ");
		date.printDate();
		date.getPreviousDay();

		System.out.println("Previous Day: ");
		date.printDate();
		date.getNextDay();
		date.getNextDay();

		System.out.println("Next Day: ");
		date.printDate();
		scanner.close();
	}
}

