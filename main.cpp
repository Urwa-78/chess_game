#include<iostream>
#include<string>
#include<limits>
#include "board.h"
using namespace std;
void banner() {
	cout << "\n===========================\n";
	cout << "========CHESS-GAME=========\n";
	cout << "===========================\n";
	cout << endl;
	cout << "Type the from square and then press Enter.\n";
	cout << "Then type the to square and press Enter.\n";
	cout << "Type quit to exit the game.\n";
}
// main body
int main() {
	banner();
	board Board;
	Board.display();
	while (!Board.isgameover()) {
		string playername = (Board.getcurrentturn() == 'W' ? "White" : "Black");
		cout << playername << "---turn----\n";
		string frominit, toinit;
		int fromrow, fromcol, torow, tocol;
		cout << "Enter from square(i.e. b3): ";
		cin >> frominit;
		if (frominit == "quit") {
			cout << "=====Game exited-----byeee=====\n";
			return 0;
		}
		if (!board::parseposition(frominit, fromrow, fromcol)) {
			cout << "Invalid format,use (e3,b4)format: \n";
			continue;
		}
		piece* selected = Board.getpiece(fromrow, fromcol);
		if (selected == nullptr) {
			cout << "That square is empty.\n";
			continue;
		}
		if (selected->getcolor() != Board.getcurrentturn()) {
			cout << "This is not your current piece\n";
			continue;
		}
		cout << "Selected:" << (selected->getcolor() == 'W' ? "White" : "Black") << selected->getname() << "AT" << frominit << endl;

		cout << "Enter TO square(i-e e4): ";
		cin >> toinit;
		if (toinit == "quit") {
			cout << "Game exited-----bye--\n";
			return 0;
		}
		if (!board::parseposition(toinit, torow, tocol)) {
			cout << "Invalid format, use (e3, b4) format\n";
			continue;
		}
		bool moved = Board.movepiece(fromrow, fromcol, torow, tocol);
		if (moved) {
			Board.display();
			if (Board.isKingCaptured('W')) {
				cout << "\n*** Black Wins! White King captured. ***\n";
				break;
			}
			if (Board.isKingCaptured('B')) {
				cout << "\n*** White Wins! Black King captured. ***\n";
				break;
			}

			// check for checkmate
			char opponent = (Board.getcurrentturn() == 'W') ? 'B' : 'W';
			if (Board.ischeckmate(opponent)) {
				cout << "*** " << (opponent == 'W' ? "Black" : "White") << " Wins! Checkmate! ***\n";
				break;
			}
			// check for check
			if (Board.isincheck(opponent)) {
				cout << "*** " << (opponent == 'W' ? "White" : "Black") << " is in Check! ***\n";
			}
			Board.switchturn();
		}
		else {
			cout << "Try again\n";
		}
	}
	cout << "\n";
	cout << "========================\n";
	cout << "       GAME OVER!" << endl;
	cout << "========================\n";
	return 0;
}