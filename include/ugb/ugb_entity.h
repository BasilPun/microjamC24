#pragma once

#include <bn_rect.h>
#include <bn_sprite_ptr.h>

namespace ugb {
    // Base class for entities (sprite_ptr w/ speed, bounding box, etc)
    class Entity {
        public:
            Entity(bn::sprite_item sprite_item, bn::fixed starting_x, bn::fixed starting_y, bn::fixed starting_speed);
            Entity(bn::sprite_item sprite_item, bn::fixed_point starting_position, bn::fixed starting_speed);

            virtual void update();

            bn::fixed x() const; // Get the Entity's x position
            bn::fixed y() const; // Get the Entity's y position
            bn::rect bounding_box() const; // Get the Entity's bounding box

            virtual ~Entity() = default;

        protected:
            bn::sprite_ptr _sprite;
            bn::fixed _speed; // Movement speed
            bn::rect _bounding_box; // Rectangle drawn around sprite for collision
    };
}