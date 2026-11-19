#pragma once

#include <bn_vector.h>
#include "ugb/ugb_constants.h"
#include "ugb/ugb_food.h"

namespace ugb {
    class FoodManager {
        public: 
            FoodManager();

            int collect_food(bn::vector<Food, constants::MAX_ENTITIES>& food, const bn::rect& player_box);
    };
}