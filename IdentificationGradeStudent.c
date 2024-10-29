#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 60
#define MAX_GRADE 100

const char* getLetterGrade(int score) {
    if (score >= 90 && score <= 100) return "A";
    else if (score >= 85 && score <= 89) return "A-";
    else if (score >= 80 && score <= 84) return "B+";
    else if (score >= 75 && score <= 79) return "B";
    else if (score >= 70 && score <= 74) return "B-";
    else if (score >= 65 && score <= 69) return "C";
    else if (score >= 50 && score <= 64) return "D";
    else return "F";
}

void groupGrades(int grades[], const char* letterGrades[], int n) {
    int groups[MAX_GRADE + 1] = {0}; // Array to count occurrences of each grade
    int unique[MAX_STUDENTS]; // Array to store unique grades
    int uniqueCount = 0;

    // Count occurrences of each grade
    for (int i = 0; i < n; i++) {
        groups[grades[i]]++;
    }

    // Print groups with identical grades
    printf("Groups with identical grades:\n");
    for (int i = 0; i <= MAX_GRADE; i++) {
        if (groups[i] > 1) {
            printf("Grade %d: %d students\n", i, groups[i]);
        } else if (groups[i] == 1) {
            unique[uniqueCount++] = i; // Collect unique grades
        }
    }

    // Handle unique grades
    printf("\nStudents with unique grades:\n");
    for (int i = 0; i < uniqueCount; i++) {
        printf("Grade %d\n", unique[i]);
    }

    // Convert numeric grades to letter grades
    for (int i = 0; i < n; i++) {
        letterGrades[i] = getLetterGrade(grades[i]);
    }
}

int main() {
    int grades[MAX_STUDENTS];
    const char* letterGrades[MAX_STUDENTS];

    // Input grades
    printf("Enter the grades of 60 students:\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        scanf("%d", &grades[i]);
    }

    // Group and handle grades, and convert to letter grades
    groupGrades(grades, letterGrades, MAX_STUDENTS);

    // Print letter grades
    printf("\nLetter grades:\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Student %d: %s\n", i + 1, letterGrades[i]);
    }

    return 0;
}
