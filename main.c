#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void addStudent() {
    struct Student s;
    FILE *file = fopen(FILE_NAME, "ab");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s.rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(struct Student), 1, file);
    fclose(file);

    printf("\nStudent added successfully!\n");
}

void displayStudents() {
    struct Student s;
    FILE *file = fopen(FILE_NAME, "rb");

    if (file == NULL) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n========== STUDENT RECORDS ==========\n");

    while (fread(&s, sizeof(struct Student), 1, file)) {
        printf("\nRoll Number : %d", s.rollNo);
        printf("\nName        : %s", s.name);
        printf("\nMarks       : %.2f\n", s.marks);
    }

    fclose(file);
}

void searchStudent() {
    struct Student s;
    int rollNo;
    int found = 0;

    FILE *file = fopen(FILE_NAME, "rb");

    if (file == NULL) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &rollNo);

    while (fread(&s, sizeof(struct Student), 1, file)) {
        if (s.rollNo == rollNo) {
            printf("\nStudent Found!");
            printf("\nRoll Number : %d", s.rollNo);
            printf("\nName        : %s", s.name);
            printf("\nMarks       : %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found.\n");
    }

    fclose(file);
}

int main() {
    int choice;

    while (1) {
        printf("\n\n===== STUDENT MANAGEMENT SYSTEM =====");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                printf("\nProgram terminated.\n");
                exit(0);

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
