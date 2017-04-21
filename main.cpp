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
enum CONTENTS{MONSTER, LOOT, EMPTY};
enum COMMAND{MOVE, USE, STATS, INVENTORY, HELP};

//==========================
//    Classes
//==========================

// BASE GAME CLASS
class Game
{
private:
	COMMAND command;
protected:

public:
	int activeWindow = MAP;
	void getCommandInput();  // To be used to get a command from user
	void executeCommand();  // To execute commands
	void tick();  // Start next game tick
};

// BASE GAME CLASS FUNCTION INIT


// ZONE / MAP CLASS
class Zone : public Game
{
private:
	int mapWidth = 8;  // looping values
	int mapHeight = 10;
	bool grid[8][10];  // Level tracking strucutre, TRUE = visited
	int level;  // 'floor', 'level', 'depth'. On zone clear: level++, visit tiles reset

public:
	void init();
	void reset();  // Resets floor state to uncleared
};

// ZONE CLASS FUNCTION INIT
void Zone::init()
{
	Zone::reset();
}
void Zone::reset()
{
	for (int i = 0; i < Zone::mapWidth; i++)
	{
		for (int j = 0; j < Zone::mapHeight; i++)
		{
			Zone::grid[i][j] = true;
		}
	}
}

// ROOM CLASS, MANAGES EACH INDIVIDUAL GRID POINT ON MAP
class Room : public Game
{
private:
	CONTENTS content;  // To hold room contents

public:
	void setContents();  // To randomly create an encounter
	int getContents(){return content;}

};

// ROOM CLASS FUNCTION INIT
void Room::setContents()
{
	int dice = (rand() % 6) + 1;  // Random num gen for deciding room content
	switch(dice)  // Placeholder switch for assigning states to dice rolls
	{
		case 1:
			Room::content = EMPTY;
			break;
		case 2:
			Room::content = EMPTY;
			break;
		case 3:
			Room::content = MONSTER;
			break;
		case 4:
			Room::content = MONSTER;
			break;
		case 5:
			Room::content = MONSTER;
			break;
		case 6:
			Room::content = LOOT;
			break;
	}

};


// PLAYER CLASS
class Player : public Game  // Player Class
{
private:
	int posx, posy;  // Player position in grid

	// Stats
	int health;  // Base health + bonuses
	int activeHealth;  // Current health pool

	int mana;  // Base mana + bonuses
	int activeMana;  // Current mana pool

	int dodgeChance;  // Chance to dodge an attack
	int activeDodgeChance;  // Buffs and Debuffs

	int critChance;  // Chance to critical
	int activeCritChance;  // Buffs and Debuffs

	int strength;  // Determines physical power + def, modifies constitution
	int activeStrength;  // Buffs and Debuffs

	int intelligence;  // Determines magical power + def, modifies spirit
	int activeIntelligence;  // Buffs and Debuffs

	int constitution;  // Modifies base health
	int activeConstitution;  // Buffs and Debuffs

	int spirit;  // Modifies base mana
	int activeSpirit;  // Buffs and Debuffs

	int dexterity;  // Modifies dodge and crit chance
	int activeDexterity;  // Buffs and Debuffs

public:
	void init();

	void setPos(int direction);  // Set player position, 1=UP, 2=RIGHT, 3=DOWN, 4=LEFT

	int getActiveHealth(){return Player::activeHealth;}
	void gotHit(int);  // Calculate Health - Damage

	int getActiveMana(){return Player::activeMana;}
	void spendMana(int);  // For when a spell is cast, or mana is drained elsewise

	int getActiveCritChace(){return Player::activeCritChance;}
	int getActiveDodgeChance(){return Player::activeDodgeChance;}
	int getActiveStrength(){return Player::activeStrength;}
	int getActiveIntelligence(){return Player::activeIntelligence;}
	int getActiveConstitution(){return Player::activeConstitution;}
	int getActiveSpirit(){return Player::activeSpirit;}
	int getActiveDexterity(){return Player::activeDexterity;}

	int checkStanding(room);  // Figure out what is in the room I'm in

};

// PLAYER CLASS FUNCTION INIT

void Player::init()
{
	Player::posx = 1;
	Player::posy = 10;
	Player::strength = 10;
	Player::intelligence = 10;
	Player::constitution = 10;
	Player::spirit = 10;
	Player::dexterity = 10;
}

void Player::executeCommand()
{
	// Some code here for command execution
	switch(Game::command)
	{
		case MOVE:
			break;
		case USE:
			break;
		case STATS:
			break;
		case INVENTORY:
			break;
		case HELP:
			cout << "Commands: Move, Use, Stats, Inventory, Help" << endl;
			break;
	}
}

int Player::checkStanding(room)
{
	CONTENTS roomContent = room.getContents();
	return roomContent;
}

void Player::getCommandInput()
{
	// Some code here to get a command input and assign it to Game::command
	cout << "What is your command?" << endl;
}

void Player::tick()
{
	Player::health = (Player::constitution * (float(Player::strength / 10) + 1));
	Player::mana = (Player::spirit * (float(Player::intelligence / 10) + 1));
	Player::getCommandInput();
}


// MAIN PROGRAM LOOP

int main()
{
	Zone zone;
	Player player;

	zone.init();
	player.init();

	return 0;
}