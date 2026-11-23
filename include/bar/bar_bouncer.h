#pragma once

#include <bn_sprite_ptr.h>
#include <bn_display.h>

#include "mj/mj_game.h"

#include "bar/bar_create_bounding_box.h"

#include "bn_sprite_items_bar_bouncer.h"

namespace bar
{
    class bar_bouncer
    {
    public:
        /**
         *  Bouncer constructor that creates sprites at the given coordinates and with randomized speeds. Extends the
         * Butano sprite pointer class bn::sprite_ptr.
         *
         *  @param start_x The starting x coordinate the bouncer spawns at
         *  @param start_y The starting y coordinate the bouncer spawns at
         */
        bar_bouncer(bn::fixed x_start, bn::fixed y_start, bn::fixed base_speed, bn::size bouncer_size);

        /**
         *  Updates the position of the Bouncer sprite by checking whether or not it's position is greater
         * than the bounds of the screen.
         */
        void update();

        bn::rect get_bounding_box() const;

        bool is_collided() const;

        // This is the only instance variable that needs to change outside this class
        void set_collided(bool set_status);

    private:
        // The bounds of the screen
        static constexpr int MAX_X = bn::display::width() / 2;
        static constexpr int MIN_X = -bn::display::width() / 2;
        static constexpr int MAX_Y = bn::display::height() / 2;
        static constexpr int MIN_Y = -bn::display::height() / 2;

        bn::sprite_ptr _sprite;
        bn::fixed _vertical_speed;
        bn::size _size;
        bn::rect _bounding_box;
        bool _collided;
    };
}