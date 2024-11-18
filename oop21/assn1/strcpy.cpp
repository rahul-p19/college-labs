#include <iostream>
using namespace std;

void strcpy(string* const target, string source){
*target = source;
}

int main(){
string name = "rahul";
string college = "jadavpur university";
string dept = "information technology";
string newname, newcollege, newdept;
strcpy(&newname,name);
strcpy(&newcollege,college);
strcpy(&newdept,dept);
cout << "Copied name: " << newname << "\n";
cout << "Copied college: " << newcollege << "\n";
cout << "Copied department: " << newdept << "\n";
return 0;
}
