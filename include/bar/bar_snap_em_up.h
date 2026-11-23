#pragma once

#include <bn_vector.h>

#include "mj/mj_game.h"
#include "bar/bar_player.h"
#include "bar/bar_bouncer.h"
#include "bar/bar_create_bounding_box.h"
#include "bar/bar_spawn_bouncer.h"
#include "bar_constants.h"

// All game functionality/classes/fields
namespace bar
{
    class bar_snap_em_up : public mj::game
    {
    public:
        bar_snap_em_up(int complete_games, const mj::game_data &data);

        bn::string<16> title() const override;

        int total_frames() const override;

        mj::game_result play(const mj::game_data &data) override;

        bool victory() const override;

        void fade_in(const mj::game_data &data) override;

        void fade_out(const mj::game_data &data) override;

    private:
        bn::vector<bar_player, 2> _player_arms;
        bn::vector<bar_bouncer, MAX_BOUNCERS> _bouncers;
        bn::fixed _recommended_bounce_speed(mj::difficulty_level difficulty);
        bn::fixed _recommended_spawn_speed(mj::difficulty_level difficulty);
        int _recommended_target_count(mj::difficulty_level difficulty);
        int bouncer_spawned_count;
        int bouncer_hit_count;
        int completed_games_global;
        int game_timer;
        bn::random &rng_spawn;
        bool bouncer_target_reached;
    };
}