#pragma once

#include <bn_display.h>
#include <bn_sprite_ptr.h>
#include <bn_rect.h>
#include <bn_fixed.h>
#include <bn_size.h>
#include "luv/luv_methods.h"

// Create a namespace to ensure all variables within are scoped to the instance.
namespace luv
{
    class luv_trap
    {

        /**
         * Trap nemone constructor
         */
    public:
        luv_trap(bn::fixed_point spawn);

        bn::rect get_bounding_box();

    private:
        static constexpr int ANEMONE_SIZE = 16;
        bn::sprite_ptr _sprite;
        bn::size _size;
        bn::rect _bounding_box; // Bounding box of the trap anemone
    };
}