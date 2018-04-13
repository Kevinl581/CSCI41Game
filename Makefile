a.out: main.cc bombrush.h JH_test.cc raine.cc
	g++ -std=c++11 main.cc -lncurses
clean:
	rm a.out
