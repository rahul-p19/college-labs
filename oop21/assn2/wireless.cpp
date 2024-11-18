// question 18
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
class Point {
public:
    double x, y, z;

    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    double distance(Point& other) {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
    }
};


class WirelessDevice {
private:
    static int idCounter;
    int id;
    Point location;
    double range;

public:
    WirelessDevice(double range = 10.0) : id(++idCounter), range(range) {
        location = Point(rand() % 100, rand() % 100, rand() % 100);
    }

    Point& getLocation() {
        return location;
    }

    double getRange() {
        return range;
    }

    void move() {
        location = Point(rand() % 100, rand() % 100, rand() % 100);
    }

    bool isNeighbor(WirelessDevice& other) {
        return location.distance(other.getLocation()) <= range;
    }

    int getId(){
        return id;
    }
};

int WirelessDevice::idCounter = 0;

int main() {
     WirelessDevice devices[10];

    for (int i = 0; i < 10; ++i) {
         cout << "Device " << devices[i].getId() << " neighbors: ";
        for (int j = 0; j < 10; ++j) {
            if (i != j && devices[i].isNeighbor(devices[j])) {
                 cout << devices[j].getId() << " ";
            }
        }
         cout <<  "\n";
    }

     cout << "\nAfter moving devices to new locations:\n";

    for (auto& device : devices) {
        device.move();
    }

    for (int i = 0; i < 10; ++i) {
         cout << "Device " << devices[i].getId() << " neighbors: ";
        for (int j = 0; j < 10; ++j) {
            if (i != j && devices[i].isNeighbor(devices[j])) {
                 cout << devices[j].getId() << " ";
            }
        }
         cout <<  "\n";
    }

    return 0;
}
