#include "Character.h"

#include "point.h"

class Enemy: public Character{
public:
	int dmg;

	Enemy(int, char);
	int attack(Character*);
	void damage(int);
	int checkAttack(Tile[MAXHEIGHT][MAXLENGTH]);
};