#include "dna_hitbox.h"
#include "dna_player.h"

namespace dna {
    bn::rect create_hitbox(bn::sprite_ptr sprite, bn::size box_size) {
        return bn::rect(
            sprite.x().round_integer(), 
            sprite.y().round_integer(), 
            box_size.width(), 
            box_size.height()
        );
    }
}