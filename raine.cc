#pragma once
#include<ncurses.h>
#include"bombrush.h"
using namespace std;
bool bomb[100][100];
class Bomb{
    private:
        int x, y;
        char bombLet;
        int bombType;
    public:
      void setBombLet(char newLet){bombLet=newLet;}
      void setBombType(int newType){bombType=newType;}
      char getBombLet(){return bombLet;}
      int getBombType(){return bombType;}
      void setXY(int newX, int newY){
          x=newX;
          y=newY;}
      
};

