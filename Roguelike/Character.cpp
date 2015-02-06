
#include "Character.h"
#include "Tile.h"
#include "Point.h"

#include<iostream>
using namespace std;

Character::Character(int h, char r){
	exp = 0;
	health = h;
	rep = r;
	xPos = -1;
	yPos = -1;
	sightDistance = 6;
}

void Character::damage(int d) { 
}

void Character::addExp(int e) { 
	exp += e;
}

void Character::setRep(char c) {
	rep = c;
}

void Character::resetExp(){
	exp = 0;
}

int Character::attack(Character* c){
	return 0;
}

char Character::getRep(){
	return rep;
}

int Character::getX(){
	return xPos;
}

int Character::getY(){
	return yPos;
}

int Character::getSight(){
	return sightDistance;
}

int Character::hasLOS(int y, int x){
	Point p1 = Point(x, y);
	Point p2 = Point(xPos, yPos);
	//cout << p1.distance(p2) << " " << sightDistance;
	if (p1.distance(p2) < sightDistance){
		return 1;
	}
	return 0;
}

void Character::setPos(int y, int x, Tile map[MAXHEIGHT][MAXLENGTH]){
	if (xPos == -1 || yPos == -1){
		map[y][x].setOccupyingCharacter(this);
		//cout << "rep: " << map[x][y].getRepresentation();
	}
	else{
		map[yPos][xPos].setOccupyingCharacter(0);
		map[yPos][xPos].setPassable(_PASS);
		map[y][x].setOccupyingCharacter(this);
		map[y][x].setPassable(_PLAYER);
	}
	xPos = x;
	yPos = y;
}