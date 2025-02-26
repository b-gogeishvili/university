package Quiz2;

public class Main {
    public static void main(String[] args) {
        // Car
        Car car = new Car("Civic", "Honda");
        car.displayInfo();
        car.startEngine();

        System.out.println("---------------------------------------------------");

        // Motorcycle
        Motorcycle motorcycle = new Motorcycle("Ninja 350", "Kawasaki");
        motorcycle.displayInfo();
        motorcycle.startEngine();
    }
}

abstract class Vehicle {
    String name;
    String brand;

    Vehicle(String name, String brand) {
        this.name = name;
        this.brand = brand;
    }

    abstract void startEngine();

    void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Brand: " + brand);
    }
}

class Car extends Vehicle {
    Car(String name, String brand) {
        super(name, brand);
    }

    void startEngine() {
        System.out.println("Car Engine is starting...");
    }
}

class Motorcycle extends Vehicle {
    Motorcycle(String name, String brand) {
        super(name, brand);
    }

    void startEngine() {
        System.out.println("Motorcycle Engine is starting...");
    }

}
