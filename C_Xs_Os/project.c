#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void player1Turn();
void player2Turn();
char checkWinner();
void printWinner(char);

int main() {
    printf("PLAYER 1 IS X \n");
    printf("PLAYER 2 IS O \n");
    char winner = ' ';
    char rematch = ' ';
    do {
        winner = ' ';
        rematch = ' ';
        resetBoard();
        while(winner == ' ' && checkFreeSpaces() != 0) {
            printBoard();
            player1Turn();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0) {
                break;
            }
            system("clear");
            printBoard();
            player2Turn();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0) {
                break;
            }
            system("clear");
        }
        system("clear");
        printBoard();
        printWinner(winner);
        printf("\nWANT A REMATCH ?");
        printf("\nY (yes) / N (no) : ");
        scanf(" %c",&rematch);
        rematch = toupper(rematch);
    } while(rematch == 'Y');
    printf("GG ! ");
    return 0;
}
void resetBoard() {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            board[i][j] = ' ';
        }
    }
}
void printBoard() {
    printf("  %c  |  %c  |  %c",board[0][0],board[0][1],board[0][2]);
    printf("\n-----|-----|-----");
    printf("\n  %c  |  %c  |  %c",board[1][0],board[1][1],board[1][2]);
    printf("\n-----|-----|-----");
    printf("\n  %c  |  %c  |  %c",board[2][0],board[2][1],board[2][2]);
    printf("\n");
}
int checkFreeSpaces() {
    int free = 9;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(board[i][j] != ' ') {
                free--;
            }
        }
    }
    return free;
}
void player1Turn() {
    int row1 , col1;
    do {
        printf("PLAYER1 : Enter row number (1-3) : ");
        scanf("%d",&row1);
        row1--;
        printf("PLAYER1 : Enter column number (1-3) : ");
        scanf("%d",&col1);
        col1--;
        if(board[row1][col1] != ' ') {
            printf("The place is already taken ! \n");
        } else {
            board[row1][col1] = PLAYER1;
            break;
        }
    } while(board[row1][col1] != ' ');
}
char checkWinner() {
    for(int i=0;i<3;i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }
    for(int j=0;j<3;j++) {
        if(board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return board[0][j];
        }
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }
    return ' ';
}
void player2Turn() {
    int row2 , col2;
    if(checkFreeSpaces() > 0) {
        do {
            printf("PLAYER2 : Enter row number (1-3) : ");
            scanf("%d",&row2);
            row2--;
            printf("PLAYER2 : Enter column number (1-3) : ");
            scanf("%d",&col2);
            col2--;
            if(board[row2][col2] != ' ') {
                printf("The place is already taken ! \n");
            } else {
                board[row2][col2] = PLAYER2;
                break;
            }
        } while(board[row2][col2] != ' ');
    } else {
        printWinner(' ');
    }
}
void printWinner(char winner) {
    if(winner == PLAYER1) {
        printf("PLAYER1 CONGRATS YOU WON ! \n");
    } else if(winner == PLAYER2) {
        printf("PLAYER2 CONGRATS YOU WON ! \n");
    } else {
        printf("DRAW ! \n");
    }
}
