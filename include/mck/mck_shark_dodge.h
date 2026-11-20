#pragma once

#include <bn_regular_bg_ptr.h>
#include <bn_sprite_ptr.h>

#include "mj/mj_game.h"
#include "mck_player.h"
#include "mck_enemy.h"

namespace mck {

    class mck_shark_dodge : public mj::game {

        public:
        mck_shark_dodge(int completed_games, const mj::game_data& data);

        bn::string<16> title() const override;
        int total_frames() const override;
        mj::game_result play(const mj::game_data& data) override;
        bool victory() const override;
        void fade_in(const mj::game_data& data) override;
        void fade_out(const mj::game_data& data) override;

        private:
        // The character that the player can move
        player _player;
        enemy _enemy;
        bool _hit = false;
    };

}