
#include "point.h"
#include "Tile.h"

#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

Point::Point(int x, int y){
	xVal = x;
	yVal = y;
}

double Point::distance(Point p){
	return sqrt((p.xVal - xVal)*(p.xVal - xVal) + (p.yVal - yVal)*(p.yVal - yVal));
}

bool Point::operator==(const Point &p){
	return (p.xVal == xVal && p.yVal == yVal);
}

vector<Point> Point::path(Tile map[MAXHEIGHT][MAXLENGTH], Point start, Point goal){
	//Point start = Point(getX(), getY());
	vector<Point> closedSet;
	vector<Point> openSet;
	openSet.insert(openSet.begin(), start);
	std::unordered_map<Point, Point, hash<Point>> cameFrom;

	std::unordered_map<Point, double, hash<Point>> g_score;
	std::unordered_map<Point, double, hash<Point>> f_score;

	g_score[start] = 0;
	f_score[start] = g_score[start] + start.distance(goal);	//in this case the "heuristic cost estimate" is just the distance
							
	while (!openSet.empty()){
		double lowest = f_score[openSet[0]];
		Point current = openSet[0];
		for (int i = 1; i < (int)openSet.size(); i++){
			if (f_score[openSet[i]] < lowest){
				lowest = f_score[openSet[i]];
				current = openSet[i];
			}
		}

		if (current == goal){
			return reconstruct_path(cameFrom, goal, start);
		}

		for (int i = 0; i < (int)openSet.size(); i++){
			if (openSet[i] == current){
				openSet.erase(openSet.begin() + i);
			}
		}
		closedSet.insert(closedSet.begin(), current);
		vector<Point> neighbors = getNeighbors(current);
		for (int i = 0; i < (int)neighbors.size(); i++){
			if (neighbors[i].xVal >= 0 && neighbors[i].yVal >= 0){
				if (map[yVal][xVal].getPassable()){
					Point currentNeighbor = neighbors[i];
					bool isClosed = false;
					for (int j = 0; j < (int)closedSet.size(); j++){
						if (closedSet[j] == currentNeighbor){
							isClosed = true;
						}
					}
					if (isClosed){
						continue;
					}

					double tentative_g_score = g_score[current] + current.distance(currentNeighbor);

					bool isOpen = false;
					for (int j = 0; j < (int)openSet.size(); j++){
						if (openSet[j] == current){
							isOpen = true;
						}
					}
					if ((!isOpen) || tentative_g_score < g_score[currentNeighbor]){
						cameFrom[currentNeighbor] = current;
						g_score[currentNeighbor] = tentative_g_score;
						f_score[currentNeighbor] = g_score[currentNeighbor] + currentNeighbor.distance(goal);
						if (!isOpen){
							openSet.insert(openSet.begin(), currentNeighbor);
						}
					}
				}
			}
		}
	}
	return closedSet;
}

vector<Point> Point::reconstruct_path(unordered_map<Point, Point, hash<Point>> cameFrom, Point current_node, Point end){
	if (current_node != end){
		vector<Point> p = reconstruct_path(cameFrom, cameFrom[current_node], end);
		p.push_back(current_node);
		return p;
	}
	else{
		vector<Point> result;
		result.insert(result.begin(), current_node);
		return result;
	}
}

vector<Point> Point::getNeighbors(Point p){
	vector<Point> result;
	result.insert(result.begin(), Point(p.xVal - 1, p.yVal - 1));
	result.insert(result.begin(), Point(p.xVal - 1, p.yVal));
	result.insert(result.begin(), Point(p.xVal, p.yVal - 1));
	result.insert(result.begin(), Point(p.xVal + 1, p.yVal + 1));
	result.insert(result.begin(), Point(p.xVal + 1, p.yVal));
	result.insert(result.begin(), Point(p.xVal, p.yVal + 1));
	result.insert(result.begin(), Point(p.xVal + 1, p.yVal - 1));
	result.insert(result.begin(), Point(p.xVal - 1, p.yVal + 1));
	return result;
}



