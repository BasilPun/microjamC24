#include "aab/aab_swimmer.h"
#include <bn_keypad.h>
#include "bn_sprite_items_aab_swimmer.h"
#include <bn_camera_ptr.h>

namespace aab
{
    Swimmer::Swimmer(bn::fixed_point starting_position) : 
        _sprite(bn::sprite_items::aab_swimmer.create_sprite(starting_position)),
        _animate(bn::create_sprite_animate_action_forever(_sprite, 16, bn::sprite_items::aab_swimmer.tiles_item(), 0, 1, 2, 3))
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
            _sprite.set_x(_sprite.x() + _forward_speed);
        }
        
        // up and down movment via arrow keys
        if(bn::keypad::up_held() && !_buffer)
        {
            _sprite.set_y(_sprite.y() + _move_up);
            _buffer = true;
        }
        if(bn::keypad::down_held() && !_buffer)
        {
            _sprite.set_y(_sprite.y() + _move_down);
            _buffer = true;
        }

        //Bounding box / lane restriction to keep swimmer out of dolphin's lane
        if(_sprite.y() < _swimmer_min_height)
        {
            _sprite.set_y(_swimmer_min_height);
        }
        if(_sprite.y() > _swimmer_max_height)
        {
            _sprite.set_y(_swimmer_max_height);
        }

        //Apply slow-down drag while timer is active
        if(_slow_timer > 0)
        {
            _slow_timer--;
            _sprite.set_x(_sprite.x() - _slow_drag);
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
        _sprite.set_camera(camera);
    }

    bn::fixed Swimmer::x() const{
        return _sprite.x();
    }

    bn::fixed Swimmer::y() const{
        return _sprite.y();
    }
}