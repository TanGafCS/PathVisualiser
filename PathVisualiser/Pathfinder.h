#pragma once
#include "TileMap.h"

class Pathfinder
{
public:
	//virtual void IsComplete() = 0;
	virtual void Step() = 0;
	virtual void Reset() = 0;
	bool IsGoalFound() { return FoundGoal; }
	Tile* startTile, * goalTile;
protected:
	bool FoundGoal = false;
	Pathfinder(Tile* start, Tile* goal)
		: startTile(start), goalTile(goal)
	{}
	//TileMap& tileMap;
};