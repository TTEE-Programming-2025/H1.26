#include <stdio.h>
#include <stdlib.h>   /* for system() */
#include <string.h>   /* for strcmp() */
#include <ctype.h>    /* for isupper, islower, isdigit */

#define PASSWORD "2024"  /* �K�X */

void clearScreen() {
    system("cls"); /* �M���ù��]Windows �M�Ρ^*/
}

int main() {
    char inputPassword[20];
    char userInput;
    int i;

    /* ��ܭӤH����e�� */
    printf("***************************************\n");
    printf("**           Welcome �w��!           **\n");
    printf("**                                   **\n");
    printf("**           By �h����               **\n");
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
    printf("�� Enter ���~�򤺮e...");
    getchar(); /* ���ݿ�J�]���@�� Enter�^*/
    clearScreen();

    /* �K�X��J */
    printf("��J4��K�X: ");
    scanf("%19s", inputPassword);
    if (strcmp(inputPassword, PASSWORD) != 0) {
        printf("(���~���K�X�A�{���N�פ�)\n");
        printf("%c", '\a'); /* �a�n */
        return 0;
    }
    printf("(�K�X���T�A�w��!!!)\n");
    getchar(); /* �M���W�@�ӿ�J�� Enter */
    getchar(); /* �A�����ݫ��� */
    clearScreen();

    /* ��ܥD��� */
    printf("-------------------------------\n");
    printf("|  'A'...'Z'  : Uppercase     |\n");
    printf("|  'a'...'z'  : Lowercase     |\n");
    printf("|  '0'...'9'  : Digit         |\n");
    printf("|  Otherwise  : Your name     |\n");
    printf("-------------------------------\n");

    /* �����ϥΪ̿�J */
    printf("��J�@�Ӧr��: ");
    scanf(" %c", &userInput);  /* �Ů�i���L�e���ݯd������ */

    if (isupper(userInput)) {
        printf("Uppercase\n");
    } else if (islower(userInput)) {
        printf("Lowercase\n");
    } else if (isdigit(userInput)) {
        printf("Digit\n");
    } else {
        printf("H1.26 �h����\n");
    }

    printf("�� Enter ���}...");
    getchar(); /* �M����J�w�İ� */
    getchar();
    return 0;
}
//�o�����@�~���ڲz��: 
//1.�ƪ������n�ʡA���ä������ƪ��|�ɭP�g�{�����|�ݭn��h���ɶ��h�ݥh�ˬd�A�S���W�ߩʤ]�|���H�P��ӥ~�h�� �C 
//2.if else�ھڤ��P����J�������X�����C�S�O�O�b�r�ŧP�_�譱�A�ϥ� if �ӧP�_�r���O�_���j�g�r���B�p�g�r���μƦr�C 
//3.system("cls")�^���ϥγo�˨ϥΪ̴N�|�@���ݨ��ª��e���Asystem("cls")�ӲM���ù����{����o��[���A���ާ@�̦���n���ާ@����C 
//�o�u�O�{���y�������L�����D���@�Ӥp���� �A�o�ӻ��ܧx���A���]�ܲ`�A�ڱo�h�[�j�o�ӻ�쪺���e�ӭ��良�Ӥ��׬O�ҷ~�٬O�N�ӨƷ~���D�ԡC 


