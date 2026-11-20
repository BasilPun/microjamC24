#pragma once

#ifndef blo_SharkASnack_H
#define blo_SharkASnack_H

#include "mj/mj_game.h"

#include "blo/blo_player.h"
#include "blo/blo_shark.h"

namespace blo
{

    class blo_SharkASnack : public mj::game
    {
        public:
            /**
             * Constructor for an instance of an SharkASnack
             *
             * @param completed_games how many microgames the player has completed so far
             * @param data shared information, such as a rng and number of frames left in the microgame
             */
            blo_SharkASnack(int completed_games, const mj::game_data &data);

            /**
             * The instructions given to the player at the beginning of the microgame.
             *
             * Must be <= 16 characters long
             */
            bn::string<16> title() const override;

            /**
             * How long the timer for the game should be set to in frames.
             *
             * 60 frames is approx 1 second
             */
            int total_frames() const override;

            /**
             * play is repeatedly called while the microgame is playing.
             *
             * @param data shared information, such as a rng and number of frames left in the microgame
             * @return the mj::game result indicating whether the game has finished and whether the title should be hidden
             */
            mj::game_result play(const mj::game_data &data) override;

            /**
             * Returns whether the player has won the microgame.
             *
             */
            bool victory() const override;

            /**
             * Called repeatedly as the game fades into view.
             *
             * @param data shared information, such as a rng and number of frames left in the microgame
             */
            void fade_in(const mj::game_data &data) override;

            /**
             * Called repeatedly as the game fades into view.
             *
             * @param data shared information, such as a rng and number of frames left in the microgame
             */
            void fade_out(const mj::game_data &data) override;
        private:
            player _player;
            shark _shark;
    };
}

#endif