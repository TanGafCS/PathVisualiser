#include "Tile.h"
class TileComparator
{
public:
    int operator() (const Tile* tile1, const Tile* tile2)
    {
        // if fCosts are equal, pick lower hCost tiles first, exploring
        // the areas closer to the target first.
        if (tile1->fCost == tile2->fCost)
        {
            return tile1->hCost > tile2->hCost;
        }
        return tile1->fCost > tile2->fCost;
    }
};