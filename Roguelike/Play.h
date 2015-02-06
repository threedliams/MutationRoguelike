

#ifndef PLAY_H
#define PLAY_H

#include "Map.h"

class Tile;
class Character;

int play(Tile[MAXHEIGHT][MAXLENGTH]);

int setCharLocation(int, int, Tile[MAXHEIGHT][MAXLENGTH]);

int setEnemyLoc(int, int, Tile[MAXHEIGHT][MAXLENGTH]);

int* locatePC(Tile[MAXHEIGHT][MAXLENGTH]);

int moveCH(int, Tile[MAXHEIGHT][MAXLENGTH], Character *);

Character ** populateMap(Tile[MAXHEIGHT][MAXLENGTH]);

#endif