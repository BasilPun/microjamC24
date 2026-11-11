#include "aab/aab_dolphin.h"
#include "bn_sprite_items_dolphin.h"

namespace aab
{
    /**
     * Dolphin constructor
     *
     * @param starting_position the location the dolphin starts at
     */
    Dolphin::Dolphin(bn::fixed_point starting_position) : sprite(bn::sprite_items::dolphin.create_sprite(starting_position)),
                                                          animate(bn::create_sprite_animate_action_forever(sprite, 10, bn::sprite_items::dolphin.tiles_item(), 0, 1, 2, 3, 4, 5))
    {
    }

    void Dolphin::update()
    {
        // animates dolphin sprite
        animate.update();
        update_position(speed);
    }

    void Dolphin::update_position(bn::fixed dolphin_speed)
    {
        sprite.set_x(sprite.x() + dolphin_speed);
    }
}