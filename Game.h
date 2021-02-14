#pragma once                     
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Piece.h"
#include <random>
#include <time.h>

#include <iostream>
#include <math.h>
#include <stdlib.h>                     // Provides exit
#include <ctype.h>                      // Provides toupper

using namespace std;

colors operator!(colors Turn);

class Game
{
public:
	Piece*** Board;
	void Init();
	colors Turn;
	void drawBoard();
	void drawCell(Position pos);
	bool validStartPos(Position &startpos, colors Turn);
	bool validEndPos(Position& endpos, colors Turn);
	static void mouseClick(Position& pos);
	void highLight(Position pos, colors color);
	void highLightValids();
	Position findKing(colors kingColor);
	bool check(colors Turn);



	Game() {
		bool same;
		bool selfCheck;
		bool enemyCheck;
		same = enemyCheck = selfCheck = false;
		srand(time(0));
		Init();
		drawBoard();
		Turn = (rand() * 1000) % 2 == 0 ? WHITE: BLACK;
		Position startpos;
		Position endpos;
		do {
			Piece::clearValids();
			drawBoard();
			if (selfCheck || enemyCheck) {
				Position king = findKing(Turn);
				highLight(king, RED);
			}
			same = enemyCheck = selfCheck = false;
			cout << "Turn changed to " << (Turn == WHITE ? "WHITE" : "BLACK") << endl;
			do {
				mouseClick(startpos);
			}while(!validStartPos(startpos, Turn));

			Board[startpos.y][startpos.x]->markValids(Board, Turn);
			highLightValids();
			highLight(startpos, YELLOW);

			do {
				mouseClick(endpos);
				if (startpos.y == endpos.y && startpos.x == endpos.x) {
					same = true;
					break;
				}
			} while (!Piece::valids[endpos.y][endpos.x]);
			if (same)
				continue;

			if (check(!Turn)) {
				enemyCheck = true;
			}
			
			delete Board[endpos.y][endpos.x];
			Board[endpos.y][endpos.x] = Board[startpos.y][startpos.x];
			Board[endpos.y][endpos.x]->pos = endpos;
			Board[startpos.y][startpos.x] = nullptr;

			Turn = !Turn;
		} while (!kbhit());
	}
};

