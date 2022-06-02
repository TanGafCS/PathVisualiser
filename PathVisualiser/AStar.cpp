#include "AStar.h"

AStar::AStar(TileMap& tileMap, Tile& start, Tile& goal)
	: openSet(), tileMap(tileMap), startTile(start), goalTile(goal)
{
	openSet.push(&startTile);
}

int AStar::Distance(Tile& tile1, Tile& tile2)
{
	return 1;
}

void AStar::Step()
{
	if (openSet.empty()) return;	// Finished pathing

	auto& cur = openSet.top();
	openSet.pop();

	if (cur == &goalTile) return;

	auto neighbours = tileMap.GetNeighbours(*cur);
	//for (size_t i = 0; i < neighbours.size(); i++)
	//{
	//	Tile& tile = neighbours[i];
	//	int x = tile.x, y = tile.y;
	//	int potentialGCost = gCost[cur.y][cur.x] + Distance(cur, tile);
	//}
	//for (Tile& tile : neighbours)
	//{
	//	int x = tile.x, y = tile.y;
	//	int potentialGCost = gCost[cur.y][cur.x] + Distance(cur, tile);
	//}
}
