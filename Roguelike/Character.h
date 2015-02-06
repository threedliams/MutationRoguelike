
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Map.h"

class Tile;

class Character
{
public:
	int exp;
	int health;
	char rep;
	int xPos;
	int yPos;
	int sightDistance;

	virtual void damage(int);
	void addExp(int);
	void setRep(char);
	void resetExp();
	virtual int attack(Character*);
	char getRep();
	Character(int, char);
	int getX();
	int getY();
	int getSight();
	void setPos(int, int, Tile[MAXHEIGHT][MAXLENGTH]);

	int hasLOS(int, int);
};

#endif


