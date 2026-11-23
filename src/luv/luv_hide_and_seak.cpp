#include "luv_hide_and_seak.h"
#include "mj/mj_game_list.h"
#include "bn_regular_bg_items_luv_seafloor.h"
#include "luv/luv_methods.h"
#include "bn_log.h"

// String arrays for the credits can go in an anonymous namespace
namespace
{
    constexpr bn::string_view code_credits[] = {"Corey Brown", "Russell Fisher"};
    constexpr bn::string_view graphics_credits[] = {""};
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

// Macros used to add game to game list
MJ_GAME_LIST_ADD(luv::luv_hide_and_seak) // The class of the game is used here
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace luv
{
    luv_hide_and_seak::luv_hide_and_seak([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data &data) : mj::game("luv"),
        _player(PLAYER_SPAWN,PLAYER_SPEED),
        _anemone({data.random.get_fixed(MIN_X,MAX_X), 
            data.random.get_fixed(SEA_FLOOR_MIN,SEA_FLOOR_MAX)}),  
        _background(bn::regular_bg_items::luv_seafloor.create_bg(0, 0))
    {
        for(int i = 0; i < _recommended_trap_spawn(recommended_difficulty_level(completed_games,data)); i++){
            _traps.push_back(luv_trap({data.random.get_fixed(MIN_X,MAX_X),data.random.get_fixed(SEA_FLOOR_MIN,SEA_FLOOR_MAX)}));
        }
    }

    bn::string<16> luv_hide_and_seak::title() const
    {
        return "Hide!";
    }

    int luv_hide_and_seak::total_frames() const
    {
        return 300;
    }

    mj::game_result luv_hide_and_seak::play([[maybe_unused]] const mj::game_data &data)
    {
         
        mj::game_result result(victory(), false);
        _player.update();
        for(luv_trap _trap_single : _traps){
            if (_player.get_bounding_box().intersects(_trap_single.get_bounding_box()))
            {
                _player.set_speed(0.5);
            }
        }
        
        return result;
  
    };

    //Method to test if the player has beaten the minigame or not.
    bool luv_hide_and_seak::victory() const
    {
        return reached_safety(_player, _anemone);
    }

    int luv_hide_and_seak::_recommended_trap_spawn(mj::difficulty_level difficulty){
        if(difficulty == mj::difficulty_level::EASY){
            return 0;
        } else if (difficulty == mj::difficulty_level::NORMAL){
            return 4;
        } 
        return 6;
    }

    bool luv_hide_and_seak::reached_safety(luv_player player, luv_anemone anemone) const{
        return player.get_bounding_box().intersects(anemone.get_bounding_box());
    }

    void luv_hide_and_seak::fade_in([[maybe_unused]] const mj::game_data &data)
    {
    }

    void luv_hide_and_seak::fade_out([[maybe_unused]] const mj::game_data &data)
    {
    }

}
