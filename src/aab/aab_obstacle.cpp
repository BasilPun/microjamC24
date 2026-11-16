#include "aab/aab_obstacle.h"
#include <bn_random.h>

namespace aab
{
    Obstacle::Obstacle(bn::sprite_item log, bn::sprite_item rock, int spawn_amount)
    {
        bn::random random;
        for(int i =0; i < spawn_amount; i++){
            //random coordinates
            //a) should be within swimmer's bound
            //b) should be good amount of space away from swimmer's spawn
            int x = random.get_unbiased_int(obstacle_min_width, obstacle_max_width);
            int y = random.get_unbiased_int(swimmer_min_height, swimmer_max_height);

            int isLog = random.get_unbiased_int(0,2);
            if(isLog == 1){
                //spawn log
                sprites.push_back(log.create_sprite(x, y));
            }
            else{
                //spawn rock
                sprites.push_back(rock.create_sprite(x, y));
            }
        }   
    }

    void Obstacle::update()
    {
        // You can leave it static or add movement here if desired
    }
}