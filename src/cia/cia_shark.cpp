#include "cia_shark.h"

#include "bn_sprite_items_cia_shark.h"

namespace cia
{
    static constexpr bn::fixed_size SHARK_SIZE(24, 12);

    shark::shark(bn::fixed_point starting_position, bn::fixed speed) : _sprite(bn::sprite_items::cia_shark.create_sprite(starting_position)),
                                                                       _speed(speed)
    {
        _sprite.set_horizontal_flip(true);
    }

    void shark::update()
    {
        _sprite.set_x(_sprite.x() - _speed);

        if (_sprite.x() < MIN_X)
        {
            _sprite.set_x(MAX_X);
        }
    }

    bn::fixed_rect shark::rect() const
    {
        return bn::fixed_rect(_sprite.position(), SHARK_SIZE);
    }
}
