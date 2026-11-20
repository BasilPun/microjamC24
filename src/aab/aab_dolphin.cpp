#include "aab/aab_dolphin.h"
#include "bn_sprite_items_aab_dolphin.h"
#include <bn_camera_ptr.h>

namespace aab
{
    /**
     * Dolphin constructor
     *
     * @param starting_position the location the dolphin starts at
     */
    Dolphin::Dolphin(bn::fixed_point starting_position, bn::fixed dolphin_speed) : 
        sprite(bn::sprite_items::aab_dolphin.create_sprite(starting_position)),
        _animate(bn::create_sprite_animate_action_forever(sprite, 10, bn::sprite_items::aab_dolphin.tiles_item(), 0, 1, 2, 3, 4, 5)),
        _speed(dolphin_speed)
    {
        //set different speeds for easy, medium, hard
    }

    void Dolphin::update()
    {
        // animates dolphin sprite
        _animate.update();
        _update_position(_speed);
    }

    void Dolphin::_update_position(bn::fixed dolphin_speed)
    {
        sprite.set_x(sprite.x() + dolphin_speed);
    }

    void Dolphin::set_camera(const bn::camera_ptr& camera){
        sprite.set_camera(camera);
    }

    bn::fixed Dolphin::x() const{
        return sprite.x();
    }

    bn::fixed Dolphin::y() const{
        return sprite.y();
    }
}