#include "bar_bouncer.h"

namespace bar
{
    bar_bouncer::bar_bouncer(bn::fixed x_start, bn::fixed y_start, bn::fixed base_speed, bn::size bouncer_size) : _sprite(bn::sprite_items::bar_bouncer.create_sprite(x_start, y_start)),
                                                                                                                  _horizontal_speed(base_speed), _size(bouncer_size),
                                                                                                                  _bounding_box(bar_create_bounding_box(_sprite, bouncer_size)), _is_collided(false)
    {
    }

    void bar_bouncer::update()
    {
        _is_collided = false;

        _sprite.set_y(_sprite.y() + _horizontal_speed);

        _bounding_box = bar_create_bounding_box(_sprite, _size);
    }

    bn::rect bar_bouncer::get_bounding_box() const
    {
        return _bounding_box;
    }

    bool bar_bouncer::is_collided() const
    {
        return _is_collided;
    }

    void bar_bouncer::set_collided(bool set_status)
    {
        _is_collided = set_status;
    }
}