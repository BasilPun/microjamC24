#include "aab/aab_obstacle.h"

#include <bn_random.h>
#include <bn_camera_ptr.h>

namespace aab
{
    Obstacle::Obstacle(bn::sprite_item log, bn::sprite_item rock, int spawn_amount, bn::random random)
    {
        random.update();
        for(int i =0; i < spawn_amount; i++){
            //random coordinates
            //a) should be within swimmer's bound
            //b) should be good amount of space away from swimmer's spawn
            int x = random.get_unbiased_int(_obstacle_min_width, _obstacle_max_width);
            int y = random.get_unbiased_int(_swimmer_min_height, _swimmer_max_height);

            int isLog = random.get_unbiased_int(0,2);
            if(isLog == 1){
                bn::sprite_ptr s = log.create_sprite(x, y);
                s.set_bg_priority(0);
                _sprites.push_back(s);
            }
            else{
                bn::sprite_ptr s = rock.create_sprite(x, y);
                s.set_bg_priority(0);
                _sprites.push_back(s);
            }
        }   
    }

    void Obstacle::update(Swimmer &_swimmer, int &_slow_timer)
    {
        // You can leave it static or add movement here if desired
        _collisionCheck(_swimmer, _slow_timer);
    }

    //right now, we have setters and getters for1 sprite. we want our
    //obstacle setter and getters to be able to apply camera/ obstacle. and we wont need getters.
    void Obstacle::set_camera(const bn::camera_ptr& camera){
        for(bn::sprite_ptr& sprite : _sprites)
        {
            sprite.set_camera(camera);
        }
    }

    void Obstacle::_collisionCheck(Swimmer &_swimmer, int &_slow_timer){
        for(bn::sprite_ptr& sprite : _sprites)
        {
            if (_slow_timer == 0 &&
                _swimmer.x() > sprite.x() - _collison_radius && _swimmer.x() < sprite.x() + _collison_radius &&
                _swimmer.y() > sprite.y() - _collison_radius && _swimmer.y() < sprite.y() + _collison_radius)
            {
                _swimmer.slow_down();
            }
        }
    }
}