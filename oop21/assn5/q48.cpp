#include <iostream>
using namespace std;

class MotorTrouble {
   public:
    MotorTrouble() {
        cout << "There are issues with the motor.\n";
    }
};

class PoorGarage{
    public:
    PoorGarage(){
        cout << "The garage is poor.\n";
    }
};

class Garage {
    class Car {
        class Motor {
            bool trouble = false;
            public:
            Motor(bool tt = false) {
                trouble = tt;
            }
            void setTrouble() {
                trouble = true;
                throw MotorTrouble();
            }
        };
        public:
        Car(bool mt = false) {
            Motor ob;
            if (mt) ob.setTrouble();
        }
    };
    public:
    Garage(bool poorGarage = false) {
            try {
                Car carOb(poorGarage);
            } catch (MotorTrouble ob) {
                cout << "Motor trouble error caught in Garage constructor.\n";
                throw PoorGarage();
            }
    }
};

int main(){
    try{
        bool flag;
        string ans;
        cout << "Does the car have troubles?(Y/N)";
        cin >> ans;
        if(ans!="Y" && ans!="N") cout << "Please give valid answer.\n";
        flag = ans == "Y"? true:false;
        Garage ob(flag);
    }catch(PoorGarage &ob){
        cout << "Poor Garage error caught in main.\n";
    }
}