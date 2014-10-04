/* Copyright: (c) Kayne Ruse 2014
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
#include "region.hpp"

#include <stdexcept>
#include <cmath>

int snapToBase(int base, int x) {
	return floor((double)x / base) * base;
}

Region::Region(int argX, int argY): x(argX), y(argY) {
	if (x != snapToBase(REGION_WIDTH, x) || y != snapToBase(REGION_HEIGHT, y)) {
		throw(std::invalid_argument("Region location is off grid"));
	}
}

Region::Region(Region const& rhs): x(rhs.x), y(rhs.y) {
	thisGen = rhs.thisGen;
	nextGen = rhs.nextGen;
}

Region::type_t Region::SetThis(int x, int y, type_t v) {
	return thisGen[x * REGION_WIDTH + y] = v;
}

Region::type_t Region::GetThis(int x, int y) {
	return thisGen[x * REGION_WIDTH + y];
}

Region::type_t Region::SetNext(int x, int y, type_t v) {
	return nextGen[x * REGION_WIDTH + y] = v;
}

Region::type_t Region::GetNext(int x, int y) {
	return nextGen[x * REGION_WIDTH + y];
}
