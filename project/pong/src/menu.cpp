/*
 * menu.cpp
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#include "menu.h"
#include <iostream>

menu::menu() {
	// TODO Auto-generated constructor stub

}

menu::~menu() {
	// TODO Auto-generated destructor stub
}

void menu::update(SDL_Event* event) {

	for (vector<button*>::iterator it = buttons.begin(); it != buttons.end();
				++it) {


			(*it)->update(event);

		}


}

void menu::draw(SDL_Surface* screen) {

	for (vector<button*>::iterator it = buttons.begin(); it != buttons.end();
			++it) {

		std::cout << "draw" <<  screen << endl;
		(*it)->draw(screen);

	}
}

void menu::addButton(int x, int y, int w, int h, std::string i) {

	button* temp  = new button(x, y, w, h, i);

	buttons.push_back(temp);

}
