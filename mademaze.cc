#include<ncurses.h>
#include<iostream>
#include<ctime>
#include<cmath>
#include"bombrush.h"
using namespace std;
bool wall[100][100];
void ulose(){
    
}

void printMaze(){//Makes a maze within the walls.
	srand(time(0));
	for(int i=1; i<19; i++){
		int xCord = rand()%74+1;//Generates a random number between 1-74.
	    int yCord = rand()%19+1;//Generates a number between 1-19
	    if(wall[xCord][yCord] == false){//Checks if there is no wall in the cordinates.
			mvaddch(yCord, xCord, '|');//Sets that cordinate 
			wall[yCord][xCord] = true;//Sets the wall at that cordinate to true.
		}
	}
	for(int j=1; j<74; j++){
 		int xCord = rand()%74+1;
    	int yCord = rand()%19+1;
		if(wall[xCord][yCord] == false)	
			mvaddch(yCord, xCord, '_');
			wall[yCord][xCord] = true;
		}
}

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
	printMaze();
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