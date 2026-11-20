#include "aab/aab_swimmer.h"
#include <bn_keypad.h>
#include "bn_sprite_items_aab_swimmer.h"
#include <bn_camera_ptr.h>
#include "bn_sprite_items_aab_up_down_arrows.h"

namespace aab
{
    Swimmer::Swimmer(bn::fixed_point starting_position) : 
        sprite(bn::sprite_items::aab_swimmer.create_sprite(starting_position)),
        _up_arrow(bn::sprite_items::aab_up_down_arrows.create_sprite(starting_position + bn::fixed_point(0,-_arrow_y_offset), 0)),
        _down_arrow(bn::sprite_items::aab_up_down_arrows.create_sprite(starting_position + bn::fixed_point(0,_arrow_y_offset), 1)),
        _animate(bn::create_sprite_animate_action_forever(sprite, 16, bn::sprite_items::aab_swimmer.tiles_item(), 0, 1, 2, 3))
    {
    }

    void Swimmer::update()
    {   
        _counter ++;
        //set a buffer for going up/down (retro movement feeling)
        if (_counter > _debounce){
            _buffer = false;
            _counter = 0;
        }
        // Swimmer only moves forward when a is pressed
        if(bn::keypad::a_pressed())
        {
            sprite.set_x(sprite.x() + _forward_speed);
            _up_arrow.set_x(_up_arrow.x() + _forward_speed);
            _down_arrow.set_x(_down_arrow.x() + _forward_speed);
        }
        
        // up and down movment via arrow keys
        if(bn::keypad::up_held() && !_buffer)
        {
            sprite.set_y(sprite.y() + _move_up);
            _up_arrow.set_y(_up_arrow.y() + _move_up);
            _down_arrow.set_y(_down_arrow.y() + _move_up);
            _buffer = true;
        }
        if(bn::keypad::down_held() && !_buffer)
        {
            sprite.set_y(sprite.y() + _move_down);
            _up_arrow.set_y(_up_arrow.y() + _move_down);
            _down_arrow.set_y(_down_arrow.y() + _move_down);
            _buffer = true;
        }

        //Bounding box / lane restriction to keep swimmer out of dolphin's lane
        if(sprite.y() < _swimmer_min_height)
        {
            sprite.set_y(_swimmer_min_height);
            _up_arrow.set_y(_swimmer_min_height -_arrow_y_offset);
            _down_arrow.set_y(_swimmer_min_height +_arrow_y_offset);
        }
        if(sprite.y() > _swimmer_max_height)
        {
            sprite.set_y(_swimmer_max_height);
            _up_arrow.set_y(_swimmer_max_height -_arrow_y_offset);
            _down_arrow.set_y(_swimmer_max_height +_arrow_y_offset);
        }

        //Apply slow-down drag while timer is active
        if(_slow_timer > 0)
        {
            _slow_timer--;
            sprite.set_x(sprite.x() - _slow_drag);
            _up_arrow.set_y(_up_arrow.y() - _slow_drag);
            _down_arrow.set_y(_down_arrow.y() - _slow_drag);

        }

        _animate.update();
    }

    void Swimmer::slow_down()
    {
        if(_slow_timer == 0)
        {
            _slow_timer = _slow_duration;
        }
    }

    void Swimmer::set_camera(const bn::camera_ptr& camera){
        sprite.set_camera(camera);
    }

    void Swimmer::arrows_set_camera(const bn::camera_ptr& camera){
        _up_arrow.set_camera(camera);
        _down_arrow.set_camera(camera);
    }

    bn::fixed Swimmer::x() const{
        return sprite.x();
    }

    bn::fixed Swimmer::y() const{
        return sprite.y();
    }
}