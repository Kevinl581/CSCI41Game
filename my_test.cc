#include<ncurses.h>
#include<iostream>
#include<ctime>
#include<cmath>
#include"bombrush.h"
using namespace std;
bool wall[100][100];
void ulose(){
    
}


class Bomb{
	public:
		int bombType;
		char bombLet;
	
 		Bomb(int x, char c) {
			bombType = x;
			bombLet = c;
			}


};


// TEST BOMB INITIALIZATION
Bomb alpha(1, 'b');
//
void defuse(Bomb in) {
	//clear line 12, 76 -- feedback line
	mvprintw(12,76," ");
	// bombs need type and letter for defusal. letter will be shown to player. from letter, players must guess the type.
	int dfuseType;
	// Display bomb color to player
	char bombDisplay = in.bombLet;
	mvprintw(10,76, "The bomb is ");
	mvprintw(10,88, "?");
	mvprintw(11,76, "Input number of wire to cut, 1 for RED, 2 for BLUE, 3 for GREEN.");
	// receive defuse type input
	cin >> dfuseType;
	if (dfuseType != (1 || 2 || 3)) {
			mvprintw(12,76, "Incorrect input.");
			defuse(in);
			}
	// if defuse type does not match bomb type, game over
	if (dfuseType != in.bombType){ ulose();}

	// else defuse bomb i.e. remove bomb character, iterate all other bombs down, adjust timer, and add 1 more bomb 
};


void printWorld(){
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++){
            if(i==0||i==20){
                if(j<76){
                mvaddch(i, j, '_');
                wall[i][j]=true;
            }}
            if(j==0||j==75){
                if(i<21&&i>0){
                mvaddch(i, j, '|');
                wall[i][j]=true;
                }
            }
}
}
void init(){
initscr();
   clear();
       noecho();
       cbreak();
       keypad(stdscr, TRUE);
       curs_set(0); }   
void erase(int y, int x){
mvaddch(y, x, ' ');
}
void gameLoop(char main_char, int row, int col, int ch){
    if(ch == 'q' || ch =='Q') return;
        printWorld(); 
             // Show the main character on the screen
            mvaddch(row, col, main_char);
         refresh();
     
           for(;;) {
                  ch = getch();
            
                      if(ch == KEY_LEFT) {
                              erase(row, col);
                              col = col - 1;
                              mvaddch(row, col, main_char);
                              refresh();
                          }
                  else if(ch == KEY_RIGHT) {
                          erase(row, col);
                          col = col + 1;
                          mvaddch(row, col, main_char);
                          refresh();
                      }
                 else if(ch == KEY_UP) {
                          erase(row, col);
                         row = row - 1;
                          mvaddch(row, col, main_char);
                          refresh();
                      }
                  else if(ch == KEY_DOWN) {
                          erase(row, col);
                          row = row + 1;
                          mvaddch(row, col, main_char);
                          refresh();
                      }
                  if(wall[row][col]==true)
                  {
                      break;
                  }
                  else if(ch == 'q' || ch == 'Q') {
                          break;
            }
        }
}
int main(){
    //define main character symbol and initial position
    int y = 2, x = 2;
    char player = 'P';
    printWorld();
    //start ncurses
    init();
    int input=getch();
    clear();
    gameLoop(player, y, x, input);
    endwin();
    system("clear");
    return 0;
}
