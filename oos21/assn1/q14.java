import java.util.Scanner;

interface Shape {
    double area();
    void draw();
    void rotate();
    void move(int x, int y);
}

class Circle implements Shape {
    double radius;
    int x, y;

    public Circle(double radius, int x, int y) {
        this.radius = radius;
        this.x = x;
        this.y = y;
    }

    public double area() {
        return Math.PI * radius * radius;
    }

    public void draw() {
        System.out.println("Drawing Circle at (" + x + ", " + y + ") with radius " + radius);
    }

    public void rotate() {
        System.out.println("Rotating Circle at (" + x + ", " + y + ")");
    }

    public void move(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Rectangle implements Shape {
    double length, width;
    int x, y;

    public Rectangle(double length, double width, int x, int y) {
        this.length = length;
        this.width = width;
        this.x = x;
        this.y = y;
    }

    public double area() {
        return length * width;
    }

    public void draw() {
        System.out.println("Drawing Rectangle at (" + x + ", " + y + ") with length " + length + " and width " + width);
    }

    public void rotate() {
        System.out.println("Rotating Rectangle at (" + x + ", " + y + ")");
    }

    public void move(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class ShapeDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Circle[] circles = new Circle[2];
        Rectangle[] rectangles = new Rectangle[3];

        for (int i = 0; i < 2; i++) {
            System.out.println("Enter details for Circle " + (i+1) + ": ");
            System.out.print("Radius: ");
            double radius = sc.nextDouble();
            System.out.print("X-coordinate: ");
            int x = sc.nextInt();
            System.out.print("Y-coordinate: ");
            int y = sc.nextInt();
            circles[i] = new Circle(radius, x, y);
        }

        for (int i = 0; i < 3; i++) {
            System.out.println("Enter details for Rectangle " + (i+1) + ": ");
            System.out.print("Length: ");
            double length = sc.nextDouble();
            System.out.print("Width: ");
            double width = sc.nextDouble();
            System.out.print("X-coordinate: ");
            int x = sc.nextInt();
            System.out.print("Y-coordinate: ");
            int y = sc.nextInt();
            rectangles[i] = new Rectangle(length, width, x, y);
        }

        System.out.println("\nBefore Moving Circles:");
        for (int i = 0; i < 2; i++) {
            circles[i].draw();
        }

        System.out.println("\nBefore Moving Rectangles:");
        for (int i = 0; i < 3; i++) {
            rectangles[i].draw();
        }

        System.out.println("\nEnter new coordinates to move the shapes:");
        System.out.print("New X-coordinate: ");
        int newX = sc.nextInt();
        System.out.print("New Y-coordinate: ");
        int newY = sc.nextInt();

        for (int i = 0; i < 2; i++) {
            circles[i].move(newX, newY);
        }

        for (int i = 0; i < 3; i++) {
            rectangles[i].move(newX, newY);
        }

        System.out.println("\nAfter Moving Circles:");
        for (int i = 0; i < 2; i++) {
            circles[i].draw();
        }

        System.out.println("\nAfter Moving Rectangles:");
        for (int i = 0; i < 3; i++) {
            rectangles[i].draw();
        }

        sc.close();
    }
}

