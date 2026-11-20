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
        void update();
        void set_camera(const bn::camera_ptr& camera);

    private:
        bn::sprite_ptr _sprite;
        bn::sprite_animate_action<2> _animate;
    };
}