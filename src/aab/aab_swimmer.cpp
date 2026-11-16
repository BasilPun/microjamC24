#include "aab/aab_swimmer.h"
#include <bn_keypad.h>
#include "bn_sprite_items_aab_swimmer.h"

namespace aab
{
    Swimmer::Swimmer(bn::fixed_point starting_position) : 
        sprite(bn::sprite_items::aab_swimmer.create_sprite(starting_position)),
        animate(bn::create_sprite_animate_action_forever(sprite, 16, bn::sprite_items::aab_swimmer.tiles_item(), 0, 1, 2, 3))
    {
    }

    void Swimmer::update()
    {   
        counter ++;
        //set a buffer for going up/down (retro movement feeling)
        if (counter > debounce){
            buffer = false;
            counter = 0;
        }
        // Swimmer only moves forward when a is pressed
        if(bn::keypad::a_pressed())
        {
            sprite.set_x(sprite.x() + forward_speed);
        }
        
        // up and down movment via arrow keys
        if(bn::keypad::up_held() && !buffer)
        {
            sprite.set_y(sprite.y() + move_up);
            buffer = true;
        }
        if(bn::keypad::down_held() && !buffer)
        {
            sprite.set_y(sprite.y() + move_down);
            buffer = true;
        }

        //Bounding box / lane restriction to keep swimmer out of dolphin's lane
        if(sprite.y() < swimmer_min_height)
        {
            sprite.set_y(swimmer_min_height);
        }
        if(sprite.y() > swimmer_max_height)
        {
            sprite.set_y(swimmer_max_height);
        }

        animate.update();
    }
}