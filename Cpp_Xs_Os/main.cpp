#include <cstdlib>
#include <iostream>
using namespace std;

char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

void printBoard() {
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "-----|-----|-----" << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "-----|-----|-----" << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
}
void resetBoard() {
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            board[i][j] = ' ';
        }
    }
}
int checkFreeSpaces() {
    int free = 9;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (board[i][j] != ' ') {
                free--;
            }
        }
    }
    return free;
}
void player1Turn() {
    int row1, col1;
    do {
        cout << "PLAYER1: Enter row number (1-3): ";
        cin >> row1;
        row1--;
        cout << "PLAYER1: Enter column number (1-3): ";
        cin >> col1;
        col1--;
        if (board[row1][col1] != ' ') {
            cout << "The place is already taken !" << endl;
        } else {
            board[row1][col1] = PLAYER1;
            break;
        }
    } while (board[row1][col1] != ' ');
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
void printWinner(char winner) {
    if (winner == PLAYER1) {
        cout << "PLAYER1 CONGRATS YOU WON !" << endl;
    } else if (winner == PLAYER2) {
        cout << "PLAYER2 CONGRATS YOU WON !" << endl;
    } else {
        cout << "DRAW !" << endl;
    }
}
void player2Turn() {
    int row2, col2;
    if (checkFreeSpaces() > 0) {
        do {
            cout << "PLAYER2: Enter row number (1-3): ";
            cin >> row2;
            row2--;
            cout << "PLAYER2: Enter column number (1-3): ";
            cin >> col2;
            col2--;
            if (board[row2][col2] != ' ') {
                cout << "The place is already taken !" << endl;
            } else {
                board[row2][col2] = PLAYER2;
                break;
            }
        } while (board[row2][col2] != ' ');
    } else {
        printWinner(' ');
    }
}

int main() {
    cout << "PLAYER 1 IS X" << endl;
    cout << "PLAYER 2 IS O" << endl;
    char winner = ' ';
    char rematch = ' ';
    resetBoard();
    do {
        winner = ' ';
        rematch = ' ';
        resetBoard();
        while (winner == ' ' && checkFreeSpaces() != 0) {
            printBoard();
            player1Turn();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0) {
                break;
            }
            system("clear");
            printBoard();
            player2Turn();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0) {
                break;
            }
            system("clear");
        }
        system("clear");
        printBoard();
        printWinner(winner);
        cout << "WANT A REMATCH ?" << endl;
        cout << "Y (yes) / N (no) : ";
        cin >> rematch;
        system("clear");
    } while (rematch == 'Y');
    cout << "GG !" << endl;
    return 0;
}
