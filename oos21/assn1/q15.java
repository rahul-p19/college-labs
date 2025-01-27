import java.util.Scanner;

class Tollbooth {
    int totalCarsPassed;
    int carsWithoutPaying;
    double totalCashCollected;
    final double tollAmount = 50;

    public void carPassed(boolean paid) {
        totalCarsPassed++;
        if (paid) {
            totalCashCollected += tollAmount;
        } else {
            carsWithoutPaying++;
        }
    }

    public void printDetails() {
        System.out.println("The total number of cars passed by without paying: " + carsWithoutPaying);
        System.out.println("Total number of cars passed by: " + totalCarsPassed);
        System.out.println("Total cash collected: Rs. " + totalCashCollected);
    }
}

class TollboothDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Tollbooth tollbooth = new Tollbooth();
        int n;

        System.out.print("Enter number of cars to process: ");
        n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.print("Did car " + (i+1) + " pay the toll? (true/false): ");
            boolean paid = sc.nextBoolean();
            tollbooth.carPassed(paid);
        }

        tollbooth.printDetails();
        sc.close();
    }
}

