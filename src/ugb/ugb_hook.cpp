#include "bn_sprite_items_ugb_hook.h"

#include "ugb/ugb_constants.h"
#include "ugb/ugb_hook.h"

namespace ugb {

    Hook::Hook(bn::fixed_point spawn_position, bn::fixed speed) : 
        Entity::Entity(bn::sprite_items::ugb_hook, spawn_position, speed), _going_down(true) {
        };

    void Hook::update() {
        bn::fixed current_y = _sprite.y();

        if (current_y >= constants::hook::MAX_Y) {
            _going_down = false;
        } else if (current_y <= constants::MIN_Y) {
            _going_down = true;
        }

        if (_going_down) {
            _sprite.set_y(current_y + _speed);
        } else {
            _sprite.set_y(current_y - _speed);
        }

        Entity::update();
    }
}