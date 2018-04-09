#include<ncurses.h>
#include<iostream>
#include<ctime>
#include<cmath>
#include"bombrush.h"
using namespace std;
void printWorld(){
}
void init(){
initscr();
   clear();
       noecho();
       cbreak();
       keypad(stdscr, TRUE);
       curs_set(0); }   
void erase(int y, int x){
    mvaddch(y, x, '#');
}
void gameLoop(char main_char, int row, int col, int ch){
    if(ch == 'q' || ch =='Q') return;
     
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
                  else if(ch == 'q' || ch == 'Q') {
                          break;
            }
        }
}
int main(){
    //define main character symbol and initial position
    int row = 10, col = 10;
    char mainChar = '@';

    //start ncurses
    init();
    int ch=getch();
    clear();
    gameLoop(mainChar, row, col, ch);

}
