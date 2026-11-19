#include "bnc/bnc_minnow.h"
#include <bn_keypad.h>
#include "bn_sprite_items_bnc_minnow_right.h"
#include "bn_sprite_items_bnc_minnow_left.h"
#include "bn_sprite_items_bnc_minnow_up.h"
#include "bn_sprite_items_bnc_minnow_down.h"

namespace bnc {
    //player constructor
    Minnow::Minnow(bn::fixed_point starting_position, bn::fixed speed) :
        _sprite(bn::sprite_items::bnc_minnow_right.create_sprite(starting_position)),
        _speed(speed)
        {}

    bn::rect create_bounding_box(bn::sprite_ptr sprite, bn::size box_size) {
        return bn::rect(sprite.x().round_integer(),
                sprite.y().round_integer(),
                box_size.width(),
                box_size.height());
    }

    bn::sprite_ptr Minnow::get_sprite() {
        return _sprite;
    }

    bn::rect Minnow::get_minnow_hit_box() {
        return _minnow_hit_box;
    }

    void Minnow::update(){
        _update_position();
        //If player tries to go out of bounds, prevent player from going out of bounds
        //If player moves too far right
        if(_sprite.x() > MAX_X) {
            _sprite.set_x(MAX_X);
        }
        //If player moves too far left
        if(_sprite.x() < MIN_X) {
            _sprite.set_x(MIN_X);
        }
        //If player moves too far bottom
        if(_sprite.y() > MAX_Y) {
            _sprite.set_y(MAX_Y);
        }
        //If player moves too far top
        if(_sprite.y() < MIN_Y) {
            _sprite.set_y(MIN_Y);
        }
        _minnow_hit_box = create_bounding_box(_sprite, PLAYER_SIZE);
    }

    bool Minnow::out_of_bounds() const{
        if(_sprite.x() >= MAX_X){
            return true;
        } else {
            return false;
        }
    }

    /**
     * Reads from the d-pad and moves the player by one frame accordingly.
     */
    void bnc::Minnow::_update_position() {
        if(bn::keypad::left_held()) {
            if (_direction != 1){
                _sprite = bn::sprite_items::bnc_minnow_left.create_sprite(_sprite.x(), _sprite.y());
                _direction = 1;
            }
            _sprite.set_x(_sprite.x() - _speed);
        }
        if(bn::keypad::right_held()) {
            if (_direction != 0){
                _sprite = bn::sprite_items::bnc_minnow_right.create_sprite(_sprite.x(), _sprite.y());
                _direction = 0;
            }
            _sprite.set_x(_sprite.x() + _speed);
        }
        if(bn::keypad::up_held()) {
            if (_direction != 2){
                _sprite = bn::sprite_items::bnc_minnow_up.create_sprite(_sprite.x(), _sprite.y());
                _direction = 2;
            }
            _sprite.set_y(_sprite.y() - _speed);
        }
        if(bn::keypad::down_held()) {
            if (_direction != 4){
                _sprite = bn::sprite_items::bnc_minnow_down.create_sprite(_sprite.x(), _sprite.y());
                _direction = 4;
            }
            _sprite.set_y(_sprite.y() + _speed);
        }
    }
}