#include "aab/dolphin.h"
#include "bn_sprite_items_dolphin.h"

namespace aab
{
    /**
     * Dolphin constructor
     *
     * @param starting_position the location the dolphin starts at
     * @param speed how fast the dolphin will move across the screen
     */
    Dolphin::Dolphin(bn::fixed_point starting_position, bn::fixed speed) : sprite(bn::sprite_items::dolphin.create_sprite(starting_position)),
                                                                           animate(bn::create_sprite_animate_action_forever(sprite, 2, bn::sprite_items::dolphin.tiles_item(), 0, 1, 2, 3, 4, 5)),
                                                                           speed(speed)
    {
    }

    void Dolphin::update()
    {
        // animates dolphin sprite
        animate.update();
    }
}