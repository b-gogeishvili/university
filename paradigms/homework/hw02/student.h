struct Student {
    char fullName[28];
    double gpa;
    unsigned int birthAndAttendance;
};

struct Student createStudent(char *name, int day, int month, int year, int attendance, double gpa);

void printStudentInfo(struct Student students[], int size);

void printStudent(void *student);