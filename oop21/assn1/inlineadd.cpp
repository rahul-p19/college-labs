#include <iostream>
using namespace std;
inline int add(int a,int b,int c){
return a+b+c;
}

inline void inlineadd(int a,int b,int c){
cout << a+b+c << "\n";
}

int main(){
int a,b,c;
cout << "Enter the three numbers: ";
cin >> a >> b >> c;
cout << "sum: " << add(a,b,c) << "\n";
cout << "Inline without return statement: \n";
inlineadd(a,b,c);
return 0;
}
