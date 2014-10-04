/* Copyright: (c) Kayne Ruse 2013, 2014
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 
 * 3. This notice may not be removed or altered from any source
 * distribution.
*/
#ifndef DRAWING_HPP_
#define DRAWING_HPP_

#include "SDL/SDL.h"

void drawPixel(SDL_Surface* const dest, int x, int y, int colour);

//lines across the screen
void drawHLine(SDL_Surface* const dest, int y, int colour);
void drawVLine(SDL_Surface* const dest, int x, int colour);

//shapes
void drawBox(SDL_Surface* const dest, int x1, int y1, int x2, int y2, int colour);

#endif
