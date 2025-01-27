import java.util.Scanner;

class Account{
	int accountNumber;
	String holderName;
	double balance;
	Account(int a, String h, double b){
		accountNumber = a;
		holderName = h;
		balance = b;
	}
	void showDetails(){
		System.out.println("\nAccount Details: ");
		System.out.println("Account Number: "+accountNumber);
		System.out.println("Account Holder Name: "+holderName);
		System.out.println("Balance: "+balance);
	}
}

class SavingsAccount extends Account{
	double interestRate;
	SavingsAccount(int a, String h, double b, double i){
		super(a,h,b);
		interestRate = i;
	}
	double calculateYearlyInterest(){
		return balance * interestRate / 100;
	}
}

class CurrentAccount extends Account{
	CurrentAccount(int a, String h, double b){
		super(a,h,b);
	}
}

class Manager{
	Account arr[];
	Manager(int s){
		arr = new Account[s];
	}
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		Manager ob = new Manager(5);		
		for(int i=0;i<5;i++){
			System.out.print("Enter account number: ");
			int a = sc.nextInt();				
			System.out.print("Enter holder name: ");
			String n = sc.next();				
			System.out.print("Enter balance: ");
			double b = sc.nextDouble();				
			if(i<2){
				System.out.print("Enter interest rate: ");
				double ir = sc.nextDouble();				
				ob.arr[i] = new SavingsAccount(a,n,b,ir);
				System.out.println("Yearly interest: "+((SavingsAccount)ob.arr[i]).calculateYearlyInterest());
			}else{
				ob.arr[i] = new CurrentAccount(a,n,b);
			}
		}
		for(int i=0;i<5;i++){
			ob.arr[i].showDetails();
		}
	}
}
