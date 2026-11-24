#include "nsj_Enemy.h"
#include "nsj_player.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_items_nsj_fish.h"
#include "bn_sprite_items_nsj_hook.h"
#include <bn_keypad.h>
#include "nsj_boundingBox.h"
#include "bn_rect.h"
namespace nsj
{
    static constexpr bn::size ENEMY_SIZE = {8, 8};

    Enemy::Enemy(bn::fixed x_start, bn::fixed y_start, bn::fixed speed, bn::random &rng) : _sprite(bn::sprite_items::nsj_hook.create_sprite(x_start, y_start)),
                                                                                           _x_speed(speed), _y_speed(speed),
                                                                                           _size(ENEMY_SIZE),
                                                                                           _rng(rng)
    {
        _bounding_box = create_bounding_box(_sprite, _size);
    }

    bn::rect nsj::Enemy::get_bounding_box()
    {
        return _bounding_box;
    }

    void Enemy::update()
    {

        _sprite.set_x(_sprite.x() + _x_speed);

        if (_sprite.x() >= MAX_X)
        {
            _sprite.set_x(MIN_X);
            _sprite.set_y(_rng.get_int(-60, 40));
        }

        else if (_sprite.x() <= MIN_X)
        {
            _sprite.set_x(MAX_X);
            _sprite.set_y(_rng.get_int(-60, 40));
        }

        _bounding_box = create_bounding_box(_sprite, _size);
    }
}
