#include "luv/luv_methods.h"

namespace luv {
    /**
     * File that contains commmon methods and variables for the luv classes and interfaces
     */

    //Methods to generate bounding box
    bn::rect generate_bounding_box(bn::sprite_ptr sprite, bn::size box_size) {
        return bn::rect(sprite.x().round_integer(),
                        sprite.y().round_integer(),
                        box_size.width(),
                        box_size.height());
    }
}