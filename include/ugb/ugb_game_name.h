#pragma once

#include <bn_string.h>

#include "mj/mj_game.h"
#include "mj/mj_game_data.h"

#include "ugb/ugb_game_state.h"
#include "ugb/ugb_player.h"

namespace ugb {
    class ugb_game_name : public mj::game {
        public:
            ugb_game_name(int completed_games, const mj::game_data& data);

            void update_score(const bn::sprite_text_generator& text_generator);

            // Instructions given at the beginning of the microgame
            bn::string<16> title() const override;

            // How long the game should last (in frames)
            int total_frames() const override;

            // Repeatedly called while game is running, returns whether the game has finished
            mj::game_result play(const mj::game_data& data) override;

            // Returns whether the player has won the microgame
            bool victory() const override;

            // Called as the game fades into view
            void fade_in(const mj::game_data& data) override;

            // Called as the game fades out of view
            void fade_out(const mj::game_data& data) override;

        private:
            Player _player;
            GameState _state;
    };
}