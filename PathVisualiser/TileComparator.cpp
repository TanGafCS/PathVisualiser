#include "Tile.h"
class TileComparator
{
public:
    int operator() (const Tile* tile1, const Tile* tile2)
    {
        // TODO: if fCosts are equal, pick lower hCost tiles first.
        return tile1->fCost > tile2->fCost;
    }
};