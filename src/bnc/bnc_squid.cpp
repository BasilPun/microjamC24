#include "bnc/bnc_squid.h"
#include <bn_keypad.h>
#include "bn_sprite_items_bnc_squid_right.h"
#include "bn_sprite_items_bnc_squid_left.h"
#include "bn_sprite_items_bnc_squid_up.h"
#include "bn_sprite_items_bnc_squid_down.h"

namespace bnc {
    //player constructor
    Squid::Squid(bn::fixed_point starting_position, bn::fixed speed) :
        _sprite(bn::sprite_items::bnc_squid_right.create_sprite(starting_position)),
        _speed(speed)
        {}

    //returns squid's sprite pointer
    bn::fixed_point Squid::get_position() {
        return (_sprite.position());
    }

    //returns squid's hit box
    bn::rect Squid::get_squid_hit_box() {
        return _squid_hit_box;
    }

    //creates squid's bounding box
    bn::rect create_bounding_box(bn::sprite_ptr sprite, bn::size box_size) {
        return bn::rect(sprite.x().round_integer(),
                        sprite.y().round_integer(),
                        box_size.width(),
                        box_size.height());
         }

    void Squid::update(){
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
        _squid_hit_box = create_bounding_box(_sprite, PLAYER_SIZE);
    }

    //Checks if the squid has reached the opposite side of the screen
    bool Squid::out_of_bounds() const{
        if(_sprite.x() >= MAX_X){
            return true;
        } else {
            return false;
        }
    }

    /**
     * Reads from the d-pad and moves the player by one frame accordingly.
     */
    void bnc::Squid::_update_position() {
        //Conditional statements for direction change
        //add direction checker
        if(bn::keypad::left_held()) {
            if (_direction != 1){
                _sprite = bn::sprite_items::bnc_squid_left.create_sprite(_sprite.x(), _sprite.y());
                _direction = 1;
            }
            _sprite.set_x(_sprite.x() - _speed);
        }
        if(bn::keypad::right_held()) {
            if (_direction != 0){
                _sprite = bn::sprite_items::bnc_squid_right.create_sprite(_sprite.x(), _sprite.y());
                _direction = 0;
            }
            _sprite.set_x(_sprite.x() + _speed);
        }
        if(bn::keypad::up_held()) {
            if (_direction != 2){
                _sprite = bn::sprite_items::bnc_squid_up.create_sprite(_sprite.x(), _sprite.y());
                _direction = 2;
            }
            _sprite.set_y(_sprite.y() - _speed);
        }
        if(bn::keypad::down_held()) {
            if (_direction != 4){
                _sprite = bn::sprite_items::bnc_squid_down.create_sprite(_sprite.x(), _sprite.y());
                _direction = 4;
            }
            _sprite.set_y(_sprite.y() + _speed);
        }
    }
}