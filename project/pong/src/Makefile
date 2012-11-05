#
# Makefile for pong
# so jenkins can build this LINUX ONLY


CPP= g++
SDL_LIB = -I /SDL/include/
CPPFLAGS = -O0 -g3 -Wall
OBJS = Entity.o Ball.o button.o game.o menu.o Singleplayer.o util.o

all: $(OBJS)

Entity.o:	Entity.cpp Entity.h
	$(CPP) $(CPPFLAGS) -c -o Entity.o Entity.cpp

Ball.o:	Ball.cpp Ball.h
	$(CPP) $(CPPFLAGS) -c -o Ball.o Ball.cpp

button.o:	button.cpp button.h
	$(CPP) $(CPPFLAGS) -c -o button.o button.cpp	

game.o:	game.cpp game.h
	$(CPP) $(CPPFLAGS) -c -o game.o game.cpp
	
menu.o:	menu.cpp menu.h
	$(CPP) $(CPPFLAGS) -c -o menu.o menu.cpp

Singleplayer.o:	Singleplayer.cpp Singleplayer.h
	$(CPP) $(CPPFLAGS) -c -o Singleplayer.o Singleplayer.cpp
	
util.o:	util.cpp util.h
	$(CPP) $(CPPFLAGS) -c -o util.o util.cpp
	
clean:
	rm -rf $(OBJS)