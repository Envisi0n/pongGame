/*
 * button.cpp
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#include "button.h"
#include "util.h"
#include <iostream>

// I KNOW TERRIBLE

SDL_Rect regions[4];

void setRegions() {

	regions[MOUSE_OVER].x = 0;
	regions[MOUSE_OVER].y = 0;
	regions[MOUSE_OVER].w = 320;
	regions[MOUSE_OVER].h = 240;

	regions[MOUSE_OUT].x = 320;
	regions[MOUSE_OUT].y = 0;
	regions[MOUSE_OUT].w = 320;
	regions[MOUSE_OUT].h = 240;

	regions[MOUSE_DOWN].x = 0;
	regions[MOUSE_DOWN].y = 240;
	regions[MOUSE_DOWN].w = 320;
	regions[MOUSE_DOWN].h = 240;

	regions[MOUSE_UP].x = 320;
	regions[MOUSE_UP].y = 240;
	regions[MOUSE_UP].w = 320;
	regions[MOUSE_UP].h = 240;

}

button::button(int x, int y, int w, int h, std::string i) {

	// Load image

	this->image = load_image(i);

	//Set the button's attributes
	box.x = x;
	box.y = y;
	box.w = w;
	box.h = h;

	//Set the default sprite

	frame = &regions[MOUSE_OUT];

}

void button::draw(SDL_Surface* screen) {

	//Show the button

	apply_surface(box.x, box.y, image, screen, frame);

}

void button::update(SDL_Event* event) {

	//The mouse offsets
	int x = 0, y = 0;

	//If the mouse moved
	if (event->type == SDL_MOUSEMOTION) {
		//Get the mouse offsets
		x = event->motion.x;
		y = event->motion.y;

		//If the mouse is over the button
		if ((x > box.x) && (x < box.x + box.w) && (y > box.y)
				&& (y < box.y + box.h)) {
			//Set the button sprite
			frame = &regions[MOUSE_OVER];
		}
		//If not
		else {
			//Set the button sprite
			frame = &regions[MOUSE_OUT];
		}
	}
	//If a mouse button was pressed
	if (event->type == SDL_MOUSEBUTTONDOWN) {
		//If the left mouse button was pressed
		if (event->button.button == SDL_BUTTON_LEFT) {
			//Get the mouse offsets
			x = event->button.x;
			y = event->button.y;

			//If the mouse is over the button
			if ((x > box.x) && (x < box.x + box.w) && (y > box.y)
					&& (y < box.y + box.h)) {
				//Set the button sprite
				frame = &regions[MOUSE_DOWN];
			}
		}
	}
	//If a mouse button was released
	if (event->type == SDL_MOUSEBUTTONUP) {
		//If the left mouse button was released
		if (event->button.button == SDL_BUTTON_LEFT) {
			//Get the mouse offsets
			x = event->button.x;
			y = event->button.y;

			//If the mouse is over the button
			if ((x > box.x) && (x < box.x + box.w) && (y > box.y)
					&& (y < box.y + box.h)) {
				//Set the button sprite
				frame = &regions[MOUSE_UP];
			}
		}
	}

}
