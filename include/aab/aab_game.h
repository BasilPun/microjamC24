#pragma once

#include <bn_regular_bg_ptr.h>
#include <bn_camera_ptr.h>

#include "mj/mj_game.h"
#include "aab/aab_dolphin.h"
#include "aab/aab_swimmer.h"
#include "aab/aab_obstacle.h"
#include "aab/aab_button.h"

namespace aab
{
    class aab_game : public mj::game
    {
    public:
        /**
         * Constructor for an instance of an aab_game
         *
         * @param completed_games how many microgames the player has completed so far
         * @param data shared information, such as a rng and number of frames left in the microgame
         */
        aab_game(int completed_games, const mj::game_data &data);

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
        mj::game_result play(const mj::game_data &data) override;

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
        void fade_in(const mj::game_data &data) override;

        /**
         * Called repeatedly as the game fades into view. Unused for this particular microgame.
         *
         * @param data shared information, such as a rng and number of frames left in the microgame
         */
        void fade_out(const mj::game_data &data) override;


        //setting amount of obstacles that spawn with difficulty level
        static int obstacle_amount(mj::difficulty_level difficulty);

        //setting dolphin speed level according to difficulty level
        bn::fixed recommended_dolphin_speed(mj::difficulty_level difficulty);

    private:
        Dolphin _dolphin;
        Swimmer _swimmer;
        Obstacle _obstacle;
        Button _button;
        bn::regular_bg_ptr _background;
        bn::camera_ptr _camera;
        int _slow_timer;
        
        static constexpr bn::fixed easy_dolphin_speed = 0.6;
        static constexpr bn::fixed normal_dolphin_speed = 1.0;
        static constexpr bn::fixed hard_dolphin_speed = 2.0;
        static constexpr int finish_line_x =150;
    };
}