// File 3: main.cpp
#include "chess-pieces.h"
#include <iostream>

using namespace std;
class ChessBoard {
private:
    ChessPiece* board[8][8];
    char currentPlayer;

    void initializeBoard() {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                board[i][j] = nullptr;

        // White pieces
        board[0][0] = new ChessPiece('W', "Rook", 0, 0);
        board[0][7] = new ChessPiece('W', "Rook", 0, 7);
        board[0][1] = new Knight('W', 0, 1);
        board[0][6] = new Knight('W', 0, 6);
        board[0][2] = new Bishop('W', 0, 2);
        board[0][5] = new Bishop('W', 0, 5);
        board[0][3] = new Queen('W', 0, 3);
        board[0][4] = new King('W', 0, 4);

        // Black pieces
        board[7][0] = new ChessPiece('B', "Rook", 7, 0);
        board[7][7] = new ChessPiece('B', "Rook", 7, 7);
        board[7][1] = new Knight('B', 7, 1);
        board[7][6] = new Knight('B', 7, 6);
        board[7][2] = new Bishop('B', 7, 2);
        board[7][5] = new Bishop('B', 7, 5);
        board[7][3] = new Queen('B', 7, 3);
        board[7][4] = new King('B', 7, 4);

        // Pawns (basic)
        for (int j = 0; j < 8; j++) {
            board[1][j] = new ChessPiece('W', "Pawn", 1, j);
            board[6][j] = new ChessPiece('B', "Pawn", 6, j);
        }
    }

public:
    ChessBoard() : currentPlayer('W') {
        initializeBoard();
    }

    ~ChessBoard() {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                delete board[i][j];
    }

    void printBoard() const {
        cout << "\n  0 1 2 3 4 5 6 7\n";
        for (int i = 0; i < 8; i++) {
            cout << i << " ";
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == nullptr)
                    cout << ". ";
                else {
                    string t = board[i][j]->getType();
                    char sym = (t == "Knight") ? 'N' : t[0];
                    cout << (board[i][j]->getColor() == 'W' ? sym : (char)tolower(sym)) << " ";
                }
            }
            cout << endl;
        }
    }

    bool makeMove(int fromX, int fromY, int toX, int toY) {
        if (fromX < 0 || fromX > 7 || fromY < 0 || fromY > 7 ||
            toX < 0 || toX > 7 || toY < 0 || toY > 7)
            return false;

        ChessPiece* piece = board[fromX][fromY];
        if (piece == nullptr || piece->getColor() != currentPlayer)
            return false;

        if (piece->isValidMove(toX, toY, board)) {
            delete board[toX][toY];           // capture if any
            board[toX][toY] = piece;
            board[fromX][fromY] = nullptr;
            piece->setPosition(toX, toY);

            currentPlayer = (currentPlayer == 'W') ? 'B' : 'W';
            return true;
        }
        return false;
    }

    bool isKingCaptured(char color) const {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] && board[i][j]->getType() == "King" &&
                    board[i][j]->getColor() == color)
                    return false;
            }
        }
        return true;
    }

    char getCurrentPlayer() const { return currentPlayer; }
};

int main() {
    ChessBoard game;
    int fromX, fromY, toX, toY;

    cout << "=== Simple Chess Game (OOP) ===\n";
    cout << "Enter moves as: fromX fromY toX toY\n";
    cout << "Enter -1 to quit\n";

    while (true) {
        game.printBoard();
        cout << "\nPlayer " << game.getCurrentPlayer() << "'s turn\n";
        cout << "Move (fromX fromY toX toY): ";

        cin >> fromX;
        if (fromX == -1) break;
        cin >> fromY >> toX >> toY;

        if (game.makeMove(fromX, fromY, toX, toY)) {
            cout << "Move successful!\n";

            if (game.isKingCaptured('W')) {
                cout << "\n*** Black Wins! White King captured. ***\n";
                break;
            }
            if (game.isKingCaptured('B')) {
                cout << "\n*** White Wins! Black King captured. ***\n";
                break;
            }
        }
        else {
            cout << "Invalid move! Try again.\n";
        }
    }

    cout << "Game Over.\n";
    return 0;
}