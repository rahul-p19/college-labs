import java.util.Scanner;

class Book {
	String author;
	String title;
	String publisher;
	double cost;
	int stock;

	Book(String a, String t, String p, double c, int s) {
		 author = a;
		 title = t;
		 publisher = p;
		 cost = c;
		 stock = s;
	}

	boolean matches(String title, String author) {
		return this.title.equalsIgnoreCase(title) && this.author.equalsIgnoreCase(author);
	}

	void displayDetails() {
		System.out.println("\nBook Details:");
		System.out.println("Title: " + title);
		System.out.println("Author: " + author);
		System.out.println("Publisher: " + publisher);
		System.out.println("Cost: $" + cost);
		System.out.println("Stock: " + stock);
	}

	boolean sellCopies(int copies) {
		if (copies <= stock) {
			stock -= copies;
			System.out.println("Total Cost: $" + (copies * cost));
			return true;
		} else {
			System.out.println("Requested copies not in stock.");
			return false;
		}
	}
}

class Bookshop {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		Book[] books = {
			new Book("J.K. Rowling", "Harry Potter", "Bloomsbury", 20.5, 10),
			new Book("J.R.R. Tolkien", "The Hobbit", "HarperCollins", 15.0, 5),
			new Book("George Orwell", "1984", "Secker & Warburg", 18.0, 8)
		};

		System.out.println("Enter book title:");
		String title = sc.nextLine();
		System.out.println("Enter author name:");
		String author = sc.nextLine();

		boolean found = false;
		for (int i=0;i<books.length;i++) {
			if (books[i].matches(title, author)) {
				found = true;
				books[i].displayDetails();

				System.out.println("Enter the number of copies required:");
				int copies = sc.nextInt();
				books[i].sellCopies(copies);
				break;
			}
		}

		if (!found) {
			System.out.println("Book not available in the inventory.");
		}

		sc.close();
	}
}

