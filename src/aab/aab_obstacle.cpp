#include "aab/aab_obstacle.h"
#include "bn_sprite_items_log.h"

namespace aab
{
    Obstacle::Obstacle(bn::fixed_point starting_position) : 
        sprite(bn::sprite_items::log.create_sprite(starting_position))
    {
    }

    void Obstacle::update()
    {
        // You can leave it static or add movement here if desired
    }
}