#pragma once

#include "ugb/ugb_entity.h"

namespace ugb
{

    class Player : public Entity
    {
    public:
        // player needs position and speed
        Player(bn::fixed start_x, bn::fixed start_y, bn::fixed speed);

        // update
        void update() override;

    private:
        int _animation_counter;
        bool _is_fish2;

        void _update_position();
        void _update_animation();
    };

}