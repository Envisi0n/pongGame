/*
 * util.h
 *
 *  Created on: Oct 27, 2012
 *      Author: Cam
 */

#ifndef UTIL_H_
#define UTIL_H_
#include <string>


SDL_Surface *load_image( std::string filename );

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* snip = NULL );



#endif /* UTIL_H_ */
