#include "Tile.h"
class TileComparator
{
public:
    int operator() (const Tile* tile1, const Tile* tile2)
    {
        return tile1->fCost > tile2->fCost;
    }
};