#pragma once

#include <bn_fixed_point.h>
#include <bn_random.h>

#include "ugb/ugb_game_state.h"

namespace ugb {

    bool _check_if_safe(bn::fixed spawn_x, bn::fixed spawn_y, Entity& entity);

    bn::fixed_point get_safe_spawn_loc(bn::random& random, GameState& state);

}