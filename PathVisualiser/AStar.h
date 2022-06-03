#pragma once
#include "Pathfinder.h"
#include "Tile.h"
#include "TileComparator.cpp"
#include <queue>

class AStar : public Pathfinder
{
public:
	AStar(TileMap& tileMap, Tile* startTile, Tile* goalTile);
	int Distance(Tile& tile1, Tile& tile2);
	// Inherited via Pathfinder
	virtual void Step() override;
private:
	std::priority_queue<Tile*, std::vector<Tile*>, TileComparator> openSet;
	Tile& startTile, & goalTile;
	TileMap& tileMap;
	std::vector<std::vector<int>> gCost, hCost, fCost;
};
