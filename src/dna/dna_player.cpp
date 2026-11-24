#include "dna/dna_player.h"
#include "dna/dna_hitbox.h"

#include <bn_keypad.h>

#include "bn_sprite_items_dna_player.h"

namespace dna {
    static constexpr int PLAYER_BORDER = 4; 

    Player::Player(bn::fixed_point starting_pos, bn::fixed speed, bn::size size) :
    _sprite(bn::sprite_items::dna_player.create_sprite(starting_pos)),
    _speed(speed),
    _size(size), 
    _hitbox(create_hitbox(_sprite, size)) {}
    
    void Player::update() {
        _update_position(); 
    }

    void Player::_update_position() {
        // Player Movement
        if (bn::keypad::left_held()) {
            _sprite.set_x(_sprite.x() - _speed);
        } 
        if (bn::keypad::right_held()) {
            _sprite.set_x(_sprite.x() + _speed);
        } 
        if (bn::keypad::up_held()) {
            _sprite.set_y(_sprite.y() - _speed);
        }
        if (bn::keypad::down_held()) {
            _sprite.set_y(_sprite.y() + _speed);
        }

        // Screen Border
        if (_sprite.x() > MAX_X - PLAYER_BORDER) {
        _sprite.set_x(MAX_X - PLAYER_BORDER);
        }
        if(_sprite.x() < MIN_X + PLAYER_BORDER){
            _sprite.set_x(MIN_X + PLAYER_BORDER);
        }
        if(_sprite.y() > MAX_Y - PLAYER_BORDER) {
            _sprite.set_y(MAX_Y - PLAYER_BORDER);
        }
        if(_sprite.y() < MIN_Y + PLAYER_BORDER){
            _sprite.set_y(MIN_Y + PLAYER_BORDER);
        }

        _hitbox = create_hitbox(_sprite, _size);
    }

    bn::rect Player::get_hitbox() {
        return _hitbox;
    }
}