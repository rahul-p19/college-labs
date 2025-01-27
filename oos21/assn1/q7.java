import java.util.Scanner;

abstract class Publication{
	int noOfPages;
	double price;
	String publisherName, authorName;
	Publication(int n, double p, String pub, String auth){
		noOfPages = n;
		price = p;
		publisherName = pub;
		authorName = auth;
	}
	void showDetails(){
		System.out.println("Number of pages: "+noOfPages);
		System.out.println("Price: "+price);
		System.out.println("Publisher Name: "+publisherName);
		System.out.println("Number of pages: "+authorName);
	}
}

class Book extends Publication{
	Book(int n, double p, String pub, String auth){
		super(n,p,pub,auth);
	}
}

class Journal extends Publication{
	Journal(int n, double p, String pub, String auth){
		super(n,p,pub,auth);
	}
}

class Library{
	Publication arr[];

	Library(int s){
		arr = new Publication[s];
	}

	public static void main(String args[]){
		Library ob = new Library(5);		
		Scanner sc = new Scanner(System.in);
		for(int i=0;i<5;i++){
			System.out.print("Enter number of pages: ");
			int n = sc.nextInt();	
			System.out.print("Enter price: ");
			double p = sc.nextDouble();	
			System.out.print("Enter Publisher Name: ");
			String pub = sc.next();	
			System.out.print("Enter Author Name: ");
			String auth = sc.next();
			if(i<3){
				ob.arr[i] = new Book(n,p,pub,auth);
			}else{
				ob.arr[i] = new Journal(n,p,pub,auth);
			}	
		}
		System.out.println("Publication details: ");
		for(int i=0;i<5;i++){
			ob.arr[i].showDetails();
		}
	}
}

