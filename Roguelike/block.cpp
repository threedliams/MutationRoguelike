

#include "block.h"
#include "Tile.h"

/*void Block::generateBlock(){
	fillMap(map);
	if (type == 0){
		for (int j = 0; j < MAXLENGTH; j++){
			map[0][j] = Wall();
		}
		for (int i = 1; i < MAXHEIGHT - 1; i++){
			map[i][0] = Wall();
			for (int j = 1; j < MAXLENGTH - 1; j++){
				map[i][j] = Floor();
			}
			map[i][MAXLENGTH - 1] = Wall();
		}
		for (int j = 0; j < MAXLENGTH; j++){
			map[MAXHEIGHT - 1][j] = Wall();
		}
		map[6][7] = Wall();
		map[6][8] = Wall();
		map[6][9] = Wall();
	}
	else if (type == 1){
		while (addRoom(map)){
		}
	}
	else{
		cout << "ERROR: Invalid map type";
	}
}*/