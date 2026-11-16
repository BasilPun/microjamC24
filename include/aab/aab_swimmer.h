#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_animate_actions.h>

namespace aab
{
    /**
     * A character controlled by up/down arrows & "A" button
     */
    class Swimmer
    {
    public:
        bn::sprite_ptr sprite;

        /**
         * player's swimmer constructor
         *
         * @param starting_position the location to start the swimmer at
         */
        Swimmer(bn::fixed_point starting_position);
        void update();
        void slow_down();

    private:
        bn::sprite_animate_action<4> animate;
        static constexpr int swimmer_min_height = 10;
        static constexpr int swimmer_max_height = 60;
        static constexpr float forward_speed = 10;
        static constexpr float move_up = -5;
        static constexpr float move_down = 5;
        static constexpr bn::fixed slow_drag = 0.5;
        static constexpr int slow_duration = 45;
        
        static constexpr int debounce = 20;
        int counter = 0;
        bool buffer = false;
        int slow_timer = 0;
    };
}