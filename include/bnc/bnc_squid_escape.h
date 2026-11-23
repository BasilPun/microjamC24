#pragma once 

#include "mj/mj_game.h"
#include "bnc/bnc_squid.h"
#include "bnc/bnc_whale.h"


namespace bnc {

    class bnc_squid_escape : public mj::game {

        public:
         /**
         * Constructor for an instance of an bnc_fish_escape
         * 
         * @param completed_games how many microgames the player has completed so far
         * @param data shared information, such as a rng and number of frames left in the microgame
         */
        bnc_squid_escape(int completed_games, const mj::game_data& data);

        /**
         * The instructions given to the player at the beginning of the microgame.
         * 
         * Must be <= 16 characters long
         */
        bn::string<16> title() const override;


        /**
         * How long the timer for the game should be set to in frames.
         * 
         * GBA runs at approx 60 frames per second.
         */
        int total_frames() const override;

        /**
         * play is repeatedly called while the microgame is playing.
         * 
         * You can think of it as what previously was in the while event loop.
         * You do NOT need to write your own while event loop
         * You do NOT need to call bn::core::update()
         * 
         * @param data shared information, such as a rng and number of frames left in the microgame
         * @return the mj::game result indicating whether the game has finished and whether the title should be hidden
         */
        mj::game_result play(const mj::game_data& data) override;

        /**
         * Returns whether the player has won the microgame.
         * 
         * In this particular microgame the player wins if they make the ball leave the screen.
         */
        bool victory() const override;

        /**
         * Called repeatedly as the game fades into view. Unused for this particular microgame.
         * 
         * @param data shared information, such as a rng and number of frames left in the microgame
         */
        void fade_in(const mj::game_data& data) override;

        /**
         * Called repeatedly as the game fades into view. Unused for this particular microgame.
         * 
         * @param data shared information, such as a rng and number of frames left in the microgame
         */
        void fade_out(const mj::game_data& data) override;

        private:
        // The character that the player can move
        Squid _squid;

        //whale vector
        static constexpr int MAX_WHALES = 9;
        
        //whale vector;
        bn::vector<Whale, MAX_WHALES> _whale_vector = {};

        // Returns progressively more whales the harder the difficulty
        int _whale_increase(mj::difficulty_level difficulty);

    };
}