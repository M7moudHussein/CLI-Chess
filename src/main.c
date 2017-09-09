/*
 ============================================================================
 Name        : Chess Project
 Author      : Mahmoud Hussein (73) & Hesham El-Sawaf (84)
 Copyright   : Copy rights reserved 2015-2016
 Description : Chess game (Human VS Human)
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "main.h"
#define true 1
#define false 0

int i = 0, j = 0;
int eaten1Index = 0, eaten2Index = 0;
int wky = 7, wkx = 4, bky = 0, bkx = 4; //Global Variable
int lastMove = 1, maxMoves = 0;
char refBoard[8][8];
char board[8][8], input[5];
char indexL[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
char indexN[8] = { '1', '2', '3', '4', '5', '6', '7', '8' };
char choice;
int main() {
	setbuf(stdout, NULL);		//Sheel alcode da ya 3am al7ag
	defaultB();
	colors();
	if (mainMenu())
		return 0;
	turn = true;
	while (true) {
		if (condition == 1) {
			system("clear");
			printing(turn);
			printf("\n\t\tCHECKMATE! \n");
			turn == false ?
					printf("\n\t\t%s WINS\n", player1) :
					printf("\n%s WINS\n", player2);
			getchar();
		}
		if (condition == 3) {
			system("clear");
			printing(turn);
			printf("\n\t\tSTALEMATE! \n");
			return 0;
		}
		system("clear");
		printing(turn);
		if (condition == 2) {
			turn == true ?
					printf("\nWATCH OUT %s! YOUR KING IS CHECKED.", player1) :
					printf("\nWATCH OUT %s! YOUR KING IS CHECKED.", player2);
			condition = 0;
		}
		turn == true ?
				printf("\n%s's turn: ", player1) :
				printf("\n%s's turn: ", player2);

		scan(turn);
		//promotion();
		if (!checkCell(!turn)) {
			if (checkmate(turn)) {
				condition = 1;
			} else
				condition = 2;
		} else if (checkmate(turn))
			condition = 3;
		turn = !turn;
	}
	return 0;
}
