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
#include "conway.hpp"

#include "drawing.hpp"

#include <iostream>

//-------------------------
//Public access members
//-------------------------

Conway::Conway() {
	//
}

Conway::~Conway() {
	//
}

//-------------------------
//Frame loop
//-------------------------

void Conway::FrameStart() {
	//
}

void Conway::Update() {
	//
}

void Conway::FrameEnd() {
	//
}

void Conway::RenderFrame() {
	SDL_Surface* screen = GetScreen();
	SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 128, 128, 128));
	Render(screen);
	SDL_Flip(screen);
	SDL_Delay(10);
}

void Conway::Render(SDL_Surface* const screen) {
	//draw the living cells
	//TODO

	//regular grid pattern
	//TODO

	//0 axis
	drawHLine(screen, camera.y, SDL_MapRGB(screen->format, 225, 225, 225));
	drawVLine(screen, camera.x, SDL_MapRGB(screen->format, 225, 225, 225));
}

//-------------------------
//Event handlers
//-------------------------

void Conway::MouseMotion(SDL_MouseMotionEvent const& motion) {
	//right click and drag
	if (motion.state & SDL_BUTTON_RMASK) {
		camera.x += motion.xrel;
		camera.y += motion.yrel;
	}
}

void Conway::MouseButtonDown(SDL_MouseButtonEvent const& button) {
	switch(button.button) {
		case SDL_BUTTON_WHEELUP:
			zoomLevel *= 2;
		break;
		case SDL_BUTTON_WHEELDOWN:
			zoomLevel /= 2;
		break;
		default:
			return;
	}

	//limit the zoom values
	if (zoomLevel < 1) {
		zoomLevel = 1;
	}
	else if (zoomLevel > 64) {
		zoomLevel = 64;
	}

	//output
	std::cout << "Zoom: " << zoomLevel << "x" << std::endl;
}

void Conway::MouseButtonUp(SDL_MouseButtonEvent const& button) {
	//
}

void Conway::KeyDown(SDL_KeyboardEvent const& key) {
	//
}

void Conway::KeyUp(SDL_KeyboardEvent const& key) {
	//
}
