#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 2025
#define MAX_TRY   3

void clear_screen();
void wait_for_key();
void print_letter_triangle(char ch);
void print_multiplication_table(int n);

int main() {
    int password, attempt = 0;
    char choice;
    int running = 1;

    // 1. 登入驗證
    while (attempt < MAX_TRY) {
        printf("請輸入4位數密碼: ");
        scanf("%d", &password);

        if (password == PASSWORD) {
            printf("密碼正確，歡迎使用!\n");
            break;
        } else {
            attempt++;
            if (attempt == MAX_TRY) {
                printf("錯誤三次，強制結束。\n");
                return 1;
            } else {
                printf("密碼錯誤，請重新輸入。\n");
            }
        }
    }

    while (running) {
        clear_screen();
        printf("======== 主選單 ========\n");
        printf("a. 直角三角形\n");
        printf("b. 顯示乘法表\n");
        printf("c. 結束\n");
        printf("========================\n");
        printf("請選擇 (a/b/c): ");

        while ((choice = getchar()) == '\n'); // 讀到不是換行才停止
        printf("%c\n", choice);

        switch (choice) {
            case 'a':
            case 'A': {
                char triangleChar;
                printf("請輸入一個字元 (a~n): ");
                // 吃掉前面可能殘留的換行
                while ((triangleChar = getchar()) == '\n');
                if (triangleChar >= 'a' && triangleChar <= 'n') {
                    print_letter_triangle(triangleChar);
                } else {
                    printf("輸入錯誤，必須是 a~n 之間的字元。\n");
                    wait_for_key();
                }
                break;
            }
            case 'b':
            case 'B': {
                int n;
                printf("請輸入乘法表大小 (1~9): ");
                if (scanf("%d", &n) == 1) {
                    if (n >= 1 && n <= 9) {
                        print_multiplication_table(n);
                    } else {
                        printf("輸入錯誤，必須是 1~9 之間的整數。\n");
                        wait_for_key();
                    }
                } else {
                    printf("輸入錯誤，請輸入數字。\n");
                    wait_for_key();
                    // 清空錯誤輸入
                    while (getchar() != '\n');
                }
                break;
            }
            case 'c':
            case 'C': {
                char cont;
                printf("確定要結束程式嗎？ (y/n): ");
                while ((cont = getchar()) == '\n');
                printf("%c\n", cont);

                if (cont == 'y' || cont == 'Y') {
                    printf("程式結束\n");
                    running = 0;
                } else if (cont == 'n' || cont == 'N') {
                    // 返回主選單
                } else {
                    printf("輸入錯誤，返回主選單。\n");
                    wait_for_key();
                }
                break;
            }
            default:
                printf("選項錯誤，請重新選擇。\n");
                wait_for_key();
        }
    }

    return 0;
}

void print_letter_triangle(char ch) {
    int i, j;
    clear_screen();
    printf("直角三角形 (%c)\n\n", ch);

    for (i = ch; i >= 'a'; i--) {
        for (j = i; j <= ch; j++) {
            printf("%c", j);
        }
        printf("\n");
    }

    printf("\n按 Enter 鍵返回主選單...\n");
    wait_for_key();
}

void print_multiplication_table(int n) {
    int i, j;
    clear_screen();
    printf("%d x %d 乘法表\n\n", n, n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    printf("\n按 Enter 鍵返回主選單...\n");
    wait_for_key();
}

void clear_screen() {
    int i;
    for (i = 0; i < 40; i++) {
        printf("\n");
    }
}

void wait_for_key() {
    int ch;
    // 清空緩衝區直到換行
    while ((ch = getchar()) != '\n' && ch != EOF);
    // 等待使用者按 Enter
    getchar();
}
/*說明與心得：

1.程式架構：
a.將每個功能分離成函式 ，降低 main() 的複雜度。
b.使用 clear screen (cls) 及 getch()，模擬簡易的互動式介面。

2.輸入驗證：
a.密碼嘗試次數限制，提高安全性。
b.單與功能輸入都加上範圍檢查，並適時提示錯誤。

3.排版：
a.乘法表使用固定寬度輸出，以對齊表格。
b.三角形輸出則根據字母生成，可調整範圍。。

4.心得：
這次練習讓我更熟悉如何設計互動式 C 程式，
包含畫面清除、無需按 Enter 的按鍵偵測，
及良好的函式拆分與錯誤處理邏輯。
尤其在直角三角形部分，由起點遞減到 a的方式。 
這只是程式語言微不足道的一小部分，我還得更加努力的去學習更多的知識內容來應對未來的挑戰 ，
隨著ai肉眼可見的進步速度 ，我也得學更多的內容去應對未來大環境趨勢的變化以防被淘汰。 
*/
