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
#ifndef REGION_HPP_
#define REGION_HPP_

#include <bitset>

//the region's storage format
constexpr int REGION_WIDTH = 20;
constexpr int REGION_HEIGHT = 20;

//utility function
int snapToBase(int base, int x);

class Region {
public:
	typedef int type_t;

	Region() = delete;
	Region(int x, int y);
	Region(Region const&);
	~Region() = default;

	type_t SetThis(int x, int y, type_t  v);
	type_t GetThis(int x, int y);

	type_t SetNext(int x, int y, type_t  v);
	type_t GetNext(int x, int y);

	//accessors
	int GetX() const { return x; }
	int GetY() const { return y; }

	std::bitset<REGION_WIDTH*REGION_HEIGHT>* GetThisGen() { return &thisGen; }
	std::bitset<REGION_WIDTH*REGION_HEIGHT>* GetNextGen() { return &nextGen; }
private:
	const int x;
	const int y;

	std::bitset<REGION_WIDTH*REGION_HEIGHT> thisGen;
	std::bitset<REGION_WIDTH*REGION_HEIGHT> nextGen;
};

#endif
