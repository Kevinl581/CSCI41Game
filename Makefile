a.out: main.cc bombrush.h  raine.cc
	g++ -std=c++11 main.cc -lncurses
clean:
	rm a.out
