#pragma once

#include <bn_display.h>
#include <bn_rect.h>
#include <bn_sprite_ptr.h>



namespace dna {
    static constexpr bn::size PLAYER_SIZE = {8, 8};

    class Player {
        // Define the bounds of the screen
        static constexpr int MAX_X = bn::display::width() / 2;
        static constexpr int MIN_X = - bn::display::width() / 2;
        static constexpr int MAX_Y = bn::display::height() / 2;
        static constexpr int MIN_Y = - bn::display::height() / 2;

        public:

            Player(bn::fixed_point starting_pos, bn::fixed speed, bn::size size);
            void update(); 

            bn::rect get_hitbox(); 

        private: 
            bn::sprite_ptr _sprite; 
            bn::fixed _speed; 
            bn::size _size; 
            bn::rect _hitbox;

            void _update_position(); 
    };
}
