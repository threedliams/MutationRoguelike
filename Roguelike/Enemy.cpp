#include "enemy.h"
#include "Tile.h"

using namespace std;

Enemy::Enemy(int h, char r) : Character(h, r){

}

int Enemy::attack(Character* c){
	//damage calculation
	int d = 5;

	if (c != 0) {
		c->damage(d);
		return 1;
	}
	else
		return 0;

	//return dmg;
}

void Enemy::damage(int d) {
	//dodge/resistance
	health -= d;

	//Check for death in here?
}

int Enemy::checkAttack(Tile map[MAXHEIGHT][MAXLENGTH]){
	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			if (map[getY() + y][getX() + x].getPassable() == _PLAYER) {
				attack(map[getY() + y][getX() + x].getOccupyingCharacter());
				return 1;
			}
		}
	}
	return 0;
}