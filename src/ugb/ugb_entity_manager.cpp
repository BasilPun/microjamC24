#include <bn_math.h>

#include "ugb/ugb_constants.h"
#include "ugb/ugb_entity_manager.h"

namespace ugb {

    bool _check_if_safe(bn::fixed spawn_x, bn::fixed spawn_y, Entity& entity) {
        bn::fixed dx = bn::abs(spawn_x - entity.x());
        bn::fixed dy = bn::abs(spawn_y - entity.y());
        if (dx < constants::spawn::MIN_DISTANCE || dy < constants::spawn::MIN_DISTANCE) {
            return false;
        }
        return true;
    }

    bn::fixed_point get_safe_spawn_loc(bn::random& random, GameState& state) {
        bn::fixed spawn_x, spawn_y;
        bn::fixed_point spawn_point(constants::MAX_X, 0);
        bool safe;

        for (int i = 0; i < constants::spawn::MAX_ATTEMPTS; i++) {
            safe = true;
            // Choose a spawn location within the screen bounds (+ padding so the sprite stays on screen)
            spawn_x = random.get_unbiased_int(constants::spawn::MIN_X, constants::spawn::MAX_X);
            spawn_y = random.get_unbiased_int(constants::spawn::MIN_Y, constants::spawn::MAX_Y);

            for (Entity& entity : state.hooks) {
                safe = _check_if_safe(spawn_x, spawn_y, entity);
            }
            for (Entity& entity : state.food) {
                safe = _check_if_safe(spawn_x, spawn_y, entity);
            }
            for (Entity& entity : state.other_entities) {
                safe = _check_if_safe(spawn_x, spawn_y, entity);
            }

            if (safe) {
                spawn_point.set_x(spawn_x);
                spawn_point.set_y(spawn_y);
                break;
            }
        }
        return spawn_point;
    }
}