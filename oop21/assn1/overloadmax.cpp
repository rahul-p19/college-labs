#include <iostream>
using namespace std;
int max(int a,int b,int c){
int max=a;
if(b>max) max=b;
if(c>max) max=c;
return max;
}

int max(int arr[]){
int max=arr[0];
for(int i=0;i<(sizeof(arr));i++){
if (arr[i]>max){
 max=arr[i];
}
}
return max;
}

int main(){
int choice;
cout << "Enter 1 for 3 numbers, 2 for arrays: ";
cin >> choice;
if(choice==1){
int a,b,c;
cout << "Enter the three numbers: ";
cin >> a >> b >> c;
cout << "Maximum: " << max(a,b,c) << "\n";
}
else if(choice ==2){
int arr[100];
int n;
cout << "Enter array size: ";
cin >> n;
cout << "Enter array elements: ";
for(int i=0;i<n;i++) cin >> arr[i];
cout << "Maximum of array: " << max(arr) << "\n";
}
else cout << "Invalid input";
return 0;
}
