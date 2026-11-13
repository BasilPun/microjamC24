#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_item.h>

namespace aab
{
    class Obstacle
    {
        public:
        bn::sprite_ptr sprite;

        Obstacle(bn::sprite_item item, bn::fixed_point starting_position);
        void update();
    };
}