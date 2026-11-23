#include "bar/bar_spawn_bouncer.h"

namespace bar
{

    void bar_spawn_bouncer(bn::vector<bar_bouncer, MAX_BOUNCERS> &bouncers, bn::fixed x_start, bn::fixed y_start, bn::fixed base_speed, bn::size bouncer_size)
    {
        if (bouncers.size() < MAX_BOUNCERS)
        {
            bar_bouncer bouncer = bar_bouncer(x_start, y_start, base_speed, bouncer_size);
            bouncers.push_back(bouncer);
        }
    }

}