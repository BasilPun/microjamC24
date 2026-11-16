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
        //continous slow forward movement from left to right
        sprite.set_x(sprite.x()+0.5);

        //up and down movment via arrow keys
        if(bn::keypad::up_held())
        {
            sprite.set_y(sprite.y() - 1);
        }
        if(bn::keypad::down_held())
        {
            sprite.set_y(sprite.y() + 1);
        }

        // A button gives a speed boost to help race forward
        if(bn::keypad::a_held()|| bn::keypad::a_pressed())
        {
            sprite.set_x(sprite.x() + 0.6);
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