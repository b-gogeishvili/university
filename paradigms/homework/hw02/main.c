#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "linked_list.h"
#include "student.h"

typedef struct ListItem* LinkedList;
typedef struct Student Student;

Student* FindStudentByName(LinkedList list, void *match) {
    char* target = (char *)match;

    while (list != NULL) {
        Student* s = (Student *)list->data;
        if (!strcmp(s->fullName, target)) {
            return s;
        }
        // printf("%s vs %s\n", s->fullName, target);
        list = list->next;
    }

    return false;
}

Student* FindStudentByGPA(LinkedList list, void *match) {
    double target = *(double *)match;

    while (list != NULL) {
        Student *s = (Student *)list->data;
        if (s->gpa == target) {
            return s;
        }
        // printf("%.2f vs %.2f\n", s->gpa, target);
        list = list->next;
    }

    return false;
}

int main() {
    Student students[5] = {
        createStudent("Tinatin Lomidze", 20, 3, 2004, 100, 4.0),
        createStudent("Saxeli Gvari", 18, 5, 2000, 55, 3.0),
        createStudent("John Doe", 27, 7, 1994, 98, 3.9),
        createStudent("Some Person", 30, 11, 2006, 70, 3.8),
    };

    size_t i_size = sizeof(Student);
    LinkedList list = NULL;

    list = Insert(list, students, i_size);
    list = Insert(list, students + 1, i_size);
    list = Insert(list, students + 2, i_size);
    list = Insert(list, students + 3, i_size);

    // printStudentInfo(students, 5);
    // printStudent(&students[0]);
    
    // PrintLinkedList(list, printStudent);

    // bool res = Find(list, "Saxeli Lomidze", FindStudentByName);
    double maxGpa = 4.0;
    char* topStudent = "Tinatin Lomidze";

    Student* res = Find(list, "Saxeli Gvari", FindStudentByName);

    if (res != NULL) {
        printf("Found! Printing student information...\n");
        printStudent(res);
    } else {
        printf("Not Found!\n");
    }
}