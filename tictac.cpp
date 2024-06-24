#include <iostream>
#include <vector>
using namespace std;

// Function to print the Tic Tac Toe board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

// Function to check if the current player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    
    return false;
}

// Function to play Tic Tac Toe
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize empty board
    bool player1Turn = true; // Player 1 starts first
    int moves = 0; // Count of total moves

    while (moves < 9) { // Maximum 9 moves in a game
        // Print the board
        cout << "Current board:" << endl;
        printBoard(board);
        
        // Determine current player
        char currentPlayer = (player1Turn) ? 'X' : 'O';
        cout << "Player " << currentPlayer << "'s turn. Enter row (1-3) and column (1-3) separated by space: ";
        
        int row, col;
        cin >> row >> col;
        
        // Adjust row and column to 0-indexed
        row--;
        col--;
        
        // Check if the chosen cell is valid and empty
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            moves++;
            
            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                printBoard(board);
                return;
            }
            
            // Switch to the next player
            player1Turn = !player1Turn;
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }
    
    // If no one wins after 9 moves, it's a tie
    cout << "It's a tie!" << endl;
    printBoard(board);
}

int main() {
    cout << "Welcome to Tic Tac Toe!" << endl;
    char playAgain = 'y';
    
    while (playAgain == 'y' || playAgain == 'Y') {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }
    
    cout << "Thanks for playing Tic Tac Toe!" << endl;
    return 0;
}
