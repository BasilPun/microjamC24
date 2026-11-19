#include "bnc/bnc_shark.h"
#include "bn_sprite_items_bnc_shark.h"
#include "mj/mj_game_result.h"
#include <bn_log.h>
#include "bnc/bnc_minnow.h"
#include <bn_vector.h>
#include <bn_rect.h>

namespace bnc{
    Shark::Shark(bn::fixed x, bn::fixed y, bn::fixed speed) :
    _shark(bn::sprite_items::bnc_shark.create_sprite(x, y)),
    _shark_hit_box(create_bounding_box(_shark, _shark_size)),
    _shark_speed(speed),
    _shark_size(SHARK_SIZE)
    {}

    bool Shark::get_shark_collision() const {
        return _shark_collision;
    }
    void Shark::update(Minnow& minnow) {

        if(_shark.x() < minnow.get_sprite().x()){
            _shark.set_x(_shark.x() + _shark_speed);
        }
        if(_shark.x() > minnow.get_sprite().x()){
            _shark.set_x(_shark.x() - _shark_speed);
        }
        if(_shark.y() > minnow.get_sprite().y()){
            _shark.set_y(_shark.y() - _shark_speed);
        }
        if(_shark.y() < minnow.get_sprite().y()){
            _shark.set_y(_shark.y() + _shark_speed);
        }
        _shark_hit_box = create_bounding_box(_shark, SHARK_SIZE);
        
        if(_shark_hit_box.intersects(minnow.get_minnow_hit_box())){
            _shark_collision = true;
        }
    }
}