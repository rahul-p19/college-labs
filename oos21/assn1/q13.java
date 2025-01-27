import java.util.Scanner;

class Automobile {
    String make;
    String type;
    int maxSpeed;
    double price;
    double mileage;
    String registrationNumber;

    public void setMake(String make) {
        this.make = make;
    }

    public String getMake() {
        return make;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getType() {
        return type;
    }

    public void setMaxSpeed(int maxSpeed) {
        this.maxSpeed = maxSpeed;
    }

    public int getMaxSpeed() {
        return maxSpeed;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public double getPrice() {
        return price;
    }

    public void setMileage(double mileage) {
        this.mileage = mileage;
    }

    public double getMileage() {
        return mileage;
    }

    public void setRegistrationNumber(String registrationNumber) {
        this.registrationNumber = registrationNumber;
    }

    public String getRegistrationNumber() {
        return registrationNumber;
    }
}

class Track extends Automobile {
    int capacity;
    String hoodType;
    int noOfWheels;

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setHoodType(String hoodType) {
        this.hoodType = hoodType;
    }

    public String getHoodType() {
        return hoodType;
    }

    public void setNoOfWheels(int noOfWheels) {
        this.noOfWheels = noOfWheels;
    }

    public int getNoOfWheels() {
        return noOfWheels;
    }
}

class Car extends Automobile {
    int noOfDoors;
    int seatingCapacity;

    public void setNoOfDoors(int noOfDoors) {
        this.noOfDoors = noOfDoors;
    }

    public int getNoOfDoors() {
        return noOfDoors;
    }

    public void setSeatingCapacity(int seatingCapacity) {
        this.seatingCapacity = seatingCapacity;
    }

    public int getSeatingCapacity() {
        return seatingCapacity;
    }
}

class AutomobileDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Track[] tracks = new Track[2];
        Car[] cars = new Car[2];

        for (int i = 0; i < 2; i++) {
            tracks[i] = new Track();
            System.out.println("Enter details for Track " + (i+1) + ": ");
            System.out.print("Make: ");
            tracks[i].setMake(sc.nextLine());
            System.out.print("Type: ");
            tracks[i].setType(sc.nextLine());
            System.out.print("Max Speed: ");
            tracks[i].setMaxSpeed(sc.nextInt());
            System.out.print("Price: ");
            tracks[i].setPrice(sc.nextDouble());
            System.out.print("Mileage: ");
            tracks[i].setMileage(sc.nextDouble());
            sc.nextLine();
            System.out.print("Registration Number: ");
            tracks[i].setRegistrationNumber(sc.nextLine());
            System.out.print("Capacity: ");
            tracks[i].setCapacity(sc.nextInt());
            sc.nextLine();
            System.out.print("Hood Type: ");
            tracks[i].setHoodType(sc.nextLine());
            System.out.print("No of Wheels: ");
            tracks[i].setNoOfWheels(sc.nextInt());
            sc.nextLine();
        }

        for (int i = 0; i < 2; i++) {
            cars[i] = new Car();
            System.out.println("Enter details for Car " + (i+1) + ": ");
            System.out.print("Make: ");
            cars[i].setMake(sc.nextLine());
            System.out.print("Type: ");
            cars[i].setType(sc.nextLine());
            System.out.print("Max Speed: ");
            cars[i].setMaxSpeed(sc.nextInt());
            System.out.print("Price: ");
            cars[i].setPrice(sc.nextDouble());
            System.out.print("Mileage: ");
            cars[i].setMileage(sc.nextDouble());
            sc.nextLine();
            System.out.print("Registration Number: ");
            cars[i].setRegistrationNumber(sc.nextLine());
            System.out.print("No of Doors: ");
            cars[i].setNoOfDoors(sc.nextInt());
            System.out.print("Seating Capacity: ");
            cars[i].setSeatingCapacity(sc.nextInt());
            sc.nextLine();
        }

        System.out.println("\nTrack Details: ");
        for (int i = 0; i < 2; i++) {
            System.out.println("Track " + (i+1) + ": ");
            System.out.println("Make: " + tracks[i].getMake());
            System.out.println("Type: " + tracks[i].getType());
            System.out.println("Max Speed: " + tracks[i].getMaxSpeed());
            System.out.println("Price: " + tracks[i].getPrice());
            System.out.println("Mileage: " + tracks[i].getMileage());
            System.out.println("Registration Number: " + tracks[i].getRegistrationNumber());
            System.out.println("Capacity: " + tracks[i].getCapacity());
            System.out.println("Hood Type: " + tracks[i].getHoodType());
            System.out.println("No of Wheels: " + tracks[i].getNoOfWheels());
            System.out.println();
        }

        System.out.println("Car Details: ");
        for (int i = 0; i < 2; i++) {
            System.out.println("Car " + (i+1) + ": ");
            System.out.println("Make: " + cars[i].getMake());
            System.out.println("Type: " + cars[i].getType());
            System.out.println("Max Speed: " + cars[i].getMaxSpeed());
            System.out.println("Price: " + cars[i].getPrice());
            System.out.println("Mileage: " + cars[i].getMileage());
            System.out.println("Registration Number: " + cars[i].getRegistrationNumber());
            System.out.println("No of Doors: " + cars[i].getNoOfDoors());
            System.out.println("Seating Capacity: " + cars[i].getSeatingCapacity());
            System.out.println();
        }
        
        sc.close();
    }
}

