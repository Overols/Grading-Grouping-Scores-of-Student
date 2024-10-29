#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void saveScoresToFile(int scores[], const char *filename, int totalStudents);
int* retrieveScoresFromFile(const char *filename, int *totalStudents);
void displayGradeDistribution(int scores[], int totalStudents);

int main() {
    // Declare variables
    int scores[60]; // Array to store scores of 60 students
    int gradeCounts[9] = {0}; // Array to store counts of grades (A, A-, B+, B, B-, C, D, E, F)
    int i; // Loop counter
    int totalStudents = 60; // Number of students

    // Input scores for 60 students
    printf("Enter scores for 60 students (0 - 100):\n");
    for (i = 0; i < totalStudents; i++) {
        scanf("%d", &scores[i]);
    }

    // Calculate grade counts
    for (i = 0; i < totalStudents; i++) {
        if (scores[i] >= 90) {
            gradeCounts[0]++; // Increment count for 'A' grade
        } else if (scores[i] >= 85) {
            gradeCounts[1]++; // Increment count for 'A-' grade
        } else if (scores[i] >= 80) {
            gradeCounts[2]++; // Increment count for 'B+' grade
        } else if (scores[i] >= 75) {
            gradeCounts[3]++; // Increment count for 'B' grade
        } else if (scores[i] >= 70) {
            gradeCounts[4]++; // Increment count for 'B-' grade
        } else if (scores[i] >= 65) {
            gradeCounts[5]++; // Increment count for 'C' grade
        } else if (scores[i] >= 50) {
            gradeCounts[6]++; // Increment count for 'D' grade
        } else if (scores[i] >= 0) { // Changed to >= 0 to avoid negative scores
            gradeCounts[7]++; // Increment count for 'E' grade
        } else { // This covers scores below 0
            gradeCounts[8]++; // Increment count for 'F' grade
        }
    }

    // Save scores to file
    saveScoresToFile(scores, "scores.txt", totalStudents);

    // Retrieve scores from file
    int retrievedTotalStudents;
    int *retrievedScores = retrieveScoresFromFile("scores.txt", &retrievedTotalStudents);

    // Display grade distribution
    displayGradeDistribution(retrievedScores, retrievedTotalStudents);

    // Free the allocated memory if necessary
    free(retrievedScores);

    return 0;
}

void saveScoresToFile(int scores[], const char *filename, int totalStudents) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < totalStudents; i++) {
        fprintf(file, "%d\n", scores[i]);
    }
    fclose(file);
}

int* retrieveScoresFromFile(const char *filename, int *totalStudents) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return NULL;
    }

    int *scores = malloc(60 * sizeof(int));
    *totalStudents = 0;

    while (fscanf(file, "%d", &scores[*totalStudents]) != EOF && *totalStudents < 60) {
        (*totalStudents)++;
    }

    fclose(file);
    return scores;
}

void displayGradeDistribution(int scores[], int totalStudents) {
    int gradeCounts[9] = {0}; // Reset grade counts for display

    // Calculate grade counts for display
    for (int i = 0; i < totalStudents; i++) {
        if (scores[i] >= 90) {
            gradeCounts[0]++;
        } else if (scores[i] >= 85) {
            gradeCounts[1]++;
        } else if (scores[i] >= 80) {
            gradeCounts[2]++;
        } else if (scores[i] >= 75) {
            gradeCounts[3]++;
        } else if (scores[i] >= 70) {
            gradeCounts[4]++;
        } else if (scores[i] >= 65) {
            gradeCounts[5]++;
        } else if (scores[i] >= 50) {
            gradeCounts[6]++;
        } else if (scores[i] >= 0) { // Changed to >= 0 to avoid negative scores
            gradeCounts[7]++;
        } else { // This covers scores below 0
            gradeCounts[8]++;
        }
    }

    // Display the grade distribution
    printf("Grade Distribution:\n");
    printf("A: %d\n", gradeCounts[0]);
    printf("A-: %d\n", gradeCounts[1]);
    printf("B+: %d\n", gradeCounts[2]);
    printf("B: %d\n", gradeCounts[3]);
    printf("B-: %d\n", gradeCounts[4]);
    printf("C: %d\n", gradeCounts[5]);
    printf("D: %d\n", gradeCounts[6]);
    printf("E: %d\n", gradeCounts[7]);
    printf("F: %d\n", gradeCounts[8]);
}
   