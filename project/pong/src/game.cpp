/*
 * game.cpp
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#include "game.h"
#include "SDL/SDL.h"
#include "util.h"
#include <iostream>

Game::Game() {

	setState(INIT);

	if( !this->init() ) {
		std::cerr << "Something exploded" << std::endl;

	}

}

Game::~Game() {

	//Free the surface
	SDL_FreeSurface(screen);
	SDL_FreeSurface(background);

	//Quit SDL
	SDL_Quit();

}

bool Game::init() {

	//Initialize all SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}

	//Set up the screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, BIT_DEPTH,
			SDL_SWSURFACE);

	//If there was an error in setting up the screen
	if (screen == NULL) {
		return false;
	}

	//Set the window caption
	SDL_WM_SetCaption("Pong", NULL);


	// Load background image

	std::cout << screen << endl;

	background = load_image( "images/background.png") ;

	apply_surface( 0, 0, background, screen );

	gamemenu.addButton( 170, 120, 320, 240, "button.png");


	//If everything initialized fine

	setState(MENU);

	return true;

}

void Game::run() {

	while (getState() != QUIT) {

		switch (getState()) {

		case MENU:

			displayMenu();

			break;

		case QUIT:
			break;

		}

	}

}

void Game::displayMenu() {

	SDL_Event event;

	//While there's an event to handle
	while (SDL_PollEvent(&event)) {

		//If the user has Xed out the window
		if (event.type == SDL_QUIT) {
			//Quit the program
			setState(QUIT);
		}

		gamemenu.update( &event);
		gamemenu.draw( screen) ;


		//Update the screen
		if (SDL_Flip(screen) == -1) {
			return;
		}

	}

}

int Game::getState() {

	return this->state;

}

void Game::setState(int state) {

	this->state = state;
}


