#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#define PASSWORD 2025
#define MAX_TRY   3

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

    // �D�j��G��ܿ��óB�z��J
    while (running) {
        system("cls"); 
        printf("======== �D��� ========\n");
        printf("a. �����T����\n");
        printf("b. ��ܭ��k��\n");
        printf("c. ����\n");
        printf("========================\n");
        printf("�п�� (a/b/c): ");

        choice = getch(); 
        printf("%c\n", choice);

        switch (choice) {
            case 'a': case 'A': {
                char triangleChar;
                printf("�п�J�@�Ӧr�� (a~n): ");
                scanf(" %c", &triangleChar);

                if (triangleChar >= 'a' && triangleChar <= 'n') {
                    print_letter_triangle(triangleChar);
                } else {
                    printf("��J���~�A�����O a~n �������r���C\n");
                    getch();
                }
                break;
            }
            case 'b': case 'B': {
                int n;
                printf("�п�J���k��j�p (1~9): ");
                scanf("%d", &n);

                if (n >= 1 && n <= 9) {
                    print_multiplication_table(n);
                } else {
                    printf("��J���~�A�����O 1~9 ��������ơC\n");
                    getch();
                }
                break;
            }
            case 'c': case 'C': {
                char cont;
                printf("�T�w�n�����{���ܡH (y/n): ");
                cont = getch();
                printf("%c\n", cont);

                if (cont=='y' || cont=='Y') {
                    printf("�{������\n");
                    running = 0;
                } else if (cont=='n' || cont=='N') {
                    // ��^�D���
                } else {
                    printf("��J���~�A��^�D���C\n");
                    getch();
                }
                break;
            }
            default:
                printf("�ﶵ���~�A�Э��s��ܡC\n");
                getch();
        }
    }

    return 0;
}

// 3. �����T���ΡG�ѿ�J�r���˧Ǧ� a�A�ë��r�����ǲ֥[�C�L
void print_letter_triangle(char ch) {
    system("cls");
    printf("�����T���� (%c)\n\n", ch);

    // start  �v�B����� 'a'
    for (char start = ch; start >= 'a'; start--) {
        // ���h�q start �C�L�� ch
        for (char letter = start; letter <= ch; letter++) {
            printf("%c", letter);
        }
        printf("\n");
    }

    printf("\n�����N���^�D���...\n");
    getch();
}

// 4. n*n ���k��
void print_multiplication_table(int n) {
    system("cls");
    printf("%d x %d ���k��\n\n", n, n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    printf("\n�����N���^�D���...\n");
    getch();
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
