// 簡易成績系統實作
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10
#define SUBJECTS 6

// 學生資料結構
struct Student {
    char name[50];
    int id;
    int grades[SUBJECTS];
    float avg;
};

struct Student students[MAX];
int student_count = 0;

// 顯示主選單
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

// 計算平均
float calculateAverage(int grades[]) {
    int sum = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        sum += grades[i];
    }
    return sum / (float)SUBJECTS;
}

// 1. 登入畫面並驗證密碼
bool login() {
    char password[5];
    int tries = 0;
    while (tries < 3) {
        printf("請輸入4位數密碼：");
        scanf("%s", password);
        if (strcmp(password, "2025") == 0) {
            printf("歡迎使用成績系統！\n");
            return true;
        }
        else {
            printf("密碼錯誤！\n");
            tries++;
        }
    }
    printf("密碼錯誤超過3次，系統結束。\n");
    return false;
}

// a. 輸入學生資料
void enterGrades() {
    printf("請輸入學生人數 (5~10)：");
    scanf("%d", &student_count);

    if (student_count < 5 || student_count > 10) {
        printf("人數錯誤！\n");
        student_count = 0;
        return;
    }

    for (int i = 0; i < student_count; i++) {
        printf("\n學生 %d 姓名: ", i + 1);
        scanf("%s", students[i].name);
        students[i].id = i + 1;
        printf("請輸入6科成績：");
        for (int j = 0; j < SUBJECTS; j++) {
            scanf("%d", &students[i].grades[j]);
            if (students[i].grades[j] < 0 || students[i].grades[j] > 100) {
                printf("成績錯誤，請重新輸入\n");
                i--;
                break;
            }
        }
        students[i].avg = calculateAverage(students[i].grades);
    }
    printf("學生資料輸入完成！\n");
}

// b. 顯示所有學生資料
void displayGrades() {
    printf("\n%-10s%-5s%-10s\n", "姓名", "ID", "平均成績");
    for (int i = 0; i < student_count; i++) {
        printf("%-10s%-5d%.1f\n", students[i].name, students[i].id, students[i].avg);
    }
    getchar(); getchar(); // 等待輸入以繼續
}

// c. 查詢特定學生成績
void searchStudent() {
    char search_name[50];
    printf("請輸入要查詢的學生姓名：");
    scanf("%s", search_name);
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("\n姓名: %s\n學號: %d\n平均成績: %.1f\n", students[i].name, students[i].id, students[i].avg);
            return;
        }
    }
    printf("查無此學生資料！\n");
    getchar(); getchar();
}

// d. 成績排名
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
    printf("\n%-10s%-5s%-10s\n", "姓名", "ID", "平均成績");
    for (int i = 0; i < student_count; i++) {
        printf("%-10s%-5d%.1f\n", students[i].name, students[i].id, students[i].avg);
    }
    getchar(); getchar();
}

// e. 離開系統
bool exitSystem() {
    char confirm;
    printf("確定離開？(y/n): ");
    getchar(); // 清除上一個輸入的換行符
    scanf("%c", &confirm);
    return (confirm == 'y' || confirm == 'Y');
}

// 主程式
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
            default: printf("無效選項！請重新選擇。\n"); break;
        }
    } while (1);

    return 0;
}
//透過這次簡易成績系統的實作，我更加熟悉 C 陣列(array)、字串操作、條件判斷(、迴圈等基礎語法的實務應用。資料輸入驗證與成績排序邏輯，這讓我學會了如何透過結構陣列儲存與操作多筆資料。此外，透過選單方式設計互動介面，也讓我對程式流程設計有更深刻的理解。
