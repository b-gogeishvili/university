#include <stdio.h>
#include <string.h>

struct Student {
    char name[28];
    double gpa;
    unsigned int attendanceAndBirthdate;
};

struct Student student(char* name, double gpa, int attendance, int day, int month, int year) {
    struct Student student;

    strncpy(student.name, name, 28); // Assigning string to arrays of characters
    
    student.gpa = gpa;

    student.attendanceAndBirthdate = attendance << 25; // Maximum value is 100, so 7 bits is enough
    student.attendanceAndBirthdate |= day << 20; // Maximum value is 31, so 5 bits is enough
    student.attendanceAndBirthdate |= month << 16; // Maximum value is 12, so 4 bits is enough
    student.attendanceAndBirthdate |= year; // Last 16 bits are for representing year

    return student;
}

void printStudentDetails(struct Student students[]) {

    for (int i = 0; i < 5; i++) {
        printf("Student %d\n", i+1);
        printf("Name: %s, ", students[i].name);
        printf("GPA: %.2f, ", students[i].gpa);
        printf("Attendance: %d\n", students[i].attendanceAndBirthdate >> 25);

        int day = (students[i].attendanceAndBirthdate >> 20) & 0b11111;
        int month = (students[i].attendanceAndBirthdate >> 16) & 0b1111;
        int year = students[i].attendanceAndBirthdate & 0xFFFF; // Need to mask with 16 bits
        printf("Birthdate: %d/%d/%d\n\n", day, month, year);
    }
}

int main(int argc, char *argv[]) {
    struct Student students[] = {
        student("Leonardo da Vinci", 3.50, 10, 15, 4, 1452),
        student("Mark Twain", 3.25, 70, 30, 11, 1835),
        student("Fyodor Dostoevsky", 3.00, 30, 11, 11, 1821),
        student("Franz Kafka", 3.65, 60, 7, 3, 1883),
        student("Isaac Newton", 4.00, 90, 4, 1, 1643),
    };

    printStudentDetails(students);
    return 0;
}