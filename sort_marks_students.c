//Create array of 10 students(rollno, name, marks) and sort students by their marks. 
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

typedef struct {
    int rollno;
    char name[50];
    float marks;
} Student;

void sortStudentsByMarks(Student students[], int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].marks > students[j].marks) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printStudents(Student students[], int n) {
    printf("Roll No\tName\t\tMarks\n");
    printf("-----------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }
}

int main() {
    Student students[MAX_STUDENTS] = {
        {1, "Alice", 85},
        {2, "Bob", 70},
        {3, "Charlie", 95},
        {4, "David", 60},
        {5, "Eva", 78},
        {6, "Frank", 88},
        {7, "Grace", 92},
        {8, "Hannah", 75},
        {9, "Ivy", 82},
        {10, "Jack", 90}
    };

    int n = MAX_STUDENTS;

    sortStudentsByMarks(students, n);

    printStudents(students, n);

    return 0;
}
