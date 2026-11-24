#include "dna_get_hooked.h"
#include "dna_player.h"

#include "mj/mj_game_list.h"

namespace
{
    constexpr bn::string_view code_credits[] = { "kohumukini" };
    constexpr bn::string_view graphics_credits[] = { "" };
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};

    bn::fixed enemy_speed(mj::difficulty_level difficulty) {
        if (difficulty == mj::difficulty_level::EASY) return 3;
        if (difficulty == mj::difficulty_level::NORMAL) return 6;
        
        return 8;
    }
}

MJ_GAME_LIST_ADD(dna::dna_get_hooked) 
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace dna {
    static constexpr bn::point PLAYER_START = {-100, 0};

    static constexpr int INITIAL_TIMER = 0; 
    static constexpr int TIMER_OFFSET = 10;

    dna_get_hooked::dna_get_hooked([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
    mj::game("dna"), 
    _player(Player(PLAYER_START, 2, PLAYER_SIZE)),
    _timer(INITIAL_TIMER), 
    _hit(false), 
    _enemies(),
    _enemy_speed(enemy_speed(recommended_difficulty_level(completed_games, data))) {}

    bn::string<16> dna_get_hooked::title() const {
        return "DODGE!";
    }

    int dna_get_hooked::total_frames() const {
        return 600; 
    }

    mj::game_result dna_get_hooked::play([[maybe_unused]] const mj::game_data& data) {
        _player.update();
        _timer--; 

        if (_timer <= 0 && !_enemies.full()) {
            _timer = TIMER_OFFSET; 
            _enemies.emplace_back(data.random, _enemy_speed, ENEMY_SIZE);
        }

        for (AquaticLife& e : _enemies) {
            if (e.update(_player)) {
                _hit = true; 
            }
        } 

        bn::erase_if(_enemies, [](const AquaticLife& e) { return e.is_offscreen(); });
        
        mj::game_result result(_hit, false); 
        return result; 
    }

    bool dna_get_hooked::victory() const {
        return !_hit;
    }

    void dna_get_hooked::fade_in([[maybe_unused]] const mj::game_data& data)
    {
    }

    void dna_get_hooked::fade_out([[maybe_unused]] const mj::game_data& data)
    {
    }
}