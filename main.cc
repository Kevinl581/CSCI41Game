
#include<ncurses.h>
#include<iostream>
#include<ctime>
#include<cmath>
#include"bombrush.h"
#include"timer.h"
#include<unordered_map>
using namespace std;
bool wall[100][100];
bool bomb[100][100];
void printBombs();
bool defuse(Bomb a);
void ulose();
void highScore(int a);
const unsigned char main_char = 'P';
const unsigned char BOMB = 'B';

void printWalls() { //Makes a maze within the walls.
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 10; j++) {
			int xcord = rand() % 74 + 1;
			int ycord = rand() % 19 + 1;
			if (wall[ycord][xcord] == false) { //Checks if there is no wall in the cordinates.
				attron(COLOR_PAIR(5));
				mvaddch(ycord, xcord, '#');//Sets that cordinate
				attroff(COLOR_PAIR(5));
				wall[ycord][xcord] = true;//Sets the wall at that cordinate to true.
			}
		}
	}
}


void printWorld() {
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++) {
			if (i == 0) {
				if (j < 76) {
					attron(COLOR_PAIR(4));
					mvaddch(i, j, '_');
					attroff(COLOR_PAIR(4));
					wall[i][j] = true;
				}
			}
			if (i == 20) {
				if (j < 76) {
					attron(COLOR_PAIR(4));
					mvaddch(i, j, '_');
					attroff(COLOR_PAIR(4));
					wall[i + 1][j] = true;
				}
			}

			if (j == 0 || j == 75) {
				if (i < 21 && i > 0) {
					attron(COLOR_PAIR(4));
					mvaddch(i, j, '|');
					attroff(COLOR_PAIR(4));
					wall[i][j] = true;
				}
			}
		}
	printWalls();
	printBombs();
}
void printBombs() {
	while (true) {
		int a = rand() % 20;
		int b = rand() % 70;
		if (wall[a][b] != true) {
			bomb[a][b] = true;
			attron(COLOR_PAIR(2));
			mvaddch(a, b, BOMB);
			attroff(COLOR_PAIR(2));
			return;
		}
	}
}
void quit() {

	mvprintw(22, 0, "Are you sure you want to quit? Yes(Y) or No(N)");
	char ch = getch();
	if (ch == 'Y' || ch == 'y') {
		system("clear");
		printf("Thank you for playing.\n");
		wait(1); // Waits 1 second.
		endwin();
		exit(0);
	} else {
		mvprintw(22, 0, "                                                   ");
		return;
	}
}

void init() {
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
}
void erase(int y, int x) {
	if (wall[y] == wall[20]) {
		attron(COLOR_PAIR(4));
		mvaddch(y, x, '_');
		attroff(COLOR_PAIR(4));

	} else mvaddch(y, x, ' ');
}
int gameLoop(int row, int col, char ch) {
	printWorld();
    refresh();
    char main_char=ch;
	int point = 0;

	for (;;) {
		mvprintw(21, 55, "Points: %i", point);


		// Show the main character on the screen
		attron(COLOR_PAIR(1));
		mvaddch(row, col, main_char);
		attroff(COLOR_PAIR(1));
        int ch = getch();

		if (ch == KEY_LEFT) {
			erase(row, col);
			col = col - 1;
			refresh();
		} else if (ch == KEY_RIGHT) {
			erase(row, col);
			col = col + 1;
			refresh();
		} else if (ch == KEY_UP) {
			erase(row, col);
			row = row - 1;
			refresh();
		} else if (ch == KEY_DOWN) {
			erase(row, col);
			row = row + 1;
			refresh();
		}
		if (bomb[row][col] == true) {
			Bomb a('h', rand() % 3 + 1);
			bomb[row][col] = false;
			if(defuse(a))break;
			point++;
			printBombs();
			//break;
		}
		if (wall[row][col] == true) {
			ulose(1);
			break;
		} else if (ch == 'q' || ch == 'Q') {
			quit();
			refresh();
		}
	}
	return point;
}
int main() {
	//define main character symbol and initial position
	int y = 2, x = 2;
	//char player = 'P';
	srand(time(NULL));
	//printWorld();
	//start ncurses
	priority_queue<int> highScores;
    unordered_map<int,char> players;
	while (1) {
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++) {
				wall[i][j] = 0;
				bomb[i][j] = 0;
			}
		init();
		printw("Proceed to each bomb and defuse. Avoid all obstacles.\n");
		printw("For bomb type A cut RED wire. For bomb type B cut BLUE wire. For bomb type C cut GREEN wire.\n");
		printw("Press Q anytime to quit.\n");
	//	printw("Press any key to continue.\n");
        printw("Type your first initial to continue, 'q' to quit \n");

		start_color();
		init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(2, COLOR_RED, COLOR_BLACK);
		init_pair(3, COLOR_WHITE, COLOR_BLACK);
		init_pair(4, COLOR_YELLOW, COLOR_BLACK);
		init_pair(5, COLOR_CYAN, COLOR_BLACK);
		char input = getch();
		if (input == 'q' || input == 'Q') {
			quit();
		}
		clear();
		int score = gameLoop(y, x, input);
		highScores.push(score);
        players[score]=input;
		highScore(highScores.top());
        printPlayerName(players[score]);
		// wall[100][100]={0};
		// bomb[100][100]={0};
		//highScores.pop();
		endwin();
		system("clear");
	}
	return 0;
}
