#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_animate_actions.h>
#include <bn_display.h>

namespace aab
{
    class Dolphin
    {
    public:
        Dolphin(bn::fixed_point starting_position, bn::fixed speed);

        void update();

    private:
        bn::sprite_ptr sprite;
        bn::sprite_animate_action<6> animate;
        bn::fixed speed;
    };
}