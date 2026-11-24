#include "nsj_Shark.h"
#include "nsj_boundingBox.h"
#include "bn_sprite_items_nsj_shark.h"
namespace nsj{
static constexpr bn::size SHARK_SIZE = {8, 8};

Shark::Shark(bn::fixed x_start, bn::fixed y_start,bn::fixed speed) : _sprite(bn::sprite_items::nsj_shark.create_sprite(x_start, y_start)),
                                                   _x_speed(speed), _y_speed(speed),
                                                   _size(SHARK_SIZE)
    {
        _bounding_box=create_bounding_box(_sprite, _size);
    }

    bn::rect nsj::Shark::get_bounding_box()
    {
        return _bounding_box;
    } 


    void Shark:: update(nsj::player& player){
         if (player.get_position().x() > _sprite.x())
        {
            _sprite.set_x(_sprite.x() + _x_speed);
            _sprite.set_horizontal_flip(true);
        }
       else if (player.get_position().x() < _sprite.x())
        {
            _sprite.set_x(_sprite.x() - _x_speed);
             _sprite.set_horizontal_flip(false);
        }
        if (player.get_position().y()> _sprite.y())
         {
            _sprite.set_y(_sprite.y()  + _y_speed) ;
         }

         else if (player.get_position().y() < _sprite.y())
         {
             _sprite.set_y(_sprite.y() - _y_speed);
         }

       _bounding_box = create_bounding_box(_sprite, _size);
    }
}