#pragma once
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_display.h>
#include <bn_rect.h>

#include "nsj_player.h"

class Enemy
{
    static constexpr int MAX_X = bn::display::width() / 2;
    static constexpr int MIN_X = -bn::display::width() / 2;

private:
    bn::sprite_ptr _sprite;
    bn::fixed _x_speed;
    bn::fixed _y_speed;
    bn::size _size;
    bn::rect _bounding_box;

public:
    Enemy(bn::fixed x_start, bn::fixed y_start, bn::fixed speed);
    void update();
};