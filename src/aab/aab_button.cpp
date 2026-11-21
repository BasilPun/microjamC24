#include "aab/aab_button.h"
#include "bn_sprite_items_aab_button.h"
#include <bn_camera_ptr.h>

namespace aab
{
    Button::Button(bn::fixed_point starting_position) : 
        _sprite(bn::sprite_items::aab_button.create_sprite(starting_position)),
        _animate(bn::create_sprite_animate_action_forever(_sprite, 16, bn::sprite_items::aab_button.tiles_item(), 0, 1))
    {
    }

    void Button::update(bn::fixed swimmer_x)
    {   
        update_x(swimmer_x);
        _animate.update();
    }

    void Button::set_camera(const bn::camera_ptr& camera){
        _sprite.set_camera(camera);
    }

    void Button::update_x(bn::fixed swimmer_x)
    {   
        _sprite.set_x(swimmer_x);
    }


}