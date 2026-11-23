#pragma once

#include "mj_game.h"
#include "luv/luv_player.h"
#include "luv/luv_anemone.h"
#include "luv/luv_trap.h"
#include <bn_vector.h>
#include <bn_regular_bg_ptr.h>

// Create a namespace for Hide and Sea-k Game.
namespace luv
{
    class luv_hide_and_seak : public mj::game
    {
    public:
        /**
         * Constructor for and instance f the Hide and Sea-k Game.
         * @param completed_games the numbner of microsgames the player has completed.
         * @param data shared information about the game. RNG, number of frames left, etc.
         */
        luv_hide_and_seak(int completed_games, const mj::game_data &data);

        /**
         * Method to display the intructions to the player when the game is booted up.
         *
         * Intructions must be less than or equal to 16 characters in length.
         */
        bn::string<16> title() const override;

        /**
         * Method that sets up the timer for the game, set in frames.
         *
         * Note: GBA runs at ~60 FPS.
         */
        int total_frames() const override;

        /**
         * Method that is called repeatedly whilst the game is running.
         *
         * @param data shared information about the game. RNG, number of frames left, etc.
         * @return the mj:data result of whether or not the game has finished and if the title
         * should or should not be hidden.
         */
        mj::game_result play(const mj::game_data &data) override;

        /**
         * Method that returns whether or not the player has won this microgame.
         * True - Victory.
         * False - Defeat.
         *
         * In this game, the player achieves victory if they can reach a
         * safe anemone hideout before the timer runs out.
         */
        bool victory() const;

        /**
         * Method that is called repeatedly as the game fades in.
         * @param data information about the game. RNG, number of frames left, etc.
         */
        void fade_in(const mj::game_data &data) override;

        /**
         * Method that is called repeatedly as the game fades in.
         * @param data information about the game. RNG, number of frames left, etc.
         */
        void fade_out(const mj::game_data &data) override;

        //Returns number of traps to spawn based on level of difficulty
        int _recommended_trap_spawn(mj::difficulty_level difficulty);

        bool reached_safety(luv_player _player, luv_anemone _anemone) const;

    private:
        static constexpr int MAX_TRAPS = 6;
        static constexpr bn::fixed_point PLAYER_SPAWN = {20, -30};
        static constexpr bn::fixed PLAYER_SPEED = 2;
        static constexpr bn::fixed SEA_FLOOR_MIN = 0;
        static constexpr bn::fixed SEA_FLOOR_MAX = MAX_Y - 20;
        luv_player _player;
        luv_anemone _anemone;
        bn::regular_bg_ptr _background;
        bn::vector<luv_trap, MAX_TRAPS> _traps; 
    };
};