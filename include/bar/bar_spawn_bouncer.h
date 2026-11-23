#pragma once

#include <bn_vector.h>

#include "bar/bar_bouncer.h"
#include "bar/bar_player.h"
#include "bar_constants.h"

namespace bar {

    void bar_spawn_bouncer(bn::vector<bar_bouncer, MAX_BOUNCERS> &bouncers, bn::fixed x_start, bn::fixed y_start, bn::fixed base_speed, bn::size bouncer_size);

}