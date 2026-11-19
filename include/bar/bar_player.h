#pragma once
#include <bn_display.h>
#include <bn_fixed.h>
#include <bn_sprite_animate_actions.h>
#include <bn_sprite_ptr.h>
#include <bn_vector.h>
#include <bn_rect.h>
#include <bn_keypad.h>

#include "bar_bouncer.h"
#include "bar_create_bounding_box.h"

#include "bn_sprite_items_bar_box.h"

// All game functions/classes/variables/constants scoped to the namespace
namespace bar
{
    class bar_player
    {

    public:
        /**
         * @param player_position_x where the player is spawned on the x axis. The character will be static.
         * @param player_position_y where the player is spawned on the y axis.
         */
        bar_player(bn::fixed player_postion_x, bn::fixed player_position_y, bn::size player_size);

        /**
         * Reads from the bumpers and triggers one of the arms to move.
         */
        void update(bar_bouncer &bouncer);

        static constexpr int get_max_bouncers()
        {
            return MAX_BOUNCERS;
        }

    private:
        static constexpr int MAX_BOUNCERS = 5;
        // The sprite to display the player
        bn::sprite_ptr _sprite;
        bn::sprite_animate_action<4> _sprite_action;
        bn::size _size;
        bn::rect _bounding_box;

        /**
         * Reads from the d-pad and sets direction sprites is pointing.
         * Regardless of direction, updates the sprite animation action.
         */
        void _update_animation();
    };
}
