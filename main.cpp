#include <iostream>

#define ROWS 3
#define COLS 3

bool xWin, oWin, draw = false;
char player = 'X';

// Create board
char board[ROWS][COLS] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}};

// Print out the board
void displayBoard() {
    std::cout << board[0][0] << '|' << board[0][1] << '|' << board[0][2] << std::endl;
    std::cout << "------\n";
    std::cout << board[1][0] << '|' << board[1][1] << '|' << board[1][2] << std::endl;
    std::cout << "------\n";
    std::cout << board[2][0] << '|' << board[2][1] << '|' << board[2][2] << std::endl;
}

// Validate move and update board
bool validatePosition(char position, char player) {
    char checkFor;
    int pos1, pos2;
    
    if (player == 'X') {
        checkFor = 'O';
    } else {
        checkFor = 'X';
    }

    switch(position) {
        case 'A': pos1 = 0, pos2 = 0; break;
        case 'B': pos1 = 0, pos2 = 1; break; 
        case 'C': pos1 = 0, pos2 = 2; break; 
        case 'D': pos1 = 1, pos2 = 0; break; 
        case 'E': pos1 = 1, pos2 = 1; break; 
        case 'F': pos1 = 1, pos2 = 2; break; 
        case 'G': pos1 = 2, pos2 = 0; break; 
        case 'H': pos1 = 2, pos2 = 1; break; 
        case 'I': pos1 = 2, pos2 = 2; break; 
    }

    if (board[pos1][pos2] == checkFor) {
        std::cout << "You can't move there!\n";
        return false;
    } else { 
        board[pos1][pos2] = player;
        displayBoard();
        return true;
    }
}

// Check for draws
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' || board[i][j] != 'O') {
                return false;
            }
        }
    }

    return !xWin && !oWin;
}

// See if X or O has won
void checkWin() {
    // X win
    // Top horizontal
    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') {
        xWin = true;
    }
    // Middle horizontal
    else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')  {
        xWin = true;
    }  
    // Bottom horizontal
    else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') {
        xWin = true;
    }
    // Left vertical
    else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') {
        xWin = true;
    } 
    // Middle vertical
    else if (board[0][1] == 'X' && board[1][1] == 'X' && board [2][1] == 'X') {
        xWin = true;
    }
    // Right vertical
    else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') {
        xWin = true;
    }
    // Left diagonal
    else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
        xWin = true;
    }
    // Right diagonal
    else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
        xWin = true;
    }
    
    // O win
    // Top horizontal
    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') {
        xWin = true;
    }
    // Middle horizontal
    else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')  {
        xWin = true;
    }  
    // Bottom horizontal
    else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') {
        xWin = true;
    }
    // Left vertical
    else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') {
        xWin = true;
    } 
    // Middle vertical
    else if (board[0][1] == 'X' && board[1][1] == 'X' && board [2][1] == 'X') {
        xWin = true;
    }
    // Right vertical
    else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') {
        xWin = true;
    }
    // Left diagonal
    else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
        xWin = true;
    }
    // Right diagonal
    else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
        xWin = true;
    }
}

void swapPlayer(char previousPlayer) {
    if (previousPlayer == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}

int main(int argc, char* argv[]) {
    char position;

    // Initial display
    displayBoard();
    
    // Main loop
    while (!xWin || !oWin) { 
        std::cout << "\n" << player << "'s turn\n";

        // Get what position the player wants to go to
        std::cin >> position; 
        
        // Validate if the player's move hadn't been taken
        if (validatePosition(toupper(position), player)) {
            checkWin();
            // Swap player after their move
            swapPlayer(player);

            // Win messages
            if (xWin == true) {
                std::cout << "X wins!\n";
                return 0;
            } else if (oWin == true) {
                std::cout << "O wins!\n"; 
                return 0;
            } else if (checkDraw()) {
                std::cout << "Draw!\n";
                return 0;
            }
        }
    }

    return 0;
}