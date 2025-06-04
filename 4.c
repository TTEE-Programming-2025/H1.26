#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10
#define SUBJECTS 6

struct Student {
    char name[50];
    int id;
    int grades[SUBJECTS];
    float avg;
};

struct Student students[MAX];
int student_count = 0;

void showMenu() {
    printf("\n----------[Grade System]----------\n");
    printf("a. Enter student grades\n");
    printf("b. Display student grades\n");
    printf("c. Search for student grades\n");
    printf("d. Grade ranking\n");
    printf("e. Exit system\n");
    printf("----------------------------------\n");
    printf("Enter your choice: ");
}

float calculateAverage(int grades[]) {
    int sum = 0;
    int i;
    for (i = 0; i < SUBJECTS; i++) {
        sum += grades[i];
    }
    return sum / (float)SUBJECTS;
}

bool login() {
    char password[10];
    int tries = 0;
    while (tries < 3) {
        printf("�п�J4��ƱK�X�G");
        scanf("%s", password);
        if (strcmp(password, "2025") == 0) {
            printf("�w��ϥΦ��Z�t�ΡI\n");
            return true;
        } else {
            printf("�K�X���~�I\n");
            tries++;
        }
    }
    printf("�K�X���~�W�L3���A�t�ε����C\n");
    return false;
}

void enterGrades() {
    int i, j;
    printf("�п�J�ǥͤH�� (5~10)�G");
    scanf("%d", &student_count);

    if (student_count < 5 || student_count > 10) {
        printf("�H�ƿ��~�I\n");
        student_count = 0;
        return;
    }

    for (i = 0; i < student_count; i++) {
        printf("\n�ǥ� %d �m�W: ", i + 1);
        scanf("%s", students[i].name);
        students[i].id = i + 1;
        printf("�п�J6�즨�Z�G");

        for (j = 0; j < SUBJECTS; j++) {
            scanf("%d", &students[i].grades[j]);
            if (students[i].grades[j] < 0 || students[i].grades[j] > 100) {
                printf("���Z���~�A�Э��s��J\n");
                i--;
                break;
            }
        }
        if (j == SUBJECTS) {
            students[i].avg = calculateAverage(students[i].grades);
        }
    }
    printf("�ǥ͸�ƿ�J�����I\n");
}

void displayGrades() {
    int i;
    printf("\n%-10s%-5s%-10s\n", "�m�W", "ID", "�������Z");
    for (i = 0; i < student_count; i++) {
        printf("%-10s%-5d%.1f\n", students[i].name, students[i].id, students[i].avg);
    }
    printf("�Ы� Enter �~��...");
    getchar();
    getchar();
}

void searchStudent() {
    char search_name[50];
    int i;
    printf("�п�J�n�d�ߪ��ǥͩm�W�G");
    scanf("%s", search_name);

    for (i = 0; i < student_count; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("\n�m�W: %s\n�Ǹ�: %d\n�������Z: %.1f\n", students[i].name, students[i].id, students[i].avg);
            printf("�Ы� Enter �~��...");
            getchar(); getchar();
            return;
        }
    }
    printf("�d�L���ǥ͸�ơI\n");
    printf("�Ы� Enter �~��...");
    getchar(); getchar();
}

void gradeRanking() {
    int i, j;
    struct Student temp;

    for (i = 0; i < student_count - 1; i++) {
        for (j = i + 1; j < student_count; j++) {
            if (students[i].avg < students[j].avg) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("\n%-10s%-5s%-10s\n", "�m�W", "ID", "�������Z");
    for (i = 0; i < student_count; i++) {
        printf("%-10s%-5d%.1f\n", students[i].name, students[i].id, students[i].avg);
    }
    printf("�Ы� Enter �~��...");
    getchar(); getchar();
}

bool exitSystem() {
    char confirm;
    printf("�T�w���}�H(y/n): ");
    getchar();
    scanf("%c", &confirm);
    return (confirm == 'y' || confirm == 'Y');
}

int main() {
    if (!login()) return 0;

    char choice;
    while (1) {
        showMenu();
        scanf(" %c", &choice);
        switch (choice) {
            case 'a': enterGrades(); break;
            case 'b': displayGrades(); break;
            case 'c': searchStudent(); break;
            case 'd': gradeRanking(); break;
            case 'e': if (exitSystem()) return 0; break;
            default: printf("�L�Ŀﶵ�I�Э��s��ܡC\n"); break;
        }
    }

    return 0;
}
//�z�L�o��²�����Z�t�Ϊ���@�A�ڧ�[���x
