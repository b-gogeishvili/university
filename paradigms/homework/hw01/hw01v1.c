#include <stdio.h>
#include <string.h>

struct Student {
    char fullName[28];
    double gpa;
    unsigned int birthAndAttendance;
};

struct Student createStudent(char *name, int day, int month, int year, int attendance, double gpa) {
    struct Student s;

    s.gpa = gpa;
    strcpy(s.fullName, name);

    // Encoding
    s.birthAndAttendance = day << 27;
    s.birthAndAttendance |= month << 23;
    s.birthAndAttendance |= year << 7;
    s.birthAndAttendance |= attendance;

    return s;
}

void printStudentInfo(struct Student students[], int size) {
    for (int i = 0; i < size; i++) {
        struct Student s = students[i];

        // Decoding
        int day = s.birthAndAttendance >> 27;
        int month = (s.birthAndAttendance >> 23) & 0xF;
        int year = (s.birthAndAttendance >> 7) & 0xFFFF;
        int attendace = s.birthAndAttendance & 0x7F;

        printf("Student: %d\n", i+1);
        printf("Name: %s\n", s.fullName);
        printf("GPA: %.2f\n", s.gpa);
        printf("Birthdate: %d / %d / %d\n", day, month, year);
        printf("Attendance: %d\n\n", attendace);
    }
}

int main() {
    struct Student students[5] = {
        createStudent("Tinatin Lomidze", 20, 3, 2004, 100, 3.5),
        createStudent("Saxeli Gvari", 18, 5, 2000, 55, 4.0),
        createStudent("John Doe", 27, 7, 1994, 98, 4.6),
        createStudent("Some Person", 30, 11, 2006, 70, 4.2),
        createStudent("Name Surname", 9, 1, 2002, 90, 3.0)
    };

    printStudentInfo(students, 5);
}