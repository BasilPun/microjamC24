#pragma once

#include <bn_vector.h>

#include "ugb/ugb_constants.h"
#include "ugb/ugb_entity.h"
#include "ugb/ugb_hook.h"
#include "ugb/ugb_food.h"

namespace ugb {

    class GameState {

        public:
            bn::vector<Hook, constants::MAX_ENTITIES> hooks;
            bn::vector<Food, constants::MAX_ENTITIES> food;
            bn::vector<Entity, constants::MAX_ENTITIES> other_entities;
            bn::vector<bn::sprite_ptr, constants::MAX_SCORE_CHARS> score_sprites;
            int score = 0;

    };

}