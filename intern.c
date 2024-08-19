#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 10

struct Student {
    char name[50];
    int scores[MAX_SUBJECTS];
    float average;
};

void input_student_data(struct Student *students, int num_students, int num_subjects) {
    for (int i = 0; i < num_students; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        for (int j = 0; j < num_subjects; j++) {
            printf("Enter score for subject %d: ", j + 1);
            scanf("%d", &students[i].scores[j]);
        }
    }
}

void calculate_averages(struct Student *students, int num_students, int num_subjects) {
    for (int i = 0; i < num_students; i++) {
        int total = 0;
        for (int j = 0; j < num_subjects; j++) {
            total += students[i].scores[j];
        }
        students[i].average = (float)total / num_subjects;
    }
}

void find_highest_lowest(struct Student *students, int num_students, int num_subjects,
                       int *highest_score, int *lowest_score, char *highest_name, char *lowest_name) {
    *highest_score = *lowest_score = students[0].scores[0];
    strcpy(highest_name, students[0].name);
    strcpy(lowest_name, students[0].name);

    for (int i = 0; i < num_students; i++) {
        for (int j = 0; j < num_subjects; j++) {
            if (students[i].scores[j] > *highest_score) {
                *highest_score = students[i].scores[j];
                strcpy(highest_name, students[i].name);
            }
            if (students[i].scores[j] < *lowest_score) {
                *lowest_score = students[i].scores[j];
                strcpy(lowest_name, students[i].name);
            }
        }
    }
}

void display_results(struct Student *students, int num_students, int num_subjects,
                   int highest_score, int lowest_score, char *highest_name, char *lowest_name) {
    printf("\nStudent Performance Summary:\n");
    printf("----------------------------\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student Name: %s\n", students[i].name);
        for (int j = 0; j < num_subjects; j++) {
            printf("Subject %d: %d\n", j + 1, students[i].scores[j]);
        }
        printf("Average Score: %.2f\n", students[i].average);
        printf("----------------------------\n");
    }

    printf("\nHighest Score: %d (by %s)\n", highest_score, highest_name);
    printf("Lowest Score: %d (by %s)\n", lowest_score, lowest_name);
}

int main() {
    int num_students, num_subjects;
    struct Student students[MAX_STUDENTS];
    int highest_score, lowest_score;
    char highest_name[50], lowest_name[50];

    printf("Enter number of students: ");
    scanf("%d", &num_students);
    printf("Enter number of subjects: ");
    scanf("%d", &num_subjects);

    input_student_data(students, num_students, num_subjects);
    calculate_averages(students, num_students, num_subjects);
    find_highest_lowest(students, num_students, num_subjects, &highest_score, &lowest_score, highest_name, lowest_name);
    display_results(students, num_students, num_subjects, highest_score, lowest_score, highest_name, lowest_name);

    return 0;
}  
