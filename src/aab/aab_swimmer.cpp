#include "aab/aab_swimmer.h"
#include <bn_keypad.h>
#include "bn_sprite_items_swimmer.h"

namespace aab
{
    Swimmer::Swimmer(bn::fixed_point starting_position) : sprite(bn::sprite_items::swimmer.create_sprite(starting_position)), animate(bn::create_sprite_animate_action_forever(sprite, 16, bn::sprite_items::swimmer.tiles_item(), 0, 1, 2, 3))
    {
    }

    void Swimmer::update()
    {
        animate.update();
    }
}