#pragma once

#include "mj/mj_game.h"
#include "bar/bar_player.h"
#include "bar/bar_bouncer.h"
#include "bar/bar_create_bounding_box.h"
#include "bar/bar_spawn_bouncer.h"

// All game functionality/classes/fields
namespace bar 
{
    class bar_snap_em_up: public mj::game {
        public:
            bar_snap_em_up(int complete_games, const mj::game_data& data);

            bn::string<16> title() const override;

            int total_frames() const override;

            mj::game_result play(const mj::game_data& data) override;

            bool victory() const override;

            void fade_in(const mj::game_data& data) override;

            void fade_out(const mj::game_data& data) override;
        private:
            bar_player _player;
            bar_bouncer _bouncer;
            bn::fixed _recommended_bounce_speed(mj::difficulty_level difficulty);
    };
}