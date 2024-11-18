#include <iostream>
using namespace std;

void errorhandling(int *arr){
	int i=0;
	for(i=0;i<3;i++){
		try{
			if(arr[i]>0) throw "Negative";
			else throw arr[i];
		}

		catch(int x){
			cout << "Catching integer error: " << x << "\n";
		}
		catch(const char *s){
			cout << "Catching string error: " << s << "\n"; 
		}
	}
}

int main(){
	int arr1[3] = {-1,0,1};
	errorhandling(arr1);
	return 0;
}
