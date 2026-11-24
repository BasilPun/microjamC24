#pragma once

#include "vct_player.h"
#include "mj_game.h"
#include "bn_regular_bg_items_vct_background.h"
#include "bn_regular_bg_ptr.h"


namespace vct 
{
    class vct_fish_bait : public mj::game 
    {
        public:
            //Constructor for an instance of an vct_fish_bait
            vct_fish_bait(int completed_games, const mj::game_data& data);

            //Game title/ the instructions to give to the player
            bn::string<16> title() const override;

            //How long the game lasts for
            int total_frames() const override;

            //Basically the "while" loop of our code, constantly updates player
            //as play constantly updates.
            mj::game_result play(const mj::game_data& data) override;
            
            //Checks if the player wins
            bool victory() const override;
            
            //Most likely unused for our game
            void fade_in(const mj::game_data& data) override;
            void fade_out(const mj::game_data& data) override;

            private:
            //background for the game
            bn::regular_bg_ptr _bg;
            //The moveable character
            player _player;
    };

}