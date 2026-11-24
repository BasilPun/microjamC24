#include "bnc/bnc_whale.h"
#include "bnc/bnc_squid_escape.h"
#include "bn_sprite_items_bnc_whale.h"
#include "mj/mj_game_data.h"
#include "bnc/bnc_squid.h"

#include <bn_vector.h>
#include <bn_rect.h>


namespace bnc{

    Whale::Whale(bn::fixed x, bn::fixed y, bn::fixed speed) :
    _whale(bn::sprite_items::bnc_whale.create_sprite(x, y)),
    _whale_hit_box(create_bounding_box(_whale, WHALE_SIZE)),
    _whale_speed(speed), _whale_size(WHALE_SIZE)
    {}


    bool Whale::get_whale_collision() const {
        return _whale_collision;
    }


    void Whale::update(Squid& squid) {
        if(_whale.x() < squid.get_position().x()){
            _whale.set_x(_whale.x() + _whale_speed);
        }

        if(_whale.x() > squid.get_position().x()){
            _whale.set_x(_whale.x() - _whale_speed);
        }

        if(_whale.y() > squid.get_position().y()){
            _whale.set_y(_whale.y() - _whale_speed);
        }

        if(_whale.y() < squid.get_position().y()){
            _whale.set_y(_whale.y() + _whale_speed);
        }

        _whale_hit_box = create_bounding_box(_whale, WHALE_SIZE);
        
        if(_whale_hit_box.intersects(squid.get_squid_hit_box())){
            _whale_collision = true;
        }


    }
}