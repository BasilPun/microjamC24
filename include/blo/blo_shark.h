#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_item.h>

namespace blo
{

    class shark
    {
    public:
        /**
         * shark constructor
         *
         * @param starting_position the location of the shark
         */
        shark(bn::fixed_point starting_position);

        void update();

        // Punches the shark
        void punch();

        // Checks to see if the shark has been punched
        bool punched() const;

        // Checks to see if the shark is fully emerged (Ready to hit)
        bool isEmerged() const;

    private:
        // The sprite to display the shark
        bn::sprite_ptr _sprite;
        bool _punched = false;
        int _frames = 0;

    };
}