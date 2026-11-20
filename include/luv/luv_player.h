#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_animate_actions.h>
#include <bn_display.h>
#include "luv/luv_methods.h"
#include "luv/luv_anemone.h"

namespace luv {
    // the bounds of the screen
    class luv_player {
        public:
        /**
         * player constructor
         * 
         * @param starting_position the location to spawn the player
         * @param speed the pixels/frame the player moves in each direction.
         */
        luv_player(bn::fixed_point starting_position, bn::fixed speed);

        /**
         * reads keypad inputs to move the character
         */
        void update();

        //Get the player bounding box
        bn::rect get_bounding_box();

        //Set the player bounding box
        void set_bounding_box(bn::sprite_ptr _player_sprite, bn::size _player_size);

        //Get the player
        luv_player get_player();

    private:
     //sprite to display the characters
        bn::sprite_ptr _sprite;
        bn::sprite_animate_action<4> _sprite_action;
        //the pixels the player moves
        bn::fixed _speed;
        bn::size _size;
        bn::rect _bounding_box;
        /**
         * Reads D-pad movement to move the player
         */
        void _update_position();

        /**
         * reads the player dpad movement and updates the sprite animation.
         */
        void _update_animation();
    };
     
}