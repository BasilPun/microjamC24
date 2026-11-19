#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_display.h>
#include <bn_rect.h>

// All game functions/classes/variables/constants scoped to the namespace
namespace mck {

/**
 * A character controlled with the d-pad.
 */
class enemy {
        // The bounds of the screen
        static constexpr int MAX_X = bn::display::width() / 2;
        static constexpr int MIN_X = - bn::display::width() / 2;
        static constexpr int MAX_Y = bn::display::height() / 2;
        static constexpr int MIN_Y = - bn::display::height() / 2;

    public:
        /**
         * enemy constructor
         * 
         * @param starting_position the location to start the enemy at
         * @param xspeed the enemy's speed in the x direction
         * @param yspeed the enemy's speed in the y direction
         */
        enemy(bn::fixed_point starting_position, bn::fixed xspeed, bn::fixed yspeed);

        bn::rect hitbox() const;

        /**
         * Moves the enemy based on its x and y speed
         */
        void update();
    
    private:
        // The sprite to display the enemy
        bn::sprite_ptr _sprite;
        // The pixels/frame the enemy moves in each dimension
        bn::fixed _xspeed;
        bn::fixed _yspeed;

        /**
         * Moves the enemy based on its current x and y speeds
         */
        void _update_position();
        
};

}
