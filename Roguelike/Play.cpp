


#include <iostream>


#include "play.h"
#include "Tile.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Point.h"
#include "graphics.h"

using namespace std;

int main(){

	//curses initialization
	initGraphics();


	Tile map[MAXHEIGHT][MAXLENGTH];
	generateMap(0, map);
	//printMap(map);
	//while(play() != 27){
	//	printMap(map);
	//}
	play(map);
	exit(EXIT_SUCCESS);
}

int play(Tile map[MAXHEIGHT][MAXLENGTH]){
	int c = 0;
	Character ** characters = populateMap(map);
	//setEnemyLoc(15, 15, map);
	

	redrawScreen(map);

	printToConsole("This is a console message. If it gets too long, it will wrap onto the next line.");
	printToStatus("This is a status message. If it gets too long, it will wrap onto the next line.");
	c = getch();
	while (c != 27){
		int redraw = 0;
		if (c == KEY_C1){
			redraw = moveCH(1, map, characters[0]);
		}
		if (c == KEY_C2){
			redraw = moveCH(2, map, characters[0]);
		}
		if (c == KEY_C3){
			redraw = moveCH(3, map, characters[0]);
		}
		if (c == KEY_B1){
			redraw = moveCH(4, map, characters[0]);
		}
		if (c == KEY_B2){
			redraw = moveCH(5, map, characters[0]);
		}
		if (c == KEY_B3){
			redraw = moveCH(6, map, characters[0]);
		}
		if (c == KEY_A1){
			redraw = moveCH(7, map, characters[0]);
		}
		if (c == KEY_A2){
			redraw = moveCH(8, map, characters[0]);
		}
		if (c == KEY_A3){
			redraw = moveCH(9, map, characters[0]);
		}
		if (redraw){
			redrawScreen(map);
		}
		printToConsole("This is a console message. If it gets too long, it will wrap onto the next line.");
		printToStatus("This is a status message. If it gets too long, it will wrap onto the next line.");
		//Iterate through enemies
		Point p1 = Point(characters[1]->getX(), characters[1]->getY());
		Point p2 = Point(characters[0]->getX(), characters[0]->getY());
		vector<Point> test = p1.path(map, p1, p2);
		//printPath(test);
		Enemy * e = (Enemy*)characters[1];
		e->checkAttack(map);
		c = getch();
	}
	endwin();
	return 1;
}

void printPath(vector<Point> p){
	//printToConsole("\n\n");
	char temp[10];
	sprintf_s(temp, "%d", p.size());
	//printToConsole(temp);
	//cout << p.size();
	for (int i = 0; i < (int)p.size(); i++){
		sprintf_s(temp, "%d, %d", p[i].xVal, p[i].yVal);
		printToConsole(temp);
		//cout << p[i].xVal << ", " << p[i].yVal << "\n";
	}
}

Character ** populateMap(Tile map[MAXHEIGHT][MAXLENGTH]){
	Character ** result = (Character**)malloc(sizeof(Character**)*2);
	Player::playerCharacter = (Character*)malloc(sizeof(Player));
	Player::playerCharacter = new Player(10, '@');
	Player::playerCharacter->setPos(1, 1, map);
	map[1][1].setPassable(_PLAYER);
	Character * e = (Character*)malloc(sizeof(Enemy));
	e = new Enemy(5, 'e');
	e->setPos(MAXHEIGHT / 2, MAXLENGTH / 2, map);
	result[0] = Player::playerCharacter;
	result[1] = e;
	return result;
}

int moveCH(int direction, Tile map[MAXHEIGHT][MAXLENGTH], Character *c){
	//top row
	if (direction == 7){
		switch (map[c->getY() - 1][c->getX() - 1].getPassable()) {
		case _PASS:
			c->setPos(c->getY() - 1, c->getX() - 1, map);
			break;

		case _ENEMY:
			c->attack(map[c->getY() - 1][c->getX() - 1].getOccupyingCharacter());
			break;

		default:
			return 0;
		}
	}
	else if (direction == 8){
		switch (map[c->getY() - 1][c->getX()].getPassable()){
		case _PASS:
			c->setPos(c->getY() - 1, c->getX(), map);
			break;

		case _ENEMY:
			c->attack(map[c->getY() - 1][c->getX()].getOccupyingCharacter());
			break;

		default:
			return 0;

		}
	}
	else if (direction == 9){
		switch (map[c->getY() - 1][c->getX() + 1].getPassable()){
		case _PASS:
			c->setPos(c->getY() - 1, c->getX() + 1, map);
			break;

		case _ENEMY:
			c->attack(map[c->getY() - 1][c->getX() + 1].getOccupyingCharacter());
			break;

		default:
			return 0;

		}
	}

	//middle row
	else if (direction == 4){
		switch (map[c->getY()][c->getX() - 1].getPassable()){
		case _PASS:
			c->setPos(c->getY(), c->getX() - 1, map);
			break;

		case _ENEMY:
			c->attack(map[c->getY()][c->getX() - 1].getOccupyingCharacter());
			break;

		default:
			return 0;

		}
	}
	else if (direction == 5){
		return 1;
	}
	else if (direction == 6){
		switch (map[c->getY()][c->getX() + 1].getPassable()){
		case _PASS:
			c->setPos(c->getY(), c->getX() + 1, map);
			break;

		case _ENEMY:
			c->attack(map[c->getY()][c->getX() + 1].getOccupyingCharacter());
			break;

		default:
			return 0;

		}
	}

	//bottom row
	else if (direction == 1){
		switch (map[c->getY() + 1][c->getX() - 1].getPassable()){
		case _PASS:
			c->setPos(c->getY() + 1, c->getX() - 1, map);
			break;

		case _ENEMY:
			c->attack(map[c->getY() + 1][c->getX() - 1].getOccupyingCharacter());
			break;

		default:
			return 0;

		}
	}
	else if (direction == 2){
		switch (map[c->getY() + 1][c->getX()].getPassable()){
		case _PASS:
			c->setPos(c->getY() + 1, c->getX(), map);
			break;

		case _ENEMY:
			c->attack(map[c->getY() + 1][c->getX()].getOccupyingCharacter());
			break;

		default:
			return 0;

		}
	}
	else if (direction == 3){
		switch (map[c->getY() + 1][c->getX() + 1].getPassable()){
		case _PASS:
			c->setPos(c->getY() + 1, c->getX() + 1, map);
			break;

		case _ENEMY:
			c->attack(map[c->getY() + 1][c->getX() + 1].getOccupyingCharacter());
			break;

		default:
			return 0;
		}
	}

	else if (direction == 27){
		return 0;
	}

	return 1;
}