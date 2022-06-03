#include "AStar.h"
#include <iostream>

AStar::AStar(TileMap& tileMap, Tile* start, Tile* goal)
	: Pathfinder(start, goal), openSet(), tileMap(tileMap)
{
	Reset();
}

int AStar::Distance(Tile& tile1, Tile& tile2)
{
	float x1 = tile1.x, x2 = tile2.x, y1 = tile1.y, y2 = tile2.y;
	float xDiff = std::abs(x1 - x2), yDiff = std::abs(y1 - y2);
	float dist = std::sqrtf((xDiff * xDiff) + (yDiff * yDiff)) * 10;
	return (int)dist;
}

void AStar::Step()
{
	if (openSet.empty()) return;	// Finished pathing

	auto* cur = openSet.top();
	openSet.pop();

	if (cur->isClosed) Step();		// if examining closed tile, skip.

	cur->isClosed = true;

	if (cur == goalTile)
	{
		openSet = {};
		FoundGoal = true;
		MarkGoalPath();
		return;
	}

	auto neighbours = tileMap.GetNeighbours(*cur);
	for (size_t i = 0; i < neighbours.size(); i++)
	{
		Tile* neighbour = neighbours[i];
		int x = neighbour->x, y = neighbour->y;
		int potentialGCost = cur->gCost + Distance(*cur, *neighbour);

		if (potentialGCost < neighbour->gCost)
		{
			neighbour->gCost = potentialGCost;
			neighbour->fCost = neighbour->gCost + neighbour->hCost;
			neighbour->predecessor = cur;
			openSet.push(neighbour);
		}
	}
}

void AStar::Reset()
{
	this->openSet.push(startTile);

	/*	Set tiles' hcosts. Use Distance function - it does not
		overestimate the actual cost, and will return the least-cost path. */
	for (int i = 0; i < tileMap.Cols(); i++)
	{
		for (int j = 0; j < tileMap.Rows(); j++)
		{
			Tile& tile = tileMap[i][j];
			auto hc = Distance(*goalTile, tileMap[i][j]);
			tile.hCost = hc;
			tile.gCost = INT_LEAST16_MAX;
			tile.fCost = INT_LEAST16_MAX;

			tile.isClosed = false;
			tile.isPath = false;
		}
	}

	// Set starting tile's costs
	startTile->gCost = 0;
	startTile->hCost = 0;
	startTile->fCost = 0;
}

void AStar::MarkGoalPath()
{
	Tile* pathTile = goalTile;
	while (pathTile)
	{
		pathTile->isPath = true;
		pathTile = pathTile->predecessor;
	}
}
