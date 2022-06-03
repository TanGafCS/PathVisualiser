#include "AStar.h"
#include <iostream>

AStar::AStar(TileMap& tileMap, Tile* start, Tile* goal)
	: openSet(), tileMap(tileMap), startTile(*start), goalTile(*goal),
	gCost(tileMap.Rows(), std::vector<int>(tileMap.Cols(), INT_LEAST16_MAX)),
	hCost(tileMap.Rows(), std::vector<int>(tileMap.Cols(), INT_LEAST16_MAX))
{
	this->openSet.push(start);

	// Set starting tile's gcost
	gCost[start->y][start->x] = 0;
	start->fCost = 0;

	/*	Set tiles' hcosts. Use Distance function - it does not
		overestimate the actual cost, and will return the least-cost path. */
	for (size_t i = 0; i < tileMap.Cols(); i++)
	{
		for (size_t j = 0; j < tileMap.Rows(); j++)
		{
			hCost[i][j] = Distance(*goal, tileMap[i][j]);
		}
	}
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
	cur->isClosed = true;
	openSet.pop();

	if (cur == &goalTile)
	{
		openSet = {};
		FoundGoal = true;
		return;
	}

	auto neighbours = tileMap.GetNeighbours(*cur);
	for (size_t i = 0; i < neighbours.size(); i++)
	{
		Tile* neighbour = neighbours[i];
		int x = neighbour->x, y = neighbour->y;
		int potentialGCost = gCost[cur->y][cur->x] + Distance(*cur, *neighbour);

		if (potentialGCost < gCost[neighbour->y][neighbour->x])
		{
			gCost[neighbour->y][neighbour->x] = potentialGCost;
			neighbour->fCost = gCost[neighbour->y][neighbour->x] + hCost[neighbour->y][neighbour->x];
			neighbour->predecessor = cur;
			openSet.push(neighbour);
		}
	}
	//for (Tile& tile : neighbours)
	//{
	//	int x = tile.x, y = tile.y;
	//	int potentialGCost = gCost[cur.y][cur.x] + Distance(cur, tile);
	//}
}
