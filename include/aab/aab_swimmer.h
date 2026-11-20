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
        /**
         * player's swimmer constructor
         *
         * @param starting_position the location to start the swimmer at
         */
        Swimmer(bn::fixed_point starting_position);
        void slow_down();
        void update();
        void set_camera(const bn::camera_ptr& camera);
        void arrows_set_camera(const bn::camera_ptr& camera);
        bn::fixed x() const;
        bn::fixed y() const;

    private:
        bn::sprite_ptr sprite;
        bn::sprite_ptr _up_arrow;
        bn::sprite_ptr _down_arrow;
        bn::sprite_animate_action<4> _animate;

        static constexpr int _swimmer_min_height = 10;
        static constexpr int _swimmer_max_height = 60;
        static constexpr float _forward_speed = 10;
        static constexpr float _move_up = -5;
        static constexpr float _move_down = 5;
        static constexpr bn::fixed _slow_drag = 0.5;
        static constexpr int _slow_duration = 45;

        static constexpr int _debounce = 20;
        static constexpr int _arrow_y_offset = 15;
        int _counter = 0;
        bool _buffer = false;
        int _slow_timer = 0;
        int _button_count = 0;
    };
}