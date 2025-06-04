// ²�����Z�t�ι�@
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10
#define SUBJECTS 6

// �ǥ͸�Ƶ��c
struct Student {
    char name[50];
    int id;
    int grades[SUBJECTS];
    float avg;
};

struct Student students[MAX];
int student_count = 0;

// ��ܥD���
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

// �p�⥭��
float calculateAverage(int grades[]) {
    int sum = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        sum += grades[i];
    }
    return sum / (float)SUBJECTS;
}

// 1. �n�J�e�������ұK�X
bool login() {
    char password[5];
    int tries = 0;
    while (tries < 3) {
        printf("�п�J4��ƱK�X�G");
        scanf("%s", password);
        if (strcmp(password, "2025") == 0) {
            printf("�w��ϥΦ��Z�t�ΡI\n");
            return true;
        }
        else {
            printf("�K�X���~�I\n");
            tries++;
        }
    }
    printf("�K�X���~�W�L3���A�t�ε����C\n");
    return false;
}

// a. ��J�ǥ͸��
void enterGrades() {
    printf("�п�J�ǥͤH�� (5~10)�G");
    scanf("%d", &student_count);

    if (student_count < 5 || student_count > 10) {
        printf("�H�ƿ��~�I\n");
        student_count = 0;
        return;
    }

    for (int i = 0; i < student_count; i++) {
        printf("\n�ǥ� %d �m�W: ", i + 1);
        scanf("%s", students[i].name);
        students[i].id = i + 1;
        printf("�п�J6�즨�Z�G");
        for (int j = 0; j < SUBJECTS; j++) {
            scanf("%d", &students[i].grades[j]);
            if (students[i].grades[j] < 0 || students[i].grades[j] > 100) {
                printf("���Z���~�A�Э��s��J\n");
                i--;
                break;
            }
        }
        students[i].avg = calculateAverage(students[i].grades);
    }
    printf("�ǥ͸�ƿ�J�����I\n");
}

// b. ��ܩҦ��ǥ͸��
void displayGrades() {
    printf("\n%-10s%-5s%-10s\n", "�m�W", "ID", "�������Z");
    for (int i = 0; i < student_count; i++) {
        printf("%-10s%-5d%.1f\n", students[i].name, students[i].id, students[i].avg);
    }
    getchar(); getchar(); // ���ݿ�J�H�~��
}

// c. �d�߯S�w�ǥͦ��Z
void searchStudent() {
    char search_name[50];
    printf("�п�J�n�d�ߪ��ǥͩm�W�G");
    scanf("%s", search_name);
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("\n�m�W: %s\n�Ǹ�: %d\n�������Z: %.1f\n", students[i].name, students[i].id, students[i].avg);
            return;
        }
    }
    printf("�d�L���ǥ͸�ơI\n");
    getchar(); getchar();
}

// d. ���Z�ƦW
void gradeRanking() {
    struct Student temp;
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (students[i].avg < students[j].avg) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("\n%-10s%-5s%-10s\n", "�m�W", "ID", "�������Z");
    for (int i = 0; i < student_count; i++) {
        printf("%-10s%-5d%.1f\n", students[i].name, students[i].id, students[i].avg);
    }
    getchar(); getchar();
}

// e. ���}�t��
bool exitSystem() {
    char confirm;
    printf("�T�w���}�H(y/n): ");
    getchar(); // �M���W�@�ӿ�J�������
    scanf("%c", &confirm);
    return (confirm == 'y' || confirm == 'Y');
}

// �D�{��
int main() {
    if (!login()) return 0;

    char choice;
    do {
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
    } while (1);

    return 0;
}
//�z�L�o��²�����Z�t�Ϊ���@�A�ڧ�[���x C �}�C(array)�B�r��ާ@�B����P�_(�B�j�鵥��¦�y�k��������ΡC��ƿ�J���һP���Z�Ƨ��޿�A�o���ھǷ|�F�p��z�L���c�}�C�x�s�P�ާ@�h����ơC���~�A�z�L���覡�]�p���ʤ����A�]���ڹ�{���y�{�]�p����`�誺�z�ѡC
