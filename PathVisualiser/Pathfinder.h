#pragma once
#include "TileMap.h"

/// <summary>
/// Manipulates the
/// </summary>
class Pathfinder
{
public:
	//virtual void IsComplete() = 0;
	virtual void Step() = 0;
	bool IsGoalFound() { return FoundGoal; }
protected:
	bool FoundGoal = false;
	//TileMap& tileMap;
};