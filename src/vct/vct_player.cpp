#include "vct_player.h"
#include <bn_keypad.h>
#include "bn_sprite_items_vct_angler.h"
#include "bn_sound_items.h"

namespace vct {

//Basic player constructor, all inital values go here
player::player(bn ::fixed_point starting_position, [[maybe_unused]] bn::fixed speed) :
    _sprite(bn::sprite_items::vct_angler.create_sprite(starting_position))
{}

//Updates the player on screen
void player::update(bn::random& random, const bn::sprite_text_generator& text_generator) {
    qte(random, text_generator);
}

//Win condition
bool player::qte_complete() const
{
    return _pressed >= _length;
}

//This handles the games actual QTE event
void player::sequence(bn::random& random, const bn::sprite_text_generator& text_generator)
{
    _words.clear(); //Words MUST be cleared
    _pressed = 0; //Initializes the start of the game with 0 currently pressed buttons


    //Max_x - Min_X is so that I can get the full length of the screen. Since it'd be
    //120 - (-120) = 240. Which would be the ful length of the screen.
    //Then 240/8 to split the screen into 8 sections
    //Then the x of each letter will be sitting in the border between each section (7 borders)
    //So the button starts at the left of the screen, Min_x, and increments every 8th of the screen
    //for each new button.
    int size = (MAX_X - MIN_X) / (_length + 1); //since it start at 0
    int x = MIN_X + size;

    for(int i = 0; i < _length; i++)
    {
        //Assigns index i of the max letters vector a random number, which then gets assigned
        //as a button
        _max[i] = random.get_int(4);

        if (_max[i] == 0)
        {
            text_generator.generate(x, 50, "A", _words);
        }
        else if (_max[i] == 1)
        {
            text_generator.generate(x, 50, "B", _words);
        }
        else if (_max[i] == 2)
        {
            text_generator.generate(x, 50, "L", _words);
        }
        else if (_max[i] == 3)
        {
            text_generator.generate(x, 50, "R", _words);
        }

        x += size; //For each iteration of the for loop, the next word will move another 8th of the screen over
    }
}

//This handles the player input for the QTE
void player::qte(bn::random& random, const bn::sprite_text_generator& text_generator) {
    
    //This if block is REQUIRED. The bool checks if the game started, if not it toggles to true
    //and blocks the game from being able to be ran WHILE the game is currently running.
    //This was a big issue when testing because the qte words would rapidly change since the game
    //started over and over again.
    if(!_started)
    {
        sequence(random, text_generator);
        _started = true;
    }

    //If the amount of pressed buttons meets the required amount, return to end early
    if(_pressed >= _length)
    {
        return;
    }

    int pressed = -1;   //-1 means nothing pressed (default value since 0 is a button)

    //QTE inputs
    if(bn::keypad::a_pressed())
    {
        pressed = 0;
    }
    else if(bn::keypad::b_pressed())
    {
        pressed = 1;
    }
    else if(bn::keypad::l_pressed())
    {
        pressed = 2;
    }
    else if(bn::keypad::r_pressed())
    {
        pressed = 3;
    }

    //After passing a QTE, hides the letter (WILL NEED TO BE CHANGED, THIS IS A PLACEHOLDER FEATURE)
    if(pressed != -1)
    {
        if(pressed == _max[_pressed])
        {
            _words[_pressed].set_visible(false);   // hide the finished one
            _pressed++;
        }
    }
 }
}