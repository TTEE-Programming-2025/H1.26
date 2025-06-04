#include <stdio.h>
#include <stdlib.h>  
#include <string.h>   
#include <ctype.h>   
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
  
    return 0;
}
