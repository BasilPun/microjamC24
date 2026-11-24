#include "bnc_squid_escape.h"

#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_sprite_ptr.h"
#include "mj/mj_game_list.h"
#include "bnc/bnc_squid.h"
#include "bnc/bnc_whale.h"

// String arrays for the credits can go in an anonymous namespace
namespace
{
    constexpr bn::string_view code_credits[] = { "Brook Carter", "Cristian Rosas B." };
    constexpr bn::string_view graphics_credits[] = { "Brook Carter", "Cristian Rosas B." };
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

// Macros used to add game to game list
MJ_GAME_LIST_ADD(bnc::bnc_squid_escape) // The class of the game is used here
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace bnc
{
    /**
 * Constructor for an instance of an bnc_squid_escape
 * 
 * First item in the initializer list MUST be a call to the superclass, mj::game with the identifier for the microgame.
 * 
 * @param completed_games how many microgames the player has completed so far
 * @param data shared information, such as a rng and number of frames left in the microgame
 */
    bnc_squid_escape::bnc_squid_escape(
        int completed_games,
        const mj::game_data& data) : mj::game("bnc"), 
        _squid(bn::fixed_point(X_START, Y_START), SPEED)
    {

        while(_whale_vector.size() < _whale_increase(recommended_difficulty_level(completed_games, data))) {
            _whale_vector.push_back(Whale(
            data.random.get_unbiased_fixed(MIN_X, MAX_X),
            data.random.get_unbiased_fixed(MIN_Y, MAX_Y),
            WHALE_SPEED));
        }
    };

    /**
 * The instructions given to the player at the beginning of the microgame.
 * 
 * Must be <= 16 characters long
 */
    bn::string<16> bnc_squid_escape::title() const {
    return "Swim across -->";
}

int bnc_squid_escape::_whale_increase(mj::difficulty_level difficulty) {
    if(difficulty == mj::difficulty_level::EASY) {
        return 3;
    } else if (difficulty == mj::difficulty_level::NORMAL) {
        return 4;
    } 
    return 5;
}

/*
 * How long the timer for the game should be set to in frames.
 * 
 * GBA runs at approx 60 frames per second.
 */
    int bnc_squid_escape::total_frames() const {
        return 600; 
    }

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
mj::game_result bnc_squid_escape::play([[maybe_unused]] const mj::game_data& data)
{
    // update the player position
    _squid.update();

    //add another boolean for individual sharks
    bool _caught_squid = false;
    
    //add the for loop to loop over enemies
    for(int i = 0; i< _whale_vector.size(); i++){
        //update the vector to the players location using the index
        _whale_vector[i].update(_squid);

        if(_whale_vector[i].get_whale_collision()) {

            _caught_squid = true;
        }
    }

    mj::game_result result(victory() || _caught_squid, false);
    return result;
}


 /**
 * Returns whether the player has won the microgame.
 * 
 * In this particular microgame the player wins if they make the ball leave the screen.
 */
bool bnc_squid_escape::victory() const {
    return _squid.out_of_bounds();
}

 /**
 * Called repeatedly as the game fades into view. Unused for this particular microgame.
 * 
 * @param data shared information, such as a rng and number of frames left in the microgame
 */
    void bnc_squid_escape::fade_in([[maybe_unused]] const mj::game_data& data)
    {
    }

 /**
 * Called repeatedly as the game fades into view. Unused for this particular microgame.
 * 
 * @param data shared information, such as a rng and number of frames left in the microgame
 */
    void bnc_squid_escape::fade_out([[maybe_unused]] const mj::game_data& data)
    {
    }



}
