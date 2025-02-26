public class Quiz3 {

    public static void main(String[] args) {
        Student student = new Student("john", "doe", "373213321");

        student.setGPA(2.3);
        student.setOopStatus();
        student.getInfo();
    }

}

class Student {

    String name;
    String surname;
    String id;
    boolean hasFinishedOop = false;
    double GPA;
    static final double MAX_GPA = 4.0;

    Student(String name, String surname, String id) {
        this.name = name;
        this.surname = surname;
        this.id = id;
    }

    boolean getOopStatus() {
        return hasFinishedOop;
    }
    void setOopStatus() {
        hasFinishedOop = true;
    }

    double getGpa() {
        return GPA;
    }

    void setGPA(double GPA) {
        this.GPA = GPA;
    }

    void getInfo() {
        System.out.print("Name: ");
        System.out.println(name);

        System.out.print("Surname: ");
        System.out.println(surname);

        System.out.print("ID: ");
        System.out.println(id);

        System.out.print("Has Finished OOP: ");
        System.out.println(hasFinishedOop);

        System.out.print("GPA: ");
        System.out.println(GPA + " / " + MAX_GPA);
    }
}
