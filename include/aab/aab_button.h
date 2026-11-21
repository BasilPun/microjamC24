#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_animate_actions.h>

namespace aab
{
    class Button
    {
    public:
        Button(bn::fixed_point starting_position);
        void update(bn::fixed swimmer_x);
        void set_camera(const bn::camera_ptr& camera);
        void update_x(bn::fixed swimmer_x);

    private:
        bn::sprite_ptr _sprite;
        bn::sprite_animate_action<2> _animate;
    };
}