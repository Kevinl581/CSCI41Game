#include<ncurses.h>
#include<iostream>
#include<unistd.h>
#include<queue>
#include<string>
#include<cstdlib>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class Bomb {
  private:
	char bombLet;
	int bombType;
  public:
	Bomb(char newLet, int newType) {
		bombLet = newLet;
		bombType = newType;
	}
	void setBombLet(char newLet) {
		bombLet = newLet;
	}
	void setBombType(int newType) {
		bombType = newType;
	}
	char getBombLet() {
		return bombLet;
	}
	int getBombType() {
		return bombType;
	}

};
int xdim, ydim; //world dimensions
const int MAX_SCORES = 10;
void ulose(int end) {
	clear();
	//cout << "Game Over.";
	mvprintw(10, 48, "Game Over.");
	mvprintw(12, 38, "Press any key to continue.");
	if (end == 1) {
		mvprintw(11, 38, "You hit a deadly obstacle!");
	}
	if (end == 2) {
		mvprintw(11, 38, "You cut the wrong wire! BOMB DETONATION.");
	}

	//refresh();
	getch();
	clear();
	//endwin();
	//system("clear");
	//exit(1);
}
bool defuse(Bomb in) {
	//clear line 12, 76 -- feedback line
	initscr();
	//clear();
	noecho();
	cbreak();


	mvprintw(12, 76, " ");
	// bombs need type and letter for defusal. letter will be shown to player. from letter, players must guess the type.
	char dfuseType;
	char bType = '0' + in.getBombType();

	// Display bomb color to player
	//  char bombDisplay = in.bombLet;
	mvprintw(10, 76, "The bomb is type");
	if (bType == '1') {
		mvprintw(10, 93, "A");
	}
	if (bType == '2') {
		mvprintw(10, 93, "B");
	}
	if (bType == '3') {
		mvprintw(10, 93, "C");
	}
	//mvprintw(10, 88, "?");
	mvprintw(11, 76, "Input number of wire to cut.");
	mvprintw(12, 76, "1 for RED, 2 for BLUE, 3 for GREEN.");
	refresh();
	// receive defuse type input
	dfuseType = getch();

	while (dfuseType != '1' && dfuseType != '2' && dfuseType != '3') {
		mvprintw(13, 76, "Incorrect input.");
		mvprintw(14, 76, "Enter 1, 2, or 3, like above.");
		//cin >> dfuseType;
		dfuseType = getch();
	}

	// if defuse type does not match bomb type, game over
	if (dfuseType != bType) {
		ulose(2);
		return 1;
		

	}

	// else defuse bomb i.e. remove bomb character, iterate all other bombs down, adjust timer, and add 1 more bomb
	//clear text if successful
	mvprintw(10, 76, "                     ");
	mvprintw(10, 93, "              ");
	mvprintw(11, 76, "                                   ");
	mvprintw(12, 76, "                                       ");
	mvprintw(13, 76, "                           ");
	mvprintw(14, 76, "                                   ");

	refresh();
	return 0;
}
void highScore(int a) {
	char c[10];
	sprintf(c, "%d", a);
	mvprintw(10, 20, "Current High Score is:");
	mvprintw(10, 45, c);
	refresh();
	timeout(3000);
	getch();
	timeout(-1);
    clear();
	return;
}
void printPlayerName(char a){
    const char *b=&a;
    mvprintw(10, 20, "Made by the player: ");
    mvprintw(10, 45, b);
    refresh();
    timeout(3000);
    getch();
    timeout(-1);
    }/*
class Heap
{
    private:
        int size = 0;
        int items[MAX_SCORES];

    public:

        int getLeftChildIndex(int parentIndex) {return 2 * parentIndex + 1;}
        int getRightChildIndex(int parentIndex) {return 2 * parentIndex +2;}
        int getParentIndex(int childIndex) {return (childIndex - 1) / 2;}

        bool hasLeftChild(int index) {return getLeftChildIndex(index) < size;}
        bool hasRightChild(int index) {return getRightChildIndex(index) < size;}
        bool hasParent(int index) {return getParentIndex(index) >= 0;}

        int leftChild(int index) {return items[getLeftChildIndex(index)];}
        int rightChild(int index) {return items[getRightChildIndex(index)];}
        int parent(int index) {return items[getParentIndex(index)];}

        void swap(int indexOne, int indexTwo)
        {
            int temp = items[indexOne];
            items[indexOne] = items[indexTwo];
            items[indexTwo] = temp;
        }

        void highScoreList()
        {
            if (size == 0) return;
            else
            {
                cout<<"Your high scores!!!\n";
                while(size > 0)
                {
                    int item = items[0];
                    items[0] = items[size - 1];
                    cout<<size<<". "<<item<<endl;
                    size--;
                    heapifyDown();
                }
            }
        }

        void add(int item)
        {
            if(size == MAX_SCORES) return;
            else{
                items[size] = item;
                size++;
                heapifyUp();
            }

        }

        void heapifyUp()
        {
            int index = size - 1;
            while (hasParent(index) && parent(index) > items[index])
            {
                swap(getParentIndex(index), index);
                index = getParentIndex(index);
            }
        }

        void heapifyDown()
        {
            int index = 0;
            while(hasLeftChild(index))
            {
                int smallerChildIndex = getLeftChildIndex(index);
                if(hasRightChild(index) && rightChild(index) < leftChild(index))
                {
                    smallerChildIndex = getRightChildIndex(index);
                }
            }

        }*/
//};

