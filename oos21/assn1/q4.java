import java.util.Scanner;
class BankAccount{
	int accountNumber;
	float balance;
	String ownerName;
	BankAccount(int a, float b, String n){
		accountNumber = a;
		balance = b;
		ownerName = n;
	}
	void showBalance(){
		System.out.println(" Balance: "+balance);
	}
	void add(float amt){
		balance += amt;
	}
	void subtract(float amt){
		balance -= amt;
	}
}

class AccountManager{
	BankAccount accounts[]; 
	AccountManager(int s){
		accounts = new BankAccount[s];
	}
	void create(int ind){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Account Number: ");
		int a = sc.nextInt();
		System.out.print("Enter Account Owner Name: ");
		String name = sc.next();
		System.out.print("Enter Account balance: ");		
		float b = sc.nextFloat();
		accounts[ind] = new BankAccount(a,b,name);
	}
	void delete(int ind){
		accounts[ind] = null;
	}
	void deposit(float amt, int ind){
		accounts[ind].add(amt);
	}
}

class Bank{
	public static void main(String args[]){
		AccountManager ob = new AccountManager(5);
		for(int i=0;i<5;i++){
			ob.create(i);		
		}
		for(int i=0;i<5;i++){
			System.out.print("Account Number: "+ob.accounts[i].accountNumber + " Account Owner Name: "+ob.accounts[i].ownerName);		
			ob.accounts[i].showBalance();
		}
	}
}
