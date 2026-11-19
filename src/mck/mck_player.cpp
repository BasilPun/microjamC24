#include "mck/mck_player.h"

#include <bn_keypad.h>

#include "bn_sprite_items_mck_urchin.h"

#include "bn_sound_items.h"

// All game functions/classes/variables/constants scoped to the namespace
namespace mck {

/**
 * player constructor
 * 
 * @param starting_position the location to start the player at
 * @param speed the pixels/frame the player moves at in each dimension
 */
player::player(bn::fixed_point starting_position, bn::fixed speed) :
    _sprite(bn::sprite_items::mck_urchin.create_sprite(starting_position)),
    _speed(speed)
    {}


void player::update() {
    _update_position();
}

/**
 * Reads from the d-pad and moves the player by one frame accordingly.
 */
void mck::player::_update_position() {
    if(bn::keypad::left_held()) {
        _sprite.set_x(_sprite.x() - _speed);
    }
    if(bn::keypad::right_held()) {
        _sprite.set_x(_sprite.x() + _speed);
    }
    if(bn::keypad::up_held()) {
        _sprite.set_y(_sprite.y() - _speed);
    }
    if(bn::keypad::down_held()) {
        _sprite.set_y(_sprite.y() + _speed);
    }
}

bn::rect player::hitbox() const {
    return bn::rect(_sprite.x().integer(), _sprite.y().integer(), 16, 16);
}

}

