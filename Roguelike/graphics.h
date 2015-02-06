
#ifndef GRAPHICS_H
#define GRAPHICS_H

#define DISPLAY_HEIGHT 40
#define DISPLAY_LENGTH 60
#define STATUS_LENGTH 20
#define CONSOLE_HEIGHT 10

#include "map.h"
#include "panel.h"

void printMap(Tile[MAXHEIGHT][MAXLENGTH]);

void initGraphics();

void redrawScreen(Tile map[MAXHEIGHT][MAXLENGTH]);

void printToConsole(char*);

void printToStatus(char*);

//WINDOW * mainWindow;

#endif