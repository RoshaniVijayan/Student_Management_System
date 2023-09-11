#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int id;
    char name[100];
    char dob[12];
    int room_no;
    char address[200];
    char phone[15];
    char email[100];
    char blood_group[5];
    char emergency_contact[15];
    char emergency_person[100];
    char allergy[100];
    char notes[200];
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

// Function to find a student's index by ID
int findStudentIndex(int studentId) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == studentId) {
            return i;
        }
    }
    return -1; // Student not found
}

void addStudent() {
    if (studentCount < MAX_STUDENTS) {
        struct Student newStudent;
        newStudent.id = studentCount + 1;

        printf("Enter Student's Name: ");
        scanf("%s", newStudent.name);

        printf("Enter Date of Birth (DD-MM-YYYY): ");
        scanf("%s", newStudent.dob);

        printf("Enter Allotted Room No.: ");
        scanf("%d", &newStudent.room_no);

        // Similarly, input other student details

        students[studentCount] = newStudent;
        studentCount++;
        printf("Student added successfully!\n");
    } else {
        printf("Maximum student limit reached.\n");
    }
}

void displayStudent(int studentId) {
    int index = findStudentIndex(studentId);
    if (index != -1) {
        struct Student student = students[index];
        printf("Student ID: %d\n", student.id);
        printf("Name: %s\n", student.name);
        printf("Date of Birth: %s\n", student.dob);
        printf("Room No.: %d\n", student.room_no);
        // Display other student details
    } else {
        printf("Student not found.\n");
    }
}

void modifyStudent(int studentId) {
    int index = findStudentIndex(studentId);
    if (index != -1) {
        struct Student *student = &students[index];
        // Allow the user to modify student details
        // Example: scanf("%s", student->name);
        printf("Student modified successfully!\n");
    } else {
        printf("Student not found.\n");
    }
}

void deleteStudent(int studentId) {
    int index = findStudentIndex(studentId);
    if (index != -1) {
        // Shift elements to remove the student
        for (int i = index; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        printf("Student deleted successfully!\n");
    } else {
        printf("Student not found.\n");
    }
}

void displayStudents() {
    printf("Student List:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Room: %d\n", students[i].id, students[i].name, students[i].room_no);
    }
}

int main() {
    int choice;
    do {
        printf("\nStudent Management System Menu:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Modify Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Enter Student ID to search: ");
                int searchId;
                scanf("%d", &searchId);
                displayStudent(searchId);
                break;
            case 4:
                printf("Enter Student ID to modify: ");
                int modifyId;
                scanf("%d", &modifyId);
                modifyStudent(modifyId);
                break;
            case 5:
                printf("Enter Student ID to delete: ");
                int deleteId;
                scanf("%d", &deleteId);
                deleteStudent(deleteId);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
