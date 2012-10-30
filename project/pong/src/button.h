/*
 * button.h
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "SDL/SDL.h"
#include <string>

enum BUTTON_STATES {

	MOUSE_OVER, MOUSE_OUT, MOUSE_DOWN, MOUSE_UP

};

class button {

public:

	button(int x, int y, int w, int h, std::string i);

	void update(SDL_Event* event);
	void draw(SDL_Surface* screen);

private:

	// Bounding box of the button
	SDL_Rect box;

	// Current clip of the button

	SDL_Rect* frame;

	// Button image

	SDL_Surface* image;

};

#endif /* BUTTON_H_ */
