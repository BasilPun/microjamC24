#include "cia_shark.h"
#include "cia_player.h"

#include "bn_sprite_items_cia_shark.h"

#include <bn_random.h>
#include <bn_fixed_point.h>
#include <bn_array.h>

namespace cia
{
    static constexpr bn::fixed_size SHARK_SIZE(24, 12);
    static constexpr bn::array<bn::fixed_point, 4> randomSpawnPos = {
        bn::fixed_point(-140, 0),
        bn::fixed_point(0, -100),
        bn::fixed_point(140, 0),
        bn::fixed_point(0, 100)
    };

    bn::fixed_point shark::getRandomStartPos(bn::random &random) const { return randomSpawnPos.at(random.get_int(4)); }

    shark::shark(bn::random &rng, bn::fixed speed) : _sprite(bn::sprite_items::cia_shark.create_sprite(getRandomStartPos(rng))),
                                                     _speed(speed)
    {
        _sprite.set_horizontal_flip(true);
    }

    void shark::update(cia::player &player)
    {
        // If the shark is to the right of the player, go left
        if (_sprite.x() < player.get_x())
        {
            _sprite.set_x(_sprite.x() + _speed);
        }

        // If the player is to the left of the player, go right
        if (_sprite.x() > player.get_x())
        {
            _sprite.set_x(_sprite.x() - _speed);
        }

        // If the player is below the shark, go down
        if (_sprite.y() < player.get_y())
        {
            _sprite.set_y(_sprite.y() + _speed);
        }

        // If the player is above the shark, go up
        if (_sprite.y() > player.get_y())
        {
            _sprite.set_y(_sprite.y() - _speed);
        }
    }

    bn::fixed_rect shark::rect() const
    {
        return bn::fixed_rect(_sprite.position(), SHARK_SIZE);
    }
}
