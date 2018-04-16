
#include<ncurses.h>
#include<iostream>
#include<ctime>
#include<cmath>
#include"bombrush.h"
#include"timer.h"
using namespace std;
bool wall[100][100];
bool bomb[100][100];
void printBombs();
void defuse(Bomb a);
void ulose();

const unsigned char main_char = 'P';
const unsigned char BOMB = 'B';

void printWalls(){//Makes a maze within the walls.
	for(int i=1; i<20; i++){
		for(int j=1; j<10; j++){
			int xcord = rand()%74+1;
			int ycord = rand()%19+1;
	    	if(wall[ycord][xcord] == false){//Checks if there is no wall in the cordinates.
				mvaddch(ycord, xcord, '#');//Sets that cordinate 
				wall[ycord][xcord] = true;//Sets the wall at that cordinate to true.
			}
		}
	}
}


void printWorld(){
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++){
            if(i==0){
                if(j<76){
                mvaddch(i, j, '_');
                wall[i][j]=true;
            }}
			 if(i==20){
			    if(j<76){
			    mvaddch(i, j, '_');
			    wall[i+1][j]=true;
			 }}
			 
            if(j==0||j==75){
                if(i<21&&i>0){
                mvaddch(i, j, '|');
                wall[i][j]=true;
                }
			}
		}
	printWalls();
    printBombs();
}
void printBombs(){
  while(true){
   int a=rand()%20;
   int b=rand()%70;
   if(wall[a][b]!=true){
       bomb[a][b]=true;
	   attron(COLOR_PAIR(2));
       mvaddch(a, b, BOMB);
	   attroff(COLOR_PAIR(2));
       return; 
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
	if(wall[y] == wall[20]) mvaddch(y, x, '_');
	else mvaddch(y, x, ' ');
}
void gameLoop(int row, int col, int ch){
    if(ch == 'q' || ch =='Q') return;
        printWorld(); 
             // Show the main character on the screen
            attron(COLOR_PAIR(1));
			mvaddch(row, col, main_char);
			attroff(COLOR_PAIR(1));
         refresh();

		 int point = 0;
  		
         for(;;) {
			 	mvprintw(21, 55,"Points: %d", point);
                  ch = getch();
           			 
                      if(ch == KEY_LEFT) {
                              erase(row, col);
                              col = col - 1;
                              attron(COLOR_PAIR(1));
							  mvaddch(row, col, main_char);
                              attroff(COLOR_PAIR(1));
							  refresh();
                          }
                  else if(ch == KEY_RIGHT) {
                          erase(row, col);
                          col = col + 1;
                          attron(COLOR_PAIR(1));
						  mvaddch(row, col, main_char);
                          attroff(COLOR_PAIR(1));
						  refresh();
                      }
                 else if(ch == KEY_UP) {
                          erase(row, col);
                         row = row - 1;
                         attron(COLOR_PAIR(1)); 
						 mvaddch(row, col, main_char);
                         attroff(COLOR_PAIR(1));
						 refresh();
                      }
                  else if(ch == KEY_DOWN) {
                          erase(row, col);
                          row = row + 1;
                          attron(COLOR_PAIR(1));
						  mvaddch(row, col, main_char);
						  attroff(COLOR_PAIR(1));
                          refresh();
                      }
                  if(bomb[row][col]==true)
                  {
					  Bomb a('h',rand()%3+1);
                      bomb[row][col]=false;
                      defuse(a);
					  point++;
					  printBombs();
                     
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
    //char player = 'P';
	srand(time(NULL));
    //printWorld();
    //start ncurses
    init();
	start_color();
	init_pair(1,COLOR_MAGENTA,COLOR_BLACK);
	init_pair(2,COLOR_RED,COLOR_BLACK);
	init_pair(3,COLOR_WHITE,COLOR_BLACK);
    int input=getch();
    clear();
    gameLoop(y, x, input);
    endwin();
    system("clear");
    return 0;
}
