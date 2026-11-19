#pragma once

#include <bn_vector.h>

#include "ugb/ugb_food_manager.h"
#include "ugb/ugb_hook.h"

namespace ugb {

    class GameState {

        public:
            bn::vector<Hook, constants::MAX_ENTITIES> hooks;
            bn::vector<Food, constants::MAX_ENTITIES> food;
            bn::vector<Entity, constants::MAX_ENTITIES> other_entities;
            bn::vector<bn::sprite_ptr, constants::MAX_SCORE_CHARS> score_sprites;

            FoodManager food_manager;

            bool hit_hook = false;
            int score = 0;

            int required_score = 0;
            int hook_count = 0;
    };

}