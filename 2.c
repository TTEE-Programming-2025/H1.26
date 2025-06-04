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

    // 1. �n�J����
    while (attempt < MAX_TRY) {
        printf("�п�J4��ƱK�X: ");
        scanf("%d", &password);

        if (password == PASSWORD) {
            printf("�K�X���T�A�w��ϥ�!\n");
            break;
        } else {
            attempt++;
            if (attempt == MAX_TRY) {
                printf("���~�T���A�j����C\n");
                return 1;
            } else {
                printf("�K�X���~�A�Э��s��J�C\n");
            }
        }
    }

    while (running) {
        clear_screen();
        printf("======== �D��� ========\n");
        printf("a. �����T����\n");
        printf("b. ��ܭ��k��\n");
        printf("c. ����\n");
        printf("========================\n");
        printf("�п�� (a/b/c): ");

        while ((choice = getchar()) == '\n'); // Ū�줣�O����~����
        printf("%c\n", choice);

        switch (choice) {
            case 'a':
            case 'A': {
                char triangleChar;
                printf("�п�J�@�Ӧr�� (a~n): ");
                // �Y���e���i��ݯd������
                while ((triangleChar = getchar()) == '\n');
                if (triangleChar >= 'a' && triangleChar <= 'n') {
                    print_letter_triangle(triangleChar);
                } else {
                    printf("��J���~�A�����O a~n �������r���C\n");
                    wait_for_key();
                }
                break;
            }
            case 'b':
            case 'B': {
                int n;
                printf("�п�J���k��j�p (1~9): ");
                if (scanf("%d", &n) == 1) {
                    if (n >= 1 && n <= 9) {
                        print_multiplication_table(n);
                    } else {
                        printf("��J���~�A�����O 1~9 ��������ơC\n");
                        wait_for_key();
                    }
                } else {
                    printf("��J���~�A�п�J�Ʀr�C\n");
                    wait_for_key();
                    // �M�ſ��~��J
                    while (getchar() != '\n');
                }
                break;
            }
            case 'c':
            case 'C': {
                char cont;
                printf("�T�w�n�����{���ܡH (y/n): ");
                while ((cont = getchar()) == '\n');
                printf("%c\n", cont);

                if (cont == 'y' || cont == 'Y') {
                    printf("�{������\n");
                    running = 0;
                } else if (cont == 'n' || cont == 'N') {
                    // ��^�D���
                } else {
                    printf("��J���~�A��^�D���C\n");
                    wait_for_key();
                }
                break;
            }
            default:
                printf("�ﶵ���~�A�Э��s��ܡC\n");
                wait_for_key();
        }
    }

    return 0;
}

void print_letter_triangle(char ch) {
    int i, j;
    clear_screen();
    printf("�����T���� (%c)\n\n", ch);

    for (i = ch; i >= 'a'; i--) {
        for (j = i; j <= ch; j++) {
            printf("%c", j);
        }
        printf("\n");
    }

    printf("\n�� Enter ���^�D���...\n");
    wait_for_key();
}

void print_multiplication_table(int n) {
    int i, j;
    clear_screen();
    printf("%d x %d ���k��\n\n", n, n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    printf("\n�� Enter ���^�D���...\n");
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
    // �M�Žw�İϪ��촫��
    while ((ch = getchar()) != '\n' && ch != EOF);
    // ���ݨϥΪ̫� Enter
    getchar();
}
/*�����P�߱o�G

1.�{���[�c�G
a.�N�C�ӥ\��������禡 �A���C main() �������סC
b.�ϥ� clear screen (cls) �� getch()�A����²�������ʦ������C

2.��J���ҡG
a.�K�X���զ��ƭ���A�����w���ʡC
b.��P�\���J���[�W�d���ˬd�A�þA�ɴ��ܿ��~�C

3.�ƪ��G
a.���k��ϥΩT�w�e�׿�X�A�H������C
b.�T���ο�X�h�ھڦr���ͦ��A�i�վ�d��C�C

4.�߱o�G
�o���m�����ڧ���x�p��]�p���ʦ� C �{���A
�]�t�e���M���B�L�ݫ� Enter �����䰻���A
�Ψ}�n���禡����P���~�B�z�޿�C
�ר�b�����T���γ����A�Ѱ_�I����� a���覡�C 
�o�u�O�{���y���L�����D���@�p�����A���ٱo��[�V�O���h�ǲߧ�h�����Ѥ��e�����良�Ӫ��D�� �A
�H��ai�ײ��i�����i�B�t�� �A�ڤ]�o�ǧ�h�����e�h���良�Ӥj�����Ͷժ��ܤƥH���Q�^�O�C 
*/
