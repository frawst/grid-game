/*
	Grid-game 1.0a

	Contributors: 
	Justyn Chaykowski

	git:github.com/frawst/grid-game

	Format Notes:
	- Inline comments require 2 blank spaces before comment
	- Example comment:  // Comment here, note blank space after slashes
	- Leave a blank line at end of file
	- Leave a line break between all classes and functions
	- Ensure any potentially ambiguous code is commented, state intentions

	**** See the README for current problem statements ****
*/

#include <iostream>
#include <string>

using namespace std;

enum WINDOW{MAP, INVENTORY, STATS};

//==========================
//    Classes
//==========================

class Game  // Primary class
{
private:

protected:

public:
	int activeWindow = MAP;
};

class Zone : public Game  // Current Zone/Map data
{
private:
	// Need a structure here to track which areas are visited/cleared
	int level;  // 'floor', 'level', 'depth'. On zone clear: level++, visit tiles reset


protected:

public:
	void reset();  // For when a floor is cleared
};

class Player : public Game  // Player Class
{
private:
	int posx, posy;  // Player position in grid

protected:

public:

};