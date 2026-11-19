#include "mck/mck_shark_dodge.h"

#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"  

#include "mj/mj_game_list.h"

namespace
{
    // TODO add names to credits as appropriate
    constexpr bn::string_view code_credits[] = { "Matthew Renner", "Connor Stimpson", "Kevin Flores-Gonzalez" };
    //constexpr bn::string_view graphics_credits[] = {};
    //constexpr bn::string_view sfx_credits[] = {};
    //constexpr bn::string_view music_credits[] = {};
}

MJ_GAME_LIST_ADD(mck::mck_shark_dodge)
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
//MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
//MJ_GAME_LIST_ADD_MUSIC_CREDITS(sfx_credits)
//MJ_GAME_LIST_ADD_SFX_CREDITS(music_credits)

namespace mck {
    mck_shark_dodge::mck_shark_dodge([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data):
        mj::game("mck"),
        _player(player({0, 0}, 1)),
        _enemy(enemy({60, -60}, 0, 0))
    {}

    bn::string<16> mck_shark_dodge::title() const {
        return "Dodge!";
    }

    int mck_shark_dodge::total_frames() const {
    return 600; // 600 frames at 60fps = 10 seconds
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
mj::game_result mck_shark_dodge::play([[maybe_unused]] const mj::game_data& data)
{
    // update the player position
    _player.update();
    _enemy.update();

    if(_player.hitbox().intersects(_enemy.hitbox())) {
        _hit = true;
    }

    mj::game_result result(_hit, false);
    return result;
}

/**
 * Returns whether the player has won the microgame.
 * 
 * In this particular microgame the player wins if they make the ball leave the screen.
 */
bool mck_shark_dodge::victory() const {
    return !_hit;
}

/**
 * Called repeatedly as the game fades into view. Unused for this particular microgame.
 * 
 * @param data shared information, such as a rng and number of frames left in the microgame
 */
void mck_shark_dodge::fade_in([[maybe_unused]] const mj::game_data& data)
{
}

/**
 * Called repeatedly as the game fades into view. Unused for this particular microgame.
 * 
 * @param data shared information, such as a rng and number of frames left in the microgame
 */
void mck_shark_dodge::fade_out([[maybe_unused]] const mj::game_data& data)
{
}
}