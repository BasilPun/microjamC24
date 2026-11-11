#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>

namespace aab
{
    class Obstacle
    {
        public:
        bn::sprite_ptr sprite;

        Obstacle(bn::fixed_point starting_position);
        void update();
    };
}