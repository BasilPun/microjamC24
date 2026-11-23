#pragma once

#include "aab_swimmer.h"
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_item.h>
#include <bn_vector.h>
#include <bn_random.h>

namespace aab
{
    class Obstacle
    {
        public:
        Obstacle(bn::sprite_item log, bn::sprite_item rock, int spawn_amount, bn::random random);

        void update(Swimmer &swimmer, int &slow_timer);
        void set_camera(const bn::camera_ptr& camera);
        bn::fixed x() const;
        bn::fixed y() const;
        void collisionCheck(Swimmer &swimmer, int &slow_timer);

        private:
        //sprite vector to hold all sprites
        bn::vector<bn::sprite_ptr, 8> _sprites;
        //animation for explosion
        bn::optional<bn::sprite_ptr> _explosion;
        int _explosion_timer;
        //map is 512 pixel long.. player spawns at -120,30.
        //let objects be spawned from -80 - 500 pixels.
        static constexpr int _swimmer_min_height = 15;
        static constexpr int _swimmer_max_height = 55;
        static constexpr int _obstacle_min_width = -50;
        static constexpr int _obstacle_max_width = 120;

        static constexpr int _collison_radius = 12;
        void _collisionCheck(Swimmer &swimmer, int &slow_timer);
    };
}