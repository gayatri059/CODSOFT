#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "Tic-Tac-Toe Board:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---------" << endl;
    }
}

// Function to check if the current player has won
bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    // If no empty cells are left and no player has won, it's a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';
    bool gameover = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameover) {
        displayBoard(board);

        // Prompt the current player for their move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Update the board with the player's move
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameover = true;
        }
        // Check if the game is a draw
        else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            gameover = true;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;

    return 0;
}
