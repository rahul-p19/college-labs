interface Fruit {
    boolean hasAPeel();
}

interface Vegetable {
    boolean hasARoot();
}

class Tomato implements Fruit, Vegetable {
    public boolean hasAPeel() {
        return true;
    }

    public boolean hasARoot() {
        return true;
    }
}

class FruitDemo {
    public static void main(String[] args) {
        Tomato tomato = new Tomato();
        
        System.out.println("Does the Tomato have a peel? " + tomato.hasAPeel());
        System.out.println("Does the Tomato have a root? " + tomato.hasARoot());

    }
}

