#include "player.h"

using namespace std;

Character* Player::playerCharacter;

Player::Player(int h, char r) : Character(h, r){

}

void Player::levelUp(){
	resetExp();
	level++;

	//increase stats by some sort of modifiers here. possibly dependent on race or something
}

int Player::attack(Character* c){
	//damage calculation
	int d = 5;
	//calculate hit/miss based on character stats
	if (c != 0){
		c->damage(d);
		return 1;
	}
	else {
		return 0;
	}
}

void Player::damage(int d) {
	//calculate dodge/evasion/resistances

	health -= d;

	//Check for death in here?
}