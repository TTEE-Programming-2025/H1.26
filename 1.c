#include <stdio.h>
#include <stdlib.h>   /* for system() */
#include <string.h>   /* for strcmp() */
#include <ctype.h>    /* for isupper, islower, isdigit */

#define PASSWORD "2024"  /* 密碼 */

void clearScreen() {
    system("cls"); /* 清除螢幕（Windows 專用）*/
}

int main() {
    char inputPassword[20];
    char userInput;
    int i;

    /* 顯示個人風格畫面 */
    printf("***************************************\n");
    printf("**           Welcome 歡迎!           **\n");
    printf("**                                   **\n");
    printf("**           By 柳辰翰               **\n");
    printf("**                                   **\n");
    printf("**             ^     ^               **\n");
    printf("**            (()__(())              **\n");
    printf("**           //       \\\\              **\n");
    printf("**          //(  0 0  )\\\\             **\n");
    printf("**          // (  w  ) \\\\             **\n");
    printf("**         \\\\ __________//            **\n");
    printf("**         000000000000000           **\n");
    printf("**        00000000000000000          **\n");
    printf("**     11 000000000000000000 11      **\n");
    printf("**   11    0000000000000000    11    **\n");
    printf("** 11    0000000000000000000     11  **\n");
    printf("**           1111   1111             **\n");
    printf("**           1111   1111             **\n");
    printf("**           1111   1111             **\n");
    printf("**           1111   1111       H1.26 **\n");
    printf("** __________________________________**\n");
    for (i = 0; i < 5; i++) {
        printf("**                                   **\n");
    }
    printf("***************************************\n");
    printf("按 Enter 鍵繼續內容...");
    getchar(); /* 等待輸入（按一次 Enter）*/
    clearScreen();

    /* 密碼輸入 */
    printf("輸入4位密碼: ");
    scanf("%19s", inputPassword);
    if (strcmp(inputPassword, PASSWORD) != 0) {
        printf("(錯誤的密碼，程式將終止)\n");
        printf("%c", '\a'); /* 鈴聲 */
        return 0;
    }
    printf("(密碼正確，歡迎!!!)\n");
    getchar(); /* 清除上一個輸入的 Enter */
    getchar(); /* 再次等待按鍵 */
    clearScreen();

    /* 顯示主選單 */
    printf("-------------------------------\n");
    printf("|  'A'...'Z'  : Uppercase     |\n");
    printf("|  'a'...'z'  : Lowercase     |\n");
    printf("|  '0'...'9'  : Digit         |\n");
    printf("|  Otherwise  : Your name     |\n");
    printf("-------------------------------\n");

    /* 接收使用者輸入 */
    printf("輸入一個字元: ");
    scanf(" %c", &userInput);  /* 空格可跳過前面殘留的換行 */

    if (isupper(userInput)) {
        printf("Uppercase\n");
    } else if (islower(userInput)) {
        printf("Lowercase\n");
    } else if (isdigit(userInput)) {
        printf("Digit\n");
    } else {
        printf("H1.26 柳辰翰\n");
    }

    printf("按 Enter 離開...");
    getchar(); /* 清除輸入緩衝區 */
    getchar();
    return 0;
}
//這次的作業讓我理解: 
//1.排版的重要性，雜亂不堪的排版會導致寫程式中會需要更多的時間去看去檢查，沒有規律性也會讓人感到而外疲憊 。 
//2.if else根據不同的輸入類型做出反應。特別是在字符判斷方面，使用 if 來判斷字元是否為大寫字母、小寫字母或數字。 
//3.system("cls")）不使用這樣使用者就會一直看到舊的畫面，system("cls")來清除螢幕讓程式顯得更加整潔，讓操作者有更好的操作體驗。 
//這只是程式語言中的微不足道的一個小部分 ，這個領域很困難，水也很深，我得多加強這個領域的內容來面對未來不論是課業還是將來事業的挑戰。 


