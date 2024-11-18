#include <iostream>
using namespace std;

void print(int arr[],int n){
	cout << "Elements of vector: \n";
	for(int i=0;i<n;i++) cout << arr[i] << " ";
}

void print(int arr[][100],int m, int n){
	cout << "Elements of matrix:\n";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++) cout << arr[i][j] << " ";
		cout << "\n";
	}
}

int main(){
	int choice;
	cout << "Enter 1 for vector, 2 for matrix: ";
	cin >> choice;
	if(choice==1){
		int n;
		cout << "Enter size of vector: ";
		cin >> n;
		int arr[100];
		cout << "Enter elements of vector: ";
		for(int i=0;i<n;i++) cin >> arr[i];
		print(arr,n);
	}
	else if (choice ==2){
		int m,n;
		cout << "Enter number of rows and columns: ";
		cin >> m >> n;
		int arr[100][100];
		cout << "Enter elements of matrix: ";
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++) cin >> arr[i][j];
		}
		print(arr,m,n);
	}
	else cout << "Invalid Input\n";
	return 0;
}
