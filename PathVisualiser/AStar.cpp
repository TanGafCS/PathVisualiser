#include "AStar.h"
#include <iostream>

AStar::AStar(TileMap& tileMap, Tile* start, Tile* goal)
	: openSet(), tileMap(tileMap), startTile(*start), goalTile(*goal),
	gCost(tileMap.Rows(), std::vector<int>(tileMap.Cols(), INT_LEAST16_MAX))
{
	this->openSet.push(start);

	// Set starting tile's gcost
	gCost[start->y][start->x] = 0;

	/*	Set tiles' hcosts. Use Distance function - it does not
		overestimate the actual cost, and will return the least-cost path. */
}

int AStar::Distance(Tile& tile1, Tile& tile2)
{
	return 1;
}

void AStar::Step()
{
	if (openSet.empty()) return;	// Finished pathing

	auto* cur = openSet.top();
	openSet.pop();

	if (cur == &goalTile)
	{
		openSet.empty();
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
