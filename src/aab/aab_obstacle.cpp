#include "aab/aab_obstacle.h"

namespace aab
{
    Obstacle::Obstacle(bn::sprite_item item, bn::fixed_point starting_position) : 
        sprite(item.create_sprite(starting_position))
    {
    }

    void Obstacle::update()
    {
        // You can leave it static or add movement here if desired
    }
}