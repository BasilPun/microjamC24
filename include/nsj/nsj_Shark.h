#include "nsj_player.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_size.h"
#include "bn_rect.h"

namespace nsj
{
    class Shark
    {
    private:
        bn::sprite_ptr _sprite;
        bn::fixed _x_speed;
        bn::fixed _y_speed;
        bn::size _size;
        bn::rect _bounding_box;

    public:
        Shark(bn::fixed x_start, bn::fixed y_start, bn::fixed speed);

        void update(nsj::player &player);

        bn::rect get_bounding_box();
    };
}