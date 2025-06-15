#include <stdio.h>

int main() {
    char filename[] = "students.csv";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int roll;
    char name[50];
    float physics, chemistry, math, total, percentage;
    char grade;

    printf("-----------------------------------------------------------------------------------------------\n");
    printf("| Roll No |   Name    | Physics | Chemistry | Mathematics | Total | Percentage | Grade |\n");
    printf("-----------------------------------------------------------------------------------------------\n");

    while (fscanf(file, "%d,%[^,],%f,%f,%f,%f,%f,%c\n", &roll, name, &physics, &chemistry, &math, &total, &percentage, &grade) != EOF) {
        printf("|  %-5d  |  %-8s |  %-6.2f |  %-8.2f |  %-10.2f |  %-4.2f |  %-9.2f |  %-5c |\n", roll, name, physics, chemistry, math, total, percentage, grade);
    }

    printf("-----------------------------------------------------------------------------------------------\n");

    fclose(file);

    return 0;
}
