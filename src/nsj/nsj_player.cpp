#include "nsj_player.h"
#include "bn_sprite_ptr.h"
#include <bn_keypad.h>
#include "bn_sprite_items_nsj_hook.h"
#include "bn_sprite_items_nsj_fish.h"
#include "nsj_boundingBox.h"

#include "bn_sound_items.h"

namespace nsj
{
    static constexpr bn::size PLAYER_SIZE = {8, 8};

    /**
     * player constructor
     *
     * @param starting_position the location to start the player at
     * @param speed the pixels/frame the player moves at in each dimension
     */
    player::player(bn::fixed_point starting_position, bn::fixed speed) : _sprite(bn::sprite_items::nsj_fish.create_sprite(starting_position)),
                                                                         _sprite_action(bn::create_sprite_animate_action_forever(_sprite, 16, bn::sprite_items::nsj_fish.tiles_item(), 0, 1, 2, 3)),
                                                                         _size(PLAYER_SIZE),
                                                                         _speed(speed)
    {
        _bounding_box = create_bounding_box(_sprite, _size);
    }

    bn::rect nsj::player::get_bounding_box()
    {
        return _bounding_box;
    }

    void player::update()
    {
        _update_position();
    }

    bn::fixed_point nsj::player::get_position()
    {
        return _sprite.position();
    }

    /**
     * Reads from the d-pad and moves the player by one frame accordingly.
     */
    void nsj::player::_update_position()
    {
        if (bn::keypad::left_held())
        {
            _sprite.set_x(_sprite.x() - _speed);
            _sprite.set_horizontal_flip(false);
        }
        if (bn::keypad::right_held())
        {
            _sprite.set_x(_sprite.x() + _speed);
            _sprite.set_horizontal_flip(true);
        }
        if (bn::keypad::up_held())
        {
            _sprite.set_y(_sprite.y() - _speed);
        }
        if (bn::keypad::down_held())
        {
            _sprite.set_y(_sprite.y() + _speed);
        }
        if (_sprite.x() > MAX_X)
        {
            _sprite.set_x(MIN_X);
        }
        else if (_sprite.x() < MIN_X)
        {
            _sprite.set_x(MAX_X);
        }

        if (_sprite.y() > MAX_Y)
        {
            _sprite.set_y(MIN_Y);
        }
        else if (_sprite.y() < MIN_Y)
        {
            _sprite.set_y(MAX_Y);
        }
        _bounding_box = create_bounding_box(_sprite, _size);
    }

}