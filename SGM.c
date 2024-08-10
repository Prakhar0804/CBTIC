//STUDENT GRADE MANAGEMENT

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define MAX_SUBJECTS 5

typedef struct {
    char name[50];
    int scores[MAX_SUBJECTS];
} Student;

void calculateAverage(Student* student, int numSubjects) {
    int sum = 0;
    for (int i = 0; i < numSubjects; i++) {
        sum += student->scores[i];
    }
    float average = (float)sum / numSubjects;
    printf("Average score: %.2f\n", average);
}

void findHighestLowest(Student* student, int numSubjects) {
    int highest = student->scores[0];
    int lowest = student->scores[0];
    for (int i = 1; i < numSubjects; i++) {
        if (student->scores[i] > highest) {
            highest = student->scores[i];
        }
        if (student->scores[i] < lowest) {
            lowest = student->scores[i];
        }
    }
    printf("Highest score: %d\n", highest);
    printf("Lowest score: %d\n", lowest);
}

void displaySummary(Student* students, int numStudents, int numSubjects) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d: %s\n", i + 1, students[i].name);
        calculateAverage(&students[i], numSubjects);
        findHighestLowest(&students[i], numSubjects);
        printf("\n");
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents, numSubjects;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    printf("Enter the number of subjects: ");
    scanf("%d", &numSubjects);

    for (int i = 0; i < numStudents; i++) {
        printf("Enter student %d's name: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter %d subject scores for student %d:\n", numSubjects, i + 1);
        for (int j = 0; j < numSubjects; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].scores[j]);
        }
    }

    displaySummary(students, numStudents, numSubjects);

    return 0;
}