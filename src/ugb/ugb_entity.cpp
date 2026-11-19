#include <bn_sprite_item.h>

#include "ugb/ugb_common.h"
#include "ugb/ugb_entity.h"

namespace ugb
{

    Entity::Entity(bn::sprite_item sprite_item, bn::fixed starting_x, bn::fixed starting_y, bn::fixed starting_speed) : 
        _sprite(sprite_item.create_sprite(starting_x, starting_y)), 
        _speed(starting_speed), 
        _bounding_box(create_bounding_box(_sprite, _sprite.dimensions())) {};

    Entity::Entity(bn::sprite_item sprite_item, bn::fixed_point starting_position, bn::fixed starting_speed) : 
        Entity(sprite_item, starting_position.x(), starting_position.y(), starting_speed) {};

    void Entity::update()
    {
        _bounding_box = create_bounding_box(_sprite, _sprite.dimensions());
    }

    bn::fixed Entity::x() const
    {
        return _sprite.x();
    }

    bn::fixed Entity::y() const
    {
        return _sprite.y();
    }

    bn::rect Entity::bounding_box() const
    {
        return _bounding_box;
    }

}