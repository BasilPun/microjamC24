#pragma once

#include "ugb/ugb_entity.h"

namespace ugb {

    class Hook : public Entity {
        public:
            Hook(bn::fixed_point spawn_position);
    };
    
}