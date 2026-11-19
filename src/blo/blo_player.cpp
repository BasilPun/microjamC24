#include "blo/blo_player.h"
#include "blo/blo_shark.h"

#include <bn_keypad.h>

namespace blo {
    /**
     * player constructor
     */
    player::player()
    {
    }

    void player::update(shark& target) {
        if (bn::keypad::a_pressed()){
            if(target.isEmerged()){
                target.punch();
            }
        }
    }

    bool player::hasSnack() const {
        return _has_snack;

    }

}