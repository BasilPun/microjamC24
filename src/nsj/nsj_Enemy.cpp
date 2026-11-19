#include "nsj_Enemy.h"
#include "nsj_player.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_items_nsj_fish.h"
#include "bn_sprite_items_nsj_hook.h"
#include <bn_keypad.h>
#include "nsj_boundingBox.h"

static constexpr bn::size ENEMY_SIZE = {8, 8};

Enemy::Enemy(bn::fixed x_start, bn::fixed y_start, bn::fixed speed) : _sprite(bn::sprite_items::nsj_hook.create_sprite(x_start, y_start)),
                                                                      _x_speed(speed), _y_speed(speed),
                                                                      _size(ENEMY_SIZE)
{
    _bounding_box = create_bounding_box(_sprite, _size);
}

void Enemy::update()
{

    _sprite.set_x(_sprite.x() + _x_speed);

    if (_sprite.x() >= MAX_X)
    {
        _x_speed = -_x_speed;
    }
    else if (_sprite.x() <= MIN_X)
    {
        _x_speed = -_x_speed;
    }

    _bounding_box = create_bounding_box(_sprite, _size);
}