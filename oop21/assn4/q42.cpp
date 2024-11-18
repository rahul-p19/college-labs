#include <iostream>
using namespace std;

class Table{
int x,y;
int **arr;
public:
Table(int xx=0, int yy=0){
x=xx;
y=yy;
arr = new int*[x];
for(int i=0;i<x;i++){
arr[i] = new int[y];
}
}

friend istream& operator>>(istream& is, Table& t){
cout << "Enter the table: ";
for(int i=0;i<t.x;i++){
for(int j=0;j<t.y;j++){
is >> t.arr[i][j];
}
}
return is;
}

friend ostream& operator<<(ostream& os, Table t){
cout << "Table:\n";
for(int i=0;i<t.x;i++){
for(int j=0;j<t.y;j++){
os << t.arr[i][j] << " ";
}
os << "\n";
}
return os;
}

int* operator[](int i){
if(i>=x) return this->arr[0];
return this->arr[i];
}

};

int main(){
Table t(4, 5), t1(4, 5);
cin >> t;
t[0][0] = 5;
int x = t[2][3];
t1 = t;
cout << t << "\n" << t1;
return 0;
}
