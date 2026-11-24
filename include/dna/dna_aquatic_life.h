#pragma once

#include "dna/dna_player.h"

#include <bn_fixed.h>
#include <bn_random.h>

namespace dna {
    class AquaticLife {
        static constexpr int MAX_X = bn::display::width() / 2;
        static constexpr int MIN_X = - bn::display::width() / 2;
        static constexpr int MAX_Y = bn::display::height() / 2;
        static constexpr int MIN_Y = - bn::display::height() / 2;
        
        public: 
            AquaticLife(bn::random &random, bn::fixed speed, bn::size size); 
            
            bool update(Player &player);
            bool is_offscreen() const; 
        
            bn::fixed_point getStartPosition(bn::random &random); 
        private: 
            bn::sprite_ptr _sprite;  
            bn::fixed _speed; 
            bn::rect _hitbox;
            bn::size _size;
    };
}
