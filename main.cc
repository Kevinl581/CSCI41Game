#include<ncurses.h>
#include<iostream>
#include<ctime>
#include<cmath>
#include"into.h"
using namespace std;

int main(){
    initscr();
    start_color();
    clear();
    noecho();
    cbreak();
    into();
}
