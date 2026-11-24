#pragma once
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_rect.h>
#include <bn_display.h>
#include <bn_sprite_animate_actions.h>

// All game functions/classes/variables/constants scoped to the namespace
namespace nsj
{
    class player
    {
        // The bounds of the screen
        static constexpr int MAX_X = bn::display::width() / 2;
        static constexpr int MIN_X = -bn::display::width() / 2;
        static constexpr int MAX_Y = bn::display::height() / 2;
        static constexpr int MIN_Y = -bn::display::height() / 2;

    public:
        /**
         * player constructor
         *
         * @param starting_position the location to start the player at
         * @param speed the pixels/frame the player moves at in each dimension
         */
        player(bn::fixed_point starting_position, bn::fixed speed);

        /**
         * Reads from the d-pad and moves the player by one frame accordingly.
         */
        void update();

        /**
         * Returns whether the player has left the screen
         *
         * @return true if the player has left the screen, false if it is still on the screen
         */
        bool out_of_bounds() const;

        bn::fixed_point get_position();
        bn::rect get_bounding_box();

    private:
        // The sprite to display the player
        bn::sprite_ptr _sprite;
        bn::sprite_animate_action<4> _sprite_action;
        bn::size _size;
        bn::fixed _speed;
        bn::rect _bounding_box;
        void _update_position();
    };

}
