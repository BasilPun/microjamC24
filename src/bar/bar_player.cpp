#include "bar_player.h"

namespace bar
{
    bar_player::bar_player(bn::fixed player_position_x, bn::fixed player_position_y, bn::size player_size) : _sprite(bn::sprite_items::bar_box.create_sprite(player_position_x, player_position_y)),
                                                                                                             _sprite_action(bn::create_sprite_animate_action_forever(_sprite, 16, bn::sprite_items::bar_box.tiles_item(), 0, 1, 2, 3)),
                                                                                                             _size(player_size), _bounding_box(bar_create_bounding_box(_sprite, player_size))
    {
    }

    void bar_player::update(bar_bouncer &bouncer)
    {
        if (bn::keypad::l_pressed() && _bounding_box.intersects(bouncer.get_bounding_box()))
        {
            bouncer.set_collided(true);
        }

        if(bn::keypad::r_pressed() && _bounding_box.intersects(bouncer.get_bounding_box())) {
            bouncer.set_collided(true);
        }
        _bounding_box = bar_create_bounding_box(_sprite, _size);
    }

    void bar::bar_player::_update_animation()
    {
    }
}
