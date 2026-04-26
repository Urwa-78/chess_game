#include"board.h"
#include"Pawn.h"
#include"Rook.h"
#include<iostream>
#include<cstring>
#include<String>
using namespace std;
board::board() :currentturn('W'), gameover(false), winner("") {

	for (int r = 0;r < 8;r++) {
		for (int c = 0;c < 8;c++) {
			grid[r][c] = nullptr;
			setuppieces();
		}
	}
}
board::~board() {
	clearboard();

}
void board::clearboard() {
	for (int r = 0;r < 8;r++) {
		for (int c = 0;c < 8;c++) {
			delete grid[r][c];
			grid[r][c] = nullptr;
		}
	}
}
void board::setuppieces() {
	
    grid[0][0] = new Rook('B', 0, 0);
    /*grid[0][1] = new Knight('B', 0, 1);
    grid[0][2] = new Bishop('B', 0, 2);
    grid[0][3] = new Queen('B', 0, 3);
    grid[0][4] = new King('B', 0, 4);
    grid[0][5] = new Bishop('B', 0, 5);
    grid[0][6] = new Knight('B', 0, 6);*/
    grid[0][7] = new Rook('B', 0, 7);

    // Black pawns (row 1)
    for (int c = 0; c < 8; c++)
        grid[1][c] = new Pawn('B', 1, c);

    // White pawns (row 6)
    for (int c = 0; c < 8; c++)
        grid[6][c] = new Pawn('W', 6, c);

    // White back row (row 7)
    grid[7][0] = new Rook('W', 7, 0);
    /*grid[7][1] = new Knight('W', 7, 1);
    grid[7][2] = new Bishop('W', 7, 2);
    grid[7][3] = new Queen('W', 7, 3);
    grid[7][4] = new King('W', 7, 4);
    grid[7][5] = new Bishop('W', 7, 5);
    grid[7][6] = new Knight('W', 7, 6);*/
    grid[7][7] = new Rook('W', 7, 7);
}
void board::display()const {
    cout << "\n  a  b  c  d   e   f   g   h\n";
    cout << "---------------------------------\n";
    cout << "---------------------------------\n";
    for (int r = 0;r < 8;r++) {
        cout << (8 - r) << "|";
        for (int c = 0;c < 8;c++) {
            if (grid[r][c] == nullptr)
            {
                cout << " .|";
            }
            else {
                cout << " " << grid[r][c]->getsymbol() << " |";
            }
        }
        cout << " " << (8 - r) << "\n";
        cout << "----------------------------\n";
        cout << "------------------------------\n";

        cout << "a    b   c   d   e   f   g   h\n";
        cout << "UPPERCASE=White | LOWERCASE=Black\n";
        cout << "P=Pawn R=Rook N=Knight B=Bishop  Q=Queen K=King\n\n";
    }
}
    //move logic
bool board::movepiece(int frorow, int frocol, int torow, int tocol) {
    if (isinbound(frorow, frocol || isinbound(torow, tocol))) {
        cout << "Out of bound ,Position\n";
        return false;
    }

    piece* p= grid[frorow][frocol];
    if (p == nullptr) {
        cout << "no piece at that position\n";
        return false;
    }
    if (p->getcolor()!=currentturn) {
        cout << "This is not your piece\n";
        return false;
    }
    if (frorow == torow && frocol == tocol) {
        cout << "You must move to a different position\n";
        return false;
    }
    if (!p->isvalidmove(torow, tocol, grid)) {
        cout << "INVALID move for" << p->getname() << ".\n";
        return false;
    }
    //execute move
    piece* t = grid[torow][tocol];
    if (t != nullptr) {
        char capturecolor = t->getcolor();
        string  capturename = t->getname();

        delete grid[torow][tocol];
        grid[torow][tocol] = nullptr;
        cout << " >>" << (capturecolor == 'W' ? "White", "Black") << " " << capturename << "captured!\n";

    }



    //king logic------fatima 



    /*if (capturedName == "King") {
        gameOver = true;
        winner = (currentTurn == 'W') ? "White" : "Black";
    }*/

    //mmove the piece
    grid[torow][tocol] = p;
    grid[frorow][frocol] = nullptr;
    p->setposition(torow, tocol);

    return true;
}
//TURN MANAGMENT
 void  board::switchturn() {
     currentturn = (currentturn == 'W') ? 'B' : 'W';
}
 char board::getcurrentturn()const {
     return currentturn;
 }
     bool board::isgameover() {
         return gameover;
     }
     string board::getwinner(){
         return winner;
}
     piece* board::getpiece(int r, int c)const {
         if(!isinbound(r,c))
             return nullptr;
             return grid[r][c];
     }
     //fatima :  -----king alive check logic have to put here
     bool board::parseposition(const string& pos, int& row, int& col) {
         if (pos.size() != 2) return false;
         char colchar = tolower(pos[0]);
         char rowchar = pos[1];
         if (colchar < 'a' || colchar > 'h') return false;
         if (rowchar < '1' || rowchar > '8') return false;
         col = colchar - 'a';
         row = 8 - (rowchar - '0');
         return true;
     }