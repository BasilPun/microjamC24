#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_display.h>

#include <bn_vector.h>
#include "mj_core.h"

namespace vct {

class player {
        //Screen bounds
        static constexpr int MAX_X = bn::display::width() / 2;

        static constexpr int MIN_X = -bn::display::width() / 2;

        static constexpr int MAX_Y = bn::display::height() / 2;
        
        static constexpr int MIN_Y = -bn::display::height() / 2;

    public:
        //Player constructor
        player(bn::fixed_point starting_position, bn::fixed speed);
        
        //Constantly updates the game
        void update(bn::random& random, const bn::sprite_text_generator& text_generator);

        //Reutnr when the quick time event is successfully comepleted (for ending the game)
        //I realized that we need a win condition since there isn't one by defualt
        bool qte_complete() const;
    
    private:
        //Player sprite
        bn::sprite_ptr _sprite;
        
        //The max amount of buttons needed to be pressed
        int _max[15]; 
        
        //How many buttons needed to be pressed for this round
        int _length = 7;

        //The amount of currently correctly pressed keys
        int _pressed = 0;        
        
        //Whether the game has started ()
        bool _started = false;   
                         
        //The vector that contains the text sprits on screen
        bn::vector<bn::sprite_ptr, 16> _words;  

        //This handles the player input for the QTE
        void qte(bn::random& random, const bn::sprite_text_generator& text_generator);
        //This handles the games actual QTE event
        void sequence(bn::random& random, const bn::sprite_text_generator& text_generator);
};

}