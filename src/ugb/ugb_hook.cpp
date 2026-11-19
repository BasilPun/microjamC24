#include "bn_sprite_items_ugb_hook.h"

#include "ugb/ugb_hook.h"

namespace ugb {

    Hook::Hook(bn::fixed_point spawn_position) : Entity::Entity(bn::sprite_items::ugb_hook, spawn_position, 0) {};

}