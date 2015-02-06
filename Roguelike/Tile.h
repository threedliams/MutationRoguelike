
#ifndef TILE_H
#define TILE_H

class Character;

#define WALL (char)219 
#define FLOOR (char)249
#define CHARACTER (char)64
#define ENEMY (char)69
enum PASSABLE {_WALL, _PASS, _ENEMY, _PLAYER};

class Tile{
	char representation;
	int isPassible;
	int isOpaque;
	int isVisible;
	int isExplored;
	bool hasCharacter;
	bool hasItem;
	Character* occupyingCharacter;

public:
	Tile();
	Tile(char, int, int);
	Tile(char);

	int getPassable();
	int getOpaque();
	int getVisible();
	int getExplored();

	char getRepresentation();

	void setPassable(int);
	void setRepresentation(char);
	void setOccupyingCharacter(Character *);
	void setVisible(int);
	void setExplored(int);

	Character * getOccupyingCharacter();
};

class Wall : public Tile{

public:
	Wall();
};

class Floor : public Tile{

public:
	Floor();
};

#endif