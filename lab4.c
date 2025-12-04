#include <stdio.h>
#include <math.h>

#define MAX_STUDENTS 50

char getGrade(double avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

int main() {
    int n;
    int id[MAX_STUDENTS];
    int scores[MAX_STUDENTS][3];
    double average[MAX_STUDENTS];
    char grade[MAX_STUDENTS];

    printf("=== Student Grade Management System ===\n\n");

    do {
        printf("Enter number of students (1-50): ");
        scanf("%d", &n);
    } while (n < 1 || n > 50);

    printf("\n--- Enter Student Data ---\n\n");

    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &id[i]);
        
        for (int j = 0; j < 3; j++) {
            printf("Exam %d score: ", j + 1);
            scanf("%d", &scores[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        average[i] = (scores[i][0] + scores[i][1] + scores[i][2]) / 3.0;
        grade[i] = getGrade(average[i]);
    }

    printf("\n=== Individual Student Reports ===\n\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Scores: %d %d %d | Average: %.2f | Grade: %c\n",
            id[i], scores[i][0], scores[i][1], scores[i][2], average[i], grade[i]);
    }

    double classAvg = 0;
    int highest = scores[0][0];
    int lowest = scores[0][0];
    int highID = id[0], lowID = id[0];

    int countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;

    for (int i = 0; i < n; i++) {
        classAvg += average[i];

        for (int j = 0; j < 3; j++) {
            if (scores[i][j] > highest) {
                highest = scores[i][j];
                highID = id[i];
            }
            if (scores[i][j] < lowest) {
                lowest = scores[i][j];
                lowID = id[i];
            }
        }

        switch (grade[i]) {
            case 'A': countA++; break;
            case 'B': countB++; break;
            case 'C': countC++; break;
            case 'D': countD++; break;
            case 'F': countF++; break;
        }
    }

    classAvg /= n;

    printf("\n=== Class Statistics ===\n");
    printf("Class Average: %.2f\n", classAvg);
    printf("Highest Score: %d (Student ID: %d)\n", highest, highID);
    printf("Lowest Score: %d (Student ID: %d)\n", lowest, lowID);

    printf("\nGrade Distribution:\n");
    printf("A: %d student(s)\n", countA);
    printf("B: %d student(s)\n", countB);
    printf("C: %d student(s)\n", countC);
    printf("D: %d student(s)\n", countD);
    printf("F: %d student(s)\n", countF);

    printf("\n=== Sorted by Average (Descending) ===\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (average[j] > average[i]) {
    
                double tempA = average[i];
                average[i] = average[j];
                average[j] = tempA;

                int tempID = id[i];
                id[i] = id[j];
                id[j] = tempID;

                char tempG = grade[i];
                grade[i] = grade[j];
                grade[j] = tempG;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d. ID: %d | Average: %.2f | Grade: %c\n",
            i + 1, id[i], average[i], grade[i]);
    }

    printf("\n--- Search Student ---\n");
    int searchID;
    printf("Enter student ID to search: ");
    scanf("%d", &searchID);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (id[i] == searchID) {found = 1;
            printf("Found: ID %d | Average: %.2f | Grade: %c\n",
                id[i], average[i], grade[i]);
            break;
        }
    }

    if (!found)
        printf("Student ID not found.\n");

    return 0;
}
