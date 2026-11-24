#pragma once

#include <bn_sprite_ptr.h>
#include <bn_fixed.h>
#include <bn_fixed_point.h>
#include <bn_size.h>
#include <bn_rect.h>
#include <bn_display.h>

namespace bnc {
    // Width and height of the the player bounding box
    static constexpr bn::size PLAYER_SIZE = {8, 8};

    //Starting position of the player
    static constexpr int X_START = -90;
    static constexpr int Y_START = 0;

    //Speed of the player
    static constexpr bn::fixed SPEED = 1;

    static constexpr int MIN_Y = -bn::display::height() / 2;
    static constexpr int MAX_Y = bn::display::height() / 2;
    static constexpr int MIN_X = -bn::display::width() / 2;        
    static constexpr int MAX_X = bn::display::width() / 2;

    bn::rect create_bounding_box(bn::sprite_ptr sprite, bn::size box_size);

    class Squid {
        public:
        //constructor
        Squid(bn::fixed_point starting_position, bn::fixed speed);

        //getter functions
        bn::fixed_point get_position();
        bn::rect get_squid_hit_box();

        void update();
        bool out_of_bounds() const;

        private:
        // The sprite to display the player
        bn::sprite_ptr _sprite;
        bn::rect _squid_hit_box;    
        bn::fixed _speed;

        //direction number for the squid sprite to change
        // depending on what keypad is pushed
        int _direction;

        /**
         * Reads from the d-pad and moves the player by one frame accordingly.
         */
        void _update_position();
    };
}