#include "luv/luv_trap.h"
#include "bn_sprite_items_luv_trap.h"

namespace luv {
    
    luv_trap::luv_trap(bn::fixed_point spawn) : 
    _sprite(bn::sprite_items::luv_trap.create_sprite(spawn)), _size({ANEMONE_SIZE,ANEMONE_SIZE}),
    _bounding_box(generate_bounding_box(_sprite, _size)) {

    }
    
    //Get the trap anemone bounding box
     bn::rect luv_trap::get_bounding_box() {
        return _bounding_box;
    };
}