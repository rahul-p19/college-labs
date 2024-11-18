#include <iostream>
using namespace std;

class IntArray{
int size;
int *arr;
public:
IntArray(int s=20){
size = 10;
arr = new int[size];
}

int& operator[](int i){
if (i>=size) return arr[0];
return arr[i];
}

friend ostream& operator<<(ostream& os, IntArray arr){
for(int i=0;i<arr.size;i++){
os << arr[i] << " ";
}
os << "\n";
}

};

int main() {
IntArray i(10);
for(int k = 0; k < 10; k++)
i[k] = k;
cout << i;
return 0;
}
