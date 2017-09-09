#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "main.h"
#define true 1
#define false 0

bool checkCell(bool turn) {	//return true if all is good : else return false
	int y, x;
	y = turn ? wky : bky;
	x = turn ? wkx : bkx;
	char cell = board[y][x];
	for (i = x + 1; i < 8; i++)
		if ((isupper(board[y][i]) && islower(cell))
				|| (islower(board[y][i]) && isupper(cell))) {
			if (board[y][i] == 'r' || board[y][i] == 'R' || board[y][i] == 'Q'
					|| board[y][i] == 'q')
				return false;
			else
				break;
		} else if ((islower(board[y][i]) && islower(cell))
				|| (isupper(board[y][i]) && isupper(cell))) {
			break;
		}
	for (i = x - 1; i >= 0; i--)
		if ((isupper(board[y][i]) && islower(cell))
				|| (islower(board[y][i]) && isupper(cell))) {
			if (board[y][i] == 'r' || board[y][i] == 'R' || board[y][i] == 'Q'
					|| board[y][i] == 'q')
				return false;
			else
				break;
		} else if ((islower(board[y][i]) && islower(cell))
				|| (isupper(board[y][i]) && isupper(cell))) {
			break;
		}
	for (i = y + 1; i < 8; i++)
		if ((isupper(board[i][x]) && islower(cell))
				|| (islower(board[i][x]) && isupper(cell))) {
			if (board[i][x] == 'r' || board[i][x] == 'R' || board[i][x] == 'Q'
					|| board[i][x] == 'q')
				return false;
			else
				break;
		} else if ((islower(board[i][x]) && islower(cell))
				|| (isupper(board[i][x]) && isupper(cell))) {
			break;
		}
	for (i = y - 1; i >= 0; i--)
		if ((isupper(board[i][x]) && islower(cell))
				|| (islower(board[i][x]) && isupper(cell))) {
			if (board[i][x] == 'r' || board[i][x] == 'R' || board[i][x] == 'Q'
					|| board[i][x] == 'q')
				return false;
			else
				break;
		} else if ((islower(board[i][x]) && islower(cell))
				|| (isupper(board[i][x]) && isupper(cell))) {
			break;
		}
	j = x, i = y, j++, i--;
	while (j != 8 && i >= 0) {
		if ((isupper(board[i][j]) && islower(board[y][x]))
				|| (islower(board[i][j]) && isupper(board[y][x]))) {
			if (board[i][j] == 'b' || board[i][j] == 'B' || board[i][j] == 'q'
					|| board[i][j] == 'Q'
					|| (cell == 'k' && board[i][j] == 'P' && i + 1 == y))
				return false;
			else
				break;

		} else if ((islower(board[i][j]) && islower(cell))
				|| (isupper(board[i][j]) && isupper(cell)))
			break;
		i--, j++;
	}
	j = x, i = y, j++, i++;
	while (j != 8 && i != 8) {
		if ((isupper(board[i][j]) && islower(board[y][x]))
				|| (islower(board[i][j]) && isupper(board[y][x]))) {
			if (board[i][j] == 'b' || board[i][j] == 'B' || board[i][j] == 'q'
					|| board[i][j] == 'Q'
					|| (cell == 'K' && board[i][j] == 'p' && i - 1 == y))
				return false;
			else
				break;

		} else if ((islower(board[i][j]) && islower(cell))
				|| (isupper(board[i][j]) && isupper(cell)))
			break;
		i++, j++;
	}
	j = x, i = y, j--, i--;
	while (j >= 0 && i >= 0) {
		if ((isupper(board[i][j]) && islower(board[y][x]))
				|| (islower(board[i][j]) && isupper(board[y][x]))) {
			if (board[i][j] == 'b' || board[i][j] == 'B' || board[i][j] == 'q'
					|| board[i][j] == 'Q'
					|| (cell == 'k' && board[i][j] == 'P' && i + 1 == y))
				return false;
			else
				break;

		} else if ((islower(board[i][j]) && islower(cell))
				|| (isupper(board[i][j]) && isupper(cell)))
			break;
		i--, j--;
	}
	j = x, i = y, j--, i++;
	while (j >= 0 && i != 8) {
		if ((isupper(board[i][j]) && islower(board[y][x]))
				|| (islower(board[i][j]) && isupper(board[y][x]))) {
			if (board[i][j] == 'b' || board[i][j] == 'B' || board[i][j] == 'q'
					|| board[i][j] == 'Q'
					|| (cell == 'K' && board[i][j] == 'p' && i - 1 == y))
				return false;
			else
				break;

		} else if ((islower(board[i][j]) && islower(cell))
				|| (isupper(board[i][j]) && isupper(cell)))
			break;
		i++, j--;
	}
	int dx[] = { 2, 2, -2, -2, 1, -1, 1, -1 };
	int dy[] = { 1, -1, 1, -1, 2, 2, -2, -2 };
	for (i = 0; i < 8; i++) {
		if ((board[y + dy[i]][x + dx[i]] == 'n' && isupper(board[y][x]))
				|| (board[y + dy[i]][x + dx[i]] == 'N' && islower(board[y][x])))
			return false;
	}
	return true;
}

bool checkMoveV2(bool turn)         //TRUE IF ALL IS GOOD
{
	bool returning = false, flag = true;
	int col = input[0] - 'A';
	int row = input[1] - '1';
	char temp = board[input[3] - '1'][input[2] - 'A'], y = turn ? wky : bky, x =
			turn ? wkx : bkx;
	switch (board[row][col]) {
	case 'P':
	case 'p':
		if (pawns()) {
			doMove(false);
			flag = false;
			if (checkCell(turn))
				returning = true;
		}
		break;
	case 'R':
	case 'r':
		if (rook()) {
			doMove(false);
			flag = false;
			if (checkCell(turn))
				returning = true;
		}
		break;
	case 'N':
	case 'n':
		if (knight()) {
			doMove(false);
			flag = false;
			if (checkCell(turn))
				returning = true;
		}
		break;
	case 'B':
	case 'b':
		if (bishop()) {
			doMove(false);
			flag = false;
			if (checkCell(turn))
				returning = true;
		}
		break;
	case 'Q':
	case 'q':
		if (queen()) {
			doMove(false);
			flag = false;
			if (checkCell(turn))
				returning = true;
		}
		break;
	case 'K':
	case 'k':
		if (king()) {
			doMove(false);
			flag = false;
			if (checkCell(turn))
				returning = true;
			if (turn) {
				wky = y, wkx = x;
			} else {
				bky = y, bkx = x;
			}
		}
		break;
	default:
		return false;
	}
	if (!flag) {
		board[input[1] - '1'][input[0] - 'A'] = board[input[3] - '1'][input[2]
				- 'A'];
		board[input[3] - '1'][input[2] - 'A'] = temp;

	}
	return returning;
}
bool checkmate(bool turn) {
	int i, j, k, l;
	char inputV2[4];
	for (i = 0; i < 4; i++)
		inputV2[i] = input[i];
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			input[0] = j + 'A';
			input[1] = i + '1';
			if ((!turn && islower(board[i][j]))
					|| (turn && isupper(board[i][j]))) {
				for (k = 0; k < 8; k++) {
					for (l = 0; l < 8; l++) {
						if ((!turn && !islower(board[k][l]))
								|| (turn && !isupper(board[k][l]))) {
							input[2] = l + 'A';
							input[3] = k + '1';
							if (input[0] == input[2] && input[1] == input[3])
								continue;
							if (checkMoveV2(!turn)) {
								for (i = 0; i < 4; i++)
									input[i] = inputV2[i];
								return false;			//no checkmate
							}
						} else
							continue;
					}
				}
			} else
				continue;
		}
	}
	for (i = 0; i < 4; i++)
		input[i] = inputV2[i];
	return true;				//checkmate
}
void printing(bool turn) {
	int k;
	printf("    ");
	for (i = 0; i < 8; i++)
		printf(" %c  ", indexL[i]);
	printf("\t\tLast move: %c%c%c%c%c\n", input[0],
			input[1] == '\0' ? ' ' : '9' - input[1] + '0', input[2],
			input[3] == '\0' ? ' ' : '9' - input[3] + '0',
			input[4] == '\0' ? ' ' : input[4]);
	for (i = 0; i < 8; i++) {
		printf("    ===============================\n");
		printf("%c  |", indexN[7 - i]);
		for (j = 0; j < 8; j++) {
			j < 7 ? printf(" %c |", board[i][j]) : printf(" %c |  %c%c",
							board[i][j], indexN[7 - i],
							i == 7 || i == 0 ? ' ' : '\n');
		}
		if (i == 0) {
			printf("\t%s Losses : ", player2);
			for (k = 0; k < eaten2Index; k++)
				k < eaten2Index - 1 ?
						printf("%c, ", eaten2[k]) : printf("%c", eaten2[k]);
			printf("\n");
		}
	}
	printf("\t%s Losses : ", player1);
	for (i = 0; i < eaten1Index; i++)
		i < eaten1Index - 1 ?
				printf("%c, ", eaten1[i]) : printf("%c", eaten1[i]);
	printf("\n    ===============================\n");
	printf("    ");
	for (i = 0; i < 8; i++)
		i < 7 ? printf(" %c  ", indexL[i]) : printf(" %c  \n", indexL[i]);
}
void colors() {
	bool flag = false;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++)
			refBoard[i][j] = (flag ? '.' : '-'), flag = !flag;
		flag = !flag;
	}
}
void doMove(bool flag) {
	int x1, y1, x2, y2;
	y1 = input[1] - '1', x1 = input[0] - 'A';
	x2 = input[2] - 'A', y2 = input[3] - '1';
	char temp = board[y2][x2];
	if (islower(board[y1][x1]) && !islower(board[y2][x2])
			&& board[y2][x2] != 'K') {
		if (board[y1][x1] == 'k')
			wky = y2, wkx = x2;
		if (isupper(board[y2][x2]) && flag)
			eaten2[eaten2Index] = board[y2][x2], eaten2Index++;
		if (flag)
			saveMove(), maxMoves = maxMoves > lastMove ? maxMoves : lastMove;
		board[y2][x2] = board[y1][x1];
		board[y1][x1] = refBoard[y1][x1];
	} else if (isupper(board[y1][x1]) && !isupper(board[y2][x2])
			&& board[y2][x2] != 'k') {
		if (board[y1][x1] == 'K')
			bky = y2, bkx = x2;
		if (islower(board[y2][x2]) && flag)
			eaten1[eaten1Index] = board[y2][x2], eaten1Index++;
		if (flag)
			saveMove();
		board[y2][x2] = board[y1][x1];
		board[y1][x1] = refBoard[y1][x1];
	} else {
		printf("WRONG MOVE! Please enter a valid one: ");
		scan(turn);
	}
	if (flag)
		promotion();
	if (flag)
		if (!checkCell(turn)) {
			board[y1][x1] = board[y2][x2];
			board[y2][x2] = temp;
			printf("LONG LIVE THE KING! Please enter a valid move: ");
			scan(turn);
		}
}

void checkMove() {
	int col = input[0] - 'A';
	int row = input[1] - '1';
	switch (board[row][col]) {
	case 'P':
	case 'p':
		if (pawns())
			doMove(true);
		else {
			printf("WRONG MOVE! Please enter a valid one: ");
			scan(turn);
		}
		break;
	case 'R':
	case 'r':
		if (rook())
			doMove(true);
		else {
			printf("WRONG MOVE! Please enter a valid one: ");
			scan(turn);
		}
		break;
	case 'N':
	case 'n':
		if (knight())
			doMove(true);
		else {
			printf("WRONG MOVE! Please enter a valid one: ");
			scan(turn);
		}
		break;
	case 'B':
	case 'b':
		if (bishop())
			doMove(true);
		else {
			printf("WRONG MOVE! Please enter a valid one: ");
			scan(turn);
		}
		break;
	case 'Q':
	case 'q':
		if (queen())
			doMove(true);
		else {
			printf("WRONG MOVE! Please enter a valid one: ");
			scan(turn);
		}
		break;
	case 'K':
	case 'k':
		if (king())
			doMove(true);
		else {
			printf("WRONG MOVE! Please enter a valid one: ");
			scan(turn);
		}
		break;
	default:
		printf("WRONG MOVE! Please enter a valid one: ");
		scan(turn);
	}
}

bool rook() {
	int dx, dy;
	if ((input[0] == input[2] && input[1] != input[3])
			|| (input[0] != input[2] && input[1] == input[3])) {
		dx = input[0] - input[2];
		dy = input[1] - input[3];
		if (dx > 0) {
			for (i = input[0] - 'A' - 1; i > input[2] - 'A'; --i) {
				if (board[input[1] - '1'][i] == '-'
						|| board[input[1] - '1'][i] == '.')
					continue;
				else {
					return false;
				}
			}
		} else if (dx < 0) {
			for (i = input[0] - 'A' + 1; i < input[2] - 'A'; ++i) {
				if (board[input[1] - '1'][i] == '-'
						|| board[input[1] - '1'][i] == '.')
					continue;
				else {
					return false;
				}
			}
		} else if (dy > 0) {
			for (i = input[1] - '1' - 1; i > input[3] - '1'; --i) {
				if (board[i][input[0] - 'A'] == '-'
						|| board[i][input[0] - 'A'] == '.')
					continue;
				else {
					return false;
				}
			}
		} else if (dy < 0)
			for (i = input[1] - '1' + 1; i < input[3] - '1'; ++i) {
				if (board[i][input[0] - 'A'] == '-'
						|| board[i][input[0] - 'A'] == '.')
					continue;
				else {
					return false;
				}
			}
		return true;
	}
	return false;
}
bool bishop() {
	int dx, dy, j = input[0] - 'A', i = input[1] - '1';
	if ((abs(input[0] - input[2]) == abs(input[1] - input[3]))
			&& (input[0] != input[2]) && input[1] != input[3]) {
		dx = input[0] - input[2];
		dy = input[1] - input[3];
		if (dx < 0 && dy > 0) {
			j++, i--;
			while (j != input[2] - 'A') {
				if (board[i][j] == '-' || board[i][j] == '.') {
					i--, j++;
					continue;
				} else {
					return false;
				}
			}
		} else if (dx < 0 && dy < 0) {
			i++, j++;
			while (j != input[2] - 'A') {
				if (board[i][j] == '-' || board[i][j] == '.') {
					i++, j++;
					continue;
				} else {
					return false;
				}
			}
		} else if (dx > 0 && dy > 0) {
			i--, j--;
			while (j != input[2] - 'A') {
				if (board[i][j] == '-' || board[i][j] == '.') {
					i--, j--;
					continue;
				} else {
					return false;
				}
			}
		} else if (dx > 0 && dy < 0) {
			j--, i++;
			while (j != input[2] - 'A') {
				if (board[i][j] == '-' || board[i][j] == '.') {
					j--, i++;
					continue;
				} else {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
bool pawns() {
	int dx, dy;
	dx = input[0] - input[2];
	dy = input[1] - input[3];
	if ((input[1] == '7' && board[input[1] - '1'][input[0] - 'A'] == 'p'
			&& dy == 2 && dx == 0
			&& (board[input[3] - '1'][input[2] - 'A'] == '-'
					|| board[input[3] - '1'][input[2] - 'A'] == '.')
			&& (board[5][input[0] - 'A'] == '.'
					|| board[5][input[0] - 'A'] == '-'))
			|| (input[1] == '2' && board[input[1] - '1'][input[0] - 'A'] == 'P'
					&& dy == -2 && dx == 0
					&& (board[input[3] - '1'][input[2] - 'A'] == '-'
							|| board[input[3] - '1'][input[2] - 'A'] == '.')
					&& (board[2][input[0] - 'A'] == '.'
							|| board[2][input[0] - 'A'] == '-')))
		return true;
	else if (dx == 0 && dy == 1 && board[input[1] - '1'][input[0] - 'A'] == 'p'
			&& (board[input[3] - '1'][input[2] - 'A'] == '-'
					|| board[input[3] - '1'][input[2] - 'A'] == '.'))
		return true;
	else if (dx == 0 && dy == -1 && board[input[1] - '1'][input[0] - 'A'] == 'P'
			&& (board[input[3] - '1'][input[2] - 'A'] == '-'
					|| board[input[3] - '1'][input[2] - 'A'] == '.'))
		return true;
	else if ((dx == 1 || dx == -1) && dy == 1
			&& board[input[1] - '1'][input[0] - 'A'] == 'p'
			&& board[input[3] - '1'][input[2] - 'A'] != '-'
			&& board[input[3] - '1'][input[2] - 'A'] != '.'
			&& board[input[3] - '1'][input[2] - 'A'] != 'K')
		return true;
	else if ((dx == 1 || dx == -1) && dy == -1
			&& board[input[1] - '1'][input[0] - 'A'] == 'P'
			&& board[input[3] - '1'][input[2] - 'A'] != '-'
			&& board[input[3] - '1'][input[2] - 'A'] != '.'
			&& board[input[3] - '1'][input[2] - 'A'] != 'k')
		return true;

	return false;
}
bool knight() {
	if ((abs(input[0] - input[2]) == 2 && abs(input[1] - input[3]) == 1)
			|| (abs(input[0] - input[2]) == 1 && abs(input[1] - input[3]) == 2)) {
		return true;
	}
	return false;
}
bool queen() {
	if (rook() || bishop())
		return true;
	return false;
}
bool king() {
	if (abs(input[0] - input[2]) <= 1 && abs(input[1] - input[3]) <= 1)
		return true;
	return false;
}
void scan(bool turn) {
	bool flag;
	char temp;
	while (true) {

		flag = true;
		char a[100];
		gets(a);
		if (strlen(a) != 4 && strlen(a) != 5) {
			printf("WRONG Input! Please enter a valid one: ");
			continue;
		}
		if (strcmp(a, "exit") == 0 || strcmp(a, "EXIT") == 0) {
			printf(
					"Unsaved game will be lost\nAre You sure you want to exit Y\\N? ");
			scan_again: gets(a);
			if (strlen(a) != 1 && a[0] != 'Y' && a[0] != 'y' && a[0] != 'N'
					&& a[0] != 'n') {
				printf("WRONG Input! Please enter a valid one: ");
				goto scan_again;
			}
			if (a[0] == 'Y' || a[0] == 'y') {
				printf("Please come back later\n");
				sleep(1), exit(1);
			} else if (a[0] == 'N' || a[0] == 'n') {
				system("clear");
				printing(turn);
				turn == true ?
						printf("\n%s's turn: ", player1) :
						printf("\n%s's turn: ", player2);
				continue;
			}
		}
		if (strcmp(a, "undo") == 0 || strcmp(a, "UNDO") == 0) {
			if (lastMove <= 1) {
				printf("No more moves to be undone\n");
				turn == true ?
						printf("\n%s's turn: ", player1) :
						printf("\n%s's turn: ", player2);
				continue;
			}
			turn = !turn;
			system("clear");
			undo();
			turn = isupper(savedMoves[lastMove][4]) ? false : true;
			printing(turn);
			turn == true ?
					printf("\n%s's turn: ", player1) :
					printf("\n%s's turn: ", player2);
			break;
		}
		if (strcmp(a, "redo") == 0 || strcmp(a, "REDO") == 0) {
			if (savedMoves[lastMove][0] == '\0') {
				printf("No more moves to be redone\n");
				turn == true ?
						printf("\n%s's turn: ", player1) :
						printf("\n%s's turn: ", player2);
				continue;
			}
			turn = !turn;
			system("clear");
			redo();
			printing(turn);
			turn == true ?
					printf("\n%s's turn: ", player1) :
					printf("\n%s's turn: ", player2);
			break;
		}
		if (strcmp(a, "save") == 0 || strcmp(a, "SAVE") == 0) {
			save();
			printf("Game Saved.\n");
			continue;
		}
		if (strcmp(a, "LOAD") == 0 || strcmp(a, "load") == 0) {
			load();
			printf("Game loaded.\n");
			turn = !turn;
			break;
		}
		if (condition == 1 || condition == 3) {
			printf(
					"Game is over!\
                   - To Undo enter UNDO\
                   - To save the game enter S\
                   - To get to the Main menu just enter M\
                   - To Exit the game enter X\
                   Your Choice : ");
			continue;
		}
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 8; j++) {
				temp = (i == 0 || i == 2 ? indexL[j] : indexN[j]);
				if (a[i] == temp)
					break;
				else if (j < 7)
					continue;
				else {
					flag = false;
					break;
				}
				if (!flag)
					break;
			}
		}
		if (!flag) {
			printf("WRONG MOVE! Please enter a valid one: ");
			continue;
		}
		a[1] = '8' - a[1] + '1';
		a[3] = '8' - a[3] + '1';
		for (i = 0; i < 4; i++)
			input[i] = a[i];
		if ((input[3] == '1' && board[input[1] - '1'][input[0] - 'A'] == 'p'
				&& (a[4] == 'p' || a[4] == 'n' || a[4] == 'r' || a[4] == 'b'
						|| a[4] == 'q'))
				|| (input[3] == '8'
						&& board[input[1] - '1'][input[0] - 'A'] == 'P'
						&& (a[4] == 'P' || a[4] == 'N' || a[4] == 'R'
								|| a[4] == 'B' || a[4] == 'Q')))
			input[4] = a[4];

		else if (strlen(a) == 5) {
			printf("WRONG Input! Please enter a valid one: ");
			continue;
		}
		if ((turn && islower(board[input[1] - '1'][input[0] - 'A']))
				|| (!turn && isupper(board[input[1] - '1'][input[0] - 'A']))) {
			checkMove();
		} else if ((turn && !isalpha(board[input[1] - '1'][input[0] - 'A']))
				|| (!turn && !isalpha(board[input[1] - '1'][input[0] - 'A']))) {
			printf("This cell is empty! Please enter a valid move: ");
			continue;
		} else {
			printf(
					"You can only move your pieces! Please enter a valid move: ");
			continue;
		}

		break;
	}
}

void defaultB() {
	bool flag = false;
	for (i = 2; i < 6; i++) {
		for (j = 0; j < 8; j++) {
			board[i][j] = (flag ? '.' : '-');
			flag = !flag;
		}
		flag = !flag;
	}
	for (i = 0; i < 8; i++) {
		board[1][i] = 'P';
		board[6][i] = 'p';
	}
	board[0][0] = board[0][7] = 'R', board[0][1] = board[0][6] = 'N', board[0][2] =
			board[0][5] = 'B', board[0][3] = 'Q', board[0][4] = 'K';
	board[7][0] = board[7][7] = 'r', board[7][1] = board[7][6] = 'n', board[7][2] =
			board[7][5] = 'b', board[7][3] = 'q', board[7][4] = 'k';
}
bool mainMenu() {
	char option[50];
//clears the screen
	system("clear");        //For UNIX-based OSes
	puts(
			"===============================                  ===============================\n"
					"=============================== WELCOME TO CHESS ===============================\n"
					"=============================== ---------------- ===============================\n");
//clears the keyboard buffer
	fflush(stdin);
//Outputs the options to console
	puts(
			"\n[1] New Game\n[2] Load Game\n[3] Instructions\n[4] About\n..........\n[x]Exit\n");
//Reads the user's option
	again: gets(option);
	if (strlen(option) != 1) {
		printf("Not a valid option! Please enter a valid one: ");
		goto again;
	}
//Selects the course of action specified by the option
	switch (option[0]) {
	case '1':
		system("clear");
		printf("Player 1's name (White): ");
		gets(player1);
		printf("Player 2's name (Black): ");
		gets(player2);
		system("clear");
		return false;
	case '2':
		system("clear");
		load();
		puts("Game Loaded.");
		sleep(1);
		return false;
		break;
	case '3':
		printf("\t\tGame Instructions.\n\n"
				"1- All the moves must be upper case e.g \"A2A4\".\n"
				"2- All the characters of any order must be the same case.\n"
				"3- To undo a move just enter undo.\n"
				"4- To save the game at any time just enter save.\n"
				"4- To load the saved game at any time just enter load.\n"
				"5- To exit the game at any time just enter exit.\n"
				"\nPress enter to continue.\n");
		getchar();
		mainMenu();
		break;
	case '4':
		printf(
				"\t\t About\n\n"
						"- This project was made as an assignment.\n"
						"- Made by Mahmoud Mohammed Hussein & Hesham Ibrahim El-Sawaf.\n"
						"- All rights reserved.\n"
						"\nPress enter to continue.\n");
		getchar();
		mainMenu();
		break;
	case 'x':
		printf("Please come again :)\n");
		sleep(1);
		exit(1);
	default:
		printf("Not a valid option! Please enter a valid one: ");
		goto again;
	}
}
void promotion() {
	if ((input[3] == '8' && board[input[3] - '1'][input[2] - 'A'] == 'P')
			|| (input[3] == '1' && board[input[3] - '1'][input[2] - 'A'] == 'p'))
		if (input[4] != '\0')
			board[input[3] - '1'][input[2] - 'A'] = input[4];
}
void saveMove() {
	savedMoves[lastMove][0] = input[0];
	savedMoves[lastMove][1] = input[1];
	savedMoves[lastMove][2] = input[2];
	savedMoves[lastMove][3] = input[3];
	savedMoves[lastMove][4] = board[input[1] - '1'][input[0] - 'A'];
	savedMoves[lastMove][5] = board[input[3] - '1'][input[2] - 'A'];
	savedMoves[lastMove][6] = input[5];
	lastMove++;
}
void undo() {
	lastMove--;
	input[0] = savedMoves[lastMove - 1][0];
	input[1] = savedMoves[lastMove - 1][1];
	input[2] = savedMoves[lastMove - 1][2];
	input[3] = savedMoves[lastMove - 1][3];
	board[savedMoves[lastMove][1] - '1'][savedMoves[lastMove][0] - 'A'] =
			savedMoves[lastMove][4];
	board[savedMoves[lastMove][3] - '1'][savedMoves[lastMove][2] - 'A'] =
			savedMoves[lastMove][5];
	if (isalpha(savedMoves[lastMove][5])) {
		if (isupper(savedMoves[lastMove][5]))
			eaten2[--eaten2Index] = '\0';
		else
			eaten1[--eaten1Index] = '\0';
	}
}
void redo() {
	input[0] = savedMoves[lastMove][0];
	input[1] = savedMoves[lastMove][1];
	input[2] = savedMoves[lastMove][2];
	input[3] = savedMoves[lastMove][3];
	input[5] = savedMoves[lastMove][6];
	checkMove();
}
void save() {
	int i = 0;
	FILE* ptr;
	if ((ptr = fopen("savedGames.txt", "w")) == NULL) {
		printf("Error saving game!");
		return;
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++)
			fprintf(ptr, "%c", board[i][j]);
		fprintf(ptr, "\n");
	}
	fprintf(ptr, "\n%s\n\n%s\n\n%d\n\n%d\n", player1, player2, turn, maxMoves);
	for (i = 0; i <= maxMoves; i++) {
		for (j = 0; j < 6; j++)
			fprintf(ptr, "%c", savedMoves[i][j]);
	}
	fprintf(ptr, "\n\n%d\n\n%d %d\n\n%d %d\n\n%d\n%s\n\n%d\n%s\n\n%d\n\n%s",
			lastMove, wkx, wky, bkx, bky, eaten1Index, eaten1, eaten2Index,
			eaten2, condition, input);
	fclose(ptr);
}
void load() {
	int i;
	FILE* ptr;
	if ((ptr = fopen("savedGames.txt", "r")) == NULL) {
		printf("Sorry! No previous saved games");
		return;
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++)
			fscanf(ptr, "%c", &board[i][j]);
		fgetc(ptr);
	}
	fscanf(ptr, "\n%s\n\n%s\n\n%d\n\n%d\n", player1, player2, &turn, &maxMoves);
	for (i = 0; i <= maxMoves; i++) {
		for (j = 0; j < 6; j++)
			fscanf(ptr, "%c", &savedMoves[i][j]);
	}
	fscanf(ptr, "\n\n%d\n\n%d %d\n\n%d %d\n\n%d\n%s\n\n%d\n%s\n\n%d\n\n%s",
			&lastMove, &wkx, &wky, &bkx, &bky, &eaten1Index, eaten1,
			&eaten2Index, eaten2, &condition, input);
	fclose(ptr);
}
