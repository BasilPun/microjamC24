#include "luv/luv_anemone.h"
#include "bn_sprite_items_luv_anemone.h"

namespace luv {
    
    luv_anemone::luv_anemone(bn::fixed_point spawn) : 
    _sprite(bn::sprite_items::luv_anemone.create_sprite(spawn)), _size({16, 16}),
    _bounding_box(generate_bounding_box(_sprite, _size)) {

    }
    
    //Get the player bounding box
     bn::rect luv_anemone::get_bounding_box() {
        return _bounding_box;
    };
}