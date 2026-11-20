#include "bn_sprite_items_ugb_food.h"

#include "ugb/ugb_food.h"

namespace ugb {

    Food::Food(bn::fixed_point spawn_position) : Entity::Entity(bn::sprite_items::ugb_food, spawn_position, 0) {};

}