#pragma once

#include <bn_fixed_rect.h>
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_display.h>

// Namespace used for the cia project
namespace cia
{
    /**
     * Values used for finding the sides of the gba screen
     */
    static constexpr int MAX_X = bn::display::width() / 2;
    static constexpr int MIN_X = -bn::display::width() / 2;
    static constexpr int MAX_Y = bn::display::height() / 2;
    static constexpr int MIN_Y = -bn::display::height() / 2;

    /**
     * The character of our main game. This represents the scuba guy
     */
    class player
    {
    public:
        /**
         * The constructor of the class. It takes a starting position and a set speed.
         *
         * @param starting_position The starting position of the player
         * @param speed The speed of the player. It's fixed
         */
        player(bn::fixed_point starting_position, bn::fixed speed);

        /**
         * Used to update the player every frame.
         */
        void update();

        /**
         * Returns a "box" of the player. Used for when checking if a specific entity overlaps with the player
         *
         * @return A bn::fixed_rect of the player
         */
        bn::fixed_rect rect() const;

    private:
        // The player sprite
        bn::sprite_ptr _sprite;

        // The speed of the player
        bn::fixed _speed;
    };
}