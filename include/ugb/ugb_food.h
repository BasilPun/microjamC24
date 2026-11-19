#pragma once

#include "ugb/ugb_entity.h"

namespace ugb {

    class Food : public Entity {
        public:
            Food(bn::fixed_point spawn_position);
    };
    
}