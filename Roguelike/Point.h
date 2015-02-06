
#ifndef POINT_H
#define POINT_H

#include "map.h"
#include <map>
#include <vector>
#include <unordered_map>
#include <functional>

class Tile;
class PointComp;
using namespace std;



class Point{
public:
	int xVal;
	int yVal;
	double distance(Point p);
	bool operator==(const Point &p);
	std::vector<Point> path(Tile[MAXHEIGHT][MAXLENGTH], Point, Point);
	std::vector<Point> reconstruct_path(std::unordered_map<Point, Point, hash<Point>>, Point, Point);
	std::vector<Point> getNeighbors(Point);
	Point(int, int);
	Point(){ xVal = 0; yVal = 0; }


	/*bool operator==(const Point &p){
		if (p.xVal == this->xVal && p.yVal == this->yVal){
			return true;
		}
		else{
			return false;
		}
	}*/
};


class PointComp{
public:
	bool operator() (const Point& lhs, const Point& rhs) const{
		return (lhs.xVal < rhs.xVal) || ((lhs.xVal == rhs.xVal) && (lhs.yVal < rhs.yVal));
	}
};

namespace std{
	template<>
	class hash<Point>{
	public:
		size_t operator()(const Point& p) const{
			return ((51 + hash<int>()(p.xVal)) * 51 + hash<int>()(p.yVal));
		}
	};
	inline bool operator == (const Point& lhs, const Point& rhs){
		return (lhs.xVal == rhs.xVal) && (lhs.xVal == rhs.xVal);
	}
	inline bool operator != (const Point& lhs, const Point& rhs){
		return (lhs.xVal != rhs.xVal) || (lhs.xVal != rhs.xVal);
	}
};

#endif