#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define true 1
#define false 0
#ifndef MAIN_H_
#define MAIN_H_

int i, j, wkx, wky, bkx, bky, eaten1Index, eaten2Index, lastMove, condition,maxMoves;//Global Variable
char refBoard[8][8];
char board[8][8], input[5];
char indexL[8];
char indexN[8];
char player1[101], player2[101];
char eaten1[16], eaten2[16];
char savedMoves[500][6];
bool turn;

bool rook();
bool bishop();
bool queen();
bool pawns();
bool king();
bool knight();
bool checkCell(bool);
bool checkMoveV2(bool);
bool checkmate(bool);
bool mainMenu();
void promotion();
void defaultB();
void checkMove();
void scan(bool);
void doMove(bool);
void colors();
void printing(bool);
void undo();
void redo();
void saveMove();
void save();
void load();
#endif /* MAIN_H_ */
