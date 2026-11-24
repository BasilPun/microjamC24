#pragma once

#include <bn_vector.h>

#include "mj/mj_game.h"

#include "dna_player.h"
#include "dna_aquatic_life.h"

namespace dna {
    class dna_get_hooked : public mj::game {
        static constexpr int MAX_ENEMY_COUNT = 15;
        static constexpr bn::size ENEMY_SIZE{8, 8}; 

        public: 
            dna_get_hooked(int completed_games, const mj::game_data& data);

            bn::string<16> title() const override;  

            int total_frames() const override; 

            mj::game_result play(const mj::game_data& data) override; 

            bool victory() const override; 

            void fade_in(const mj::game_data& data) override; 
            void fade_out(const mj::game_data& data) override; 
        private: 
            Player _player;
            int _timer; 
            bool _hit; 
            bn::vector<AquaticLife, MAX_ENEMY_COUNT> _enemies; 
            bn::fixed _enemy_speed; 
    };
}
