#include <iostream>
using namespace std;

class Collision {
   public:
    Collision() {
        cout << "Cars must be stopped. There may be collision\n";
    }
};

class Vehicle {
    int direction, speed, x;

   public:
    Vehicle(int d = 0, int s = 0, int xx = 0) {
        direction = d;
        speed = s;
        x = xx;
    }

    friend void detectCollision(Vehicle &v1, Vehicle &v2) {
        bool flag = false;
        if (v1.x == v2.x) flag = true;
        // v1   v2
        else if (v1.x < v2.x) {
            if ((v1.direction > 0 && v2.direction < 0) || (v1.direction > 0 && v2.direction > 0 && v1.speed > v2.speed) || (v1.direction < 0 && v2.direction < 0 && v2.speed > v1.speed))
                flag = true;
        } else {
            // v2   v1
            if ((v2.direction > 0 && v1.direction < 0) || (v2.direction > 0 && v1.direction > 0 && v2.speed > v1.speed) || (v2.direction < 0 && v1.direction < 0 && v1.speed > v2.speed))
                flag = true;
        }

        if (flag)
            throw Collision();
        else
            cout << "No collision\n";
    }
};

int main() {
    // Vehicle v1(-1), v2(1);
    int ss, dd, xx;
    cout << "Enter position, direction and speed: ";
    cin >> xx >> dd >> ss;
    Vehicle v1(dd,ss,xx);
    cout << "Enter position, direction and speed: ";
    Vehicle v2(dd,ss,xx);
    cin >> xx >> dd >> ss;
    try{
    detectCollision(v1, v2);
    }
    catch(Collision ob){
    }
    
    return 0;
}
