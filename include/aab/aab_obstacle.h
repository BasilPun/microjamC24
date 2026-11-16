#pragma once

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
        //sprite vector to hold all sprites
        bn::vector<bn::sprite_ptr, 8> sprites;

        Obstacle(bn::sprite_item log, bn::sprite_item rock, int spawn_amount, bn::random random);
        void update();

        private:
        //map is 512 pixel long.. player spawns at -120,30.
        //let objects be spawned from -80 - 500 pixels.
        static constexpr int swimmer_min_height = 15;
        static constexpr int swimmer_max_height = 55;
        static constexpr int obstacle_min_width = -50;
        static constexpr int obstacle_max_width = 120;
    };
}