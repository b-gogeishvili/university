package Quiz1;

public class Main {
    public static void main(String[] args) {
        // Circle
        Circle circle = new Circle(2);

        System.out.println("Circle area: " + circle.calculateArea());
        System.out.println("Circle perimeter: " + circle.calculatePerimeter());

        System.out.println("---------------------------------------------------");

        // Rectangle
        Rectangle rectangle = new Rectangle(2,3);

        System.out.println("Rectangle area: " + rectangle.calculateArea());
        System.out.println("Rectangle perimeter: " + rectangle.calculatePerimeter());
    }
}

interface Shape {
    double calculateArea();
    double calculatePerimeter();
}

class Circle implements Shape {
    double radius;

    Circle (double radius) {
        this.radius = radius;
    }

    public double calculateArea() {
        return Math.PI * (Math.pow(radius, 2));
    }

    public double calculatePerimeter() {
        return 2 * Math.PI * radius;
    }
}

class Rectangle implements Shape {
    double width;
    double height;

    Rectangle (double width, double height) {
        this.width = width;
        this.height = height;
    }

    public double calculateArea() {
        return width * height;
    }

    public double calculatePerimeter() {
        return 2 * (height + width);
    }
}
