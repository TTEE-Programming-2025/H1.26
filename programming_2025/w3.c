#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h> 

#define ROWS 9
#define COLS 9
#define PASSWORD "2025"
#define MAX_ATTEMPTS 3

char seats[ROWS][COLS];

// Function to clear the screen
void clearScreen() {
    system("cls"); // for Windows
}

// Function to initialize the seat map with '-' and randomly reserve 10 seats as '*'
void initSeats() {
    srand(time(NULL));
    int count = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j] = '-';

    while (count < 10) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] != '*') {
            seats[r][c] = '*';
            count++;
        }
    }
}

// Function to display the seat map
void displaySeats() {
    printf(" \\123456789\n");
    for (int i = ROWS - 1; i >= 0; i--) {
        printf("%d", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

// Function to authenticate password
int login() {
    char input[10];
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter 4-digit password: ");
        scanf("%s", input);

        if (strcmp(input, PASSWORD) == 0) {
            printf("Welcome!\n");
            return 1;
        } else {
            printf("Incorrect password. Try again.\n");
            attempts++;
        }
    }

    printf("Too many failed attempts. System locked.\n");
    return 0;
}

// Function to randomly arrange seats for the user
void autoArrange(int count) {
    int found = 0;
    for (int i = 0; i < ROWS && !found; i++) {
        for (int j = 0; j <= COLS - count; j++) {
            int ok = 1;
            for (int k = 0; k < count; k++) {
                if (seats[i][j + k] != '-') {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                for (int k = 0; k < count; k++) {
                    seats[i][j + k] = '@';
                }
                found = 1;
                break;
            }
        }
    }

    if (!found && count == 4) {
        for (int i = 0; i < ROWS - 1 && !found; i++) {
            for (int j = 0; j < COLS; j++) {
                if (seats[i][j] == '-' && seats[i + 1][j] == '-') {
                    seats[i][j] = seats[i + 1][j] = '@';
                    for (int k = 0; k < COLS; k++) {
                        if (k != j && seats[i][k] == '-') {
                            seats[i][k] = '@';
                            for (int l = 0; l < COLS; l++) {
                                if (l != j && l != k && seats[i + 1][l] == '-') {
                                    seats[i + 1][l] = '@';
                                    found = 1;
                                    break;
                                }
                            }
                            if (found) break;
                            else seats[i][k] = '-';
                        }
                    }
                    if (!found) {
                        seats[i][j] = seats[i + 1][j] = '-';
                    }
                }
            }
        }
    }

    displaySeats();
    printf("Are you satisfied with this arrangement? (y/n): ");
    char ch;
    scanf(" %c", &ch);

    if (ch == 'y' || ch == 'Y') {
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                if (seats[i][j] == '@')
                    seats[i][j] = '*';
    } else {
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                if (seats[i][j] == '@')
                    seats[i][j] = '-';
    }
}

// Function for manual seat selection
void manualChoose() {
    int n;
    char input[10];
    printf("How many seats to choose (1-4)? ");
    scanf("%d", &n);
    if (n < 1 || n > 4) {
        printf("Invalid number.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        int r, c;
        while (1) {
            printf("Enter seat (row-col, e.g., 3-5): ");
            scanf("%s", input);
            if (sscanf(input, "%d-%d", &r, &c) == 2 && r >= 1 && r <= 9 && c >= 1 && c <= 9) {
                if (seats[r - 1][c - 1] == '-') {
                    seats[r - 1][c - 1] = '@';
                    break;
                } else {
                    printf("Seat already taken.\n");
                }
            } else {
                printf("Invalid input format.\n");
            }
        }
    }

    displaySeats();
    printf("Press any key to confirm...");
    getch();

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (seats[i][j] == '@')
                seats[i][j] = '*';
}

// Main menu
void menu() {
    char choice;
    while (1) {
        clearScreen();
        printf("----------[Booking System]----------\n");
        printf("| a. Available seats               |\n");
        printf("| b. Arrange for you               |\n");
        printf("| c. Choose by yourself            |\n");
        printf("| d. Exit                          |\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                clearScreen();
                displaySeats();
                printf("Press any key to return to menu...");
                getch();
                break;
            case 'b': {
                int people;
                printf("How many seats do you need (1-4)? ");
                scanf("%d", &people);
                if (people >= 1 && people <= 4)
                    autoArrange(people);
                else
                    printf("Invalid number.\n");
                printf("Press any key to return to menu...");
                getch();
                break;
            }
            case 'c':
                manualChoose();
                break;
            case 'd': {
                char confirm;
                printf("Continue? (y/n): ");
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') continue;
                else if (confirm == 'n' || confirm == 'N') {
                    printf("Goodbye.\n");
                    return;
                } else {
                    printf("Invalid input.\n");
                    getch();
                }
                break;
            }
            default:
                printf("Invalid option. Try again.\n");
                getch();
        }
    }
}

// Main program
int main() {
    clearScreen();
    printf("******** WELCOME TO THE SYSTEM ********\n");
    printf("*                                     *\n");
    printf("*       Personal Booking Program      *\n");
    printf("*         Designed by [h1.26]         *\n");
    printf("*                                     *\n");
    printf("***************************************\n\n");

    if (login()) {
        clearScreen();
        initSeats();
        menu();
    }

    return 0;
}


//�߱o

//�z�L�o�����y��w�q�t�Χ@�~�A�ڥ[�j�F�� C �y���򥻻y�k�P�޿誺�z�ѻP���ΡC
//�b�]�p�o�Өt�Ϊ��L�{���A�ڽm�ߤF�p��ϥΤG���}�C�Ӫ�ܮy��ϡA�H�Φp��B�z�ϥΪ̿�J�B�i����~�ˬd�B��ܿ��P�������P�_����Χޥ��C
//�ϫ�L�{�������~�A�C�C��i�F���ؼСC 
