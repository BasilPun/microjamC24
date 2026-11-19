#include "luv/luv_player.h"

#include <bn_keypad.h>
#include "bn_sprite_items_luv_fish.h"

namespace luv
{
    /**
     * player constructor
     */
    luv_player::luv_player(bn::fixed_point starting_position, bn::fixed speed) 
    : _sprite(bn::sprite_items::luv_fish.create_sprite(starting_position)),
        _sprite_action(bn::create_sprite_animate_action_forever(
            _sprite, 
            4, 
            bn::sprite_items::luv_fish.tiles_item(), 
            0, 1, 2, 3)),
        _speed(speed),
        _size({16, 16}),
        _bounding_box(generate_bounding_box(_sprite, _size))
    {
    }

    void luv_player::update()
    {
        _update_position();

        if (bn::keypad::any_held())
        {
            _update_animation();
        }
    }

    // Get the player bounding box
    bn::rect luv_player::get_bounding_box()
    {
        return _bounding_box;
    };

    // Set the player bounding box
    void luv_player::set_bounding_box(bn::sprite_ptr _player_sprite, bn::size _player_size)
    {
        _bounding_box = generate_bounding_box(_player_sprite, _player_size);
    };

    /**
     * reads dpad movement
     */
    void luv::luv_player::_update_position()
    {
        if (bn::keypad::left_held())
        {
            _sprite.set_x(_sprite.x() - _speed);
        }
        if (bn::keypad::right_held())
        {
            _sprite.set_x(_sprite.x() + _speed);
        }
        if (bn::keypad::up_held())
        {
            _sprite.set_y(_sprite.y() - _speed);
        }
        if (bn::keypad::down_held())
        {
            _sprite.set_y(_sprite.y() + _speed);
        }

        //Update the bounding box
        set_bounding_box(_sprite, _size);
    }

    void luv::luv_player::_update_animation()
    {
        if (bn::keypad::left_held())
        {
            _sprite_action = bn::create_sprite_animate_action_forever(_sprite, 4, bn::sprite_items::luv_fish.tiles_item(), 0, 1, 2, 3);
        }
        if (bn::keypad::right_held())
        {
            _sprite_action = bn::create_sprite_animate_action_forever(_sprite, 4, bn::sprite_items::luv_fish.tiles_item(), 0, 1, 2, 3);
        }
        if (bn::keypad::up_held())
        {
            _sprite_action = bn::create_sprite_animate_action_forever(_sprite, 4, bn::sprite_items::luv_fish.tiles_item(), 0, 1, 2, 3);
        }
        if (bn::keypad::down_held())
        {
            _sprite_action = bn::create_sprite_animate_action_forever(_sprite, 4, bn::sprite_items::luv_fish.tiles_item(), 0, 1, 2, 3);
        }
        _sprite_action.update();
    }
}