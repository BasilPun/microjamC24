#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_animate_actions.h>

namespace aab
{
    /**
     * A character controlled by up/down arrows & "A" button
     */
    class Swimmer
    {
    public:
        bn::sprite_ptr sprite;

        /**
         * player's swimmer constructor
         *
         * @param starting_position the location to start the swimmer at
         */

        Swimmer(bn::fixed_point starting_position);
        void update();

    private:
        bn::sprite_animate_action<4> animate;
    };
}