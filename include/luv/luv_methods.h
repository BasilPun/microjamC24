#pragma once
#include <bn_rect.h>
// #include <bn_fixed.h>
// #include <bn_random.h>
#include <bn_size.h>
#include <bn_display.h>
#include <bn_sprite_ptr.h>

namespace luv {
    /**
     * File that contains commmon methods and variables for the luv classes and interfaces
     */

    //Set the the bounds of the screen
    static constexpr int MAX_X = bn::display::width() / 2;
    static constexpr int MIN_X = - bn::display::width() / 2;
    static constexpr int MAX_Y = bn::display::height() / 2;
    static constexpr int MIN_Y = - bn::display::height() / 2;

    //Methods to generate bounding box
    bn::rect generate_bounding_box(bn::sprite_ptr sprite, bn::size box_size);
}