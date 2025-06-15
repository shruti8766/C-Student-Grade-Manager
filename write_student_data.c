#include <stdio.h>

int main() {
    char filename[] = "students.csv";
    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int roll;
    char name[50];
    float physics, chemistry, math, total, percentage;
    char grade;

    printf("Enter Roll number: ");
    scanf("%d", &roll);
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Physics marks: ");
    scanf("%f", &physics);
    printf("Enter Chemistry marks: ");
    scanf("%f", &chemistry);
    printf("Enter Mathematics marks: ");
    scanf("%f", &math);

    total = physics + chemistry + math;
    percentage = (total / 300) * 100;

    if (percentage >= 90) {
        grade = 'A';
    } else if (percentage >= 80) {
        grade = 'B';
    } else if (percentage >= 70) {
        grade = 'C';
    } else if (percentage >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    fprintf(file, "%d,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%c\n", roll, name, physics, chemistry, math, total, percentage, grade);

    fclose(file);

    printf("Data saved successfully.\n");

    return 0;
}

