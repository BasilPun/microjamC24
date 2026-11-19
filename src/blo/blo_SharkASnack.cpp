#include "blo_SharkASnack.h"

#include "mj/mj_game_list.h"

namespace
{
    constexpr bn::string_view code_credits[] = {"Brandon Mitzel", "Logan Highley"};
    constexpr bn::string_view graphics_credits[] = {""};
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

// Macros to add game to game list
MJ_GAME_LIST_ADD(blo::blo_SharkASnack)
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace blo
{
    /**
     * Constructor for an instance of an SharkASnack
     *
     * @param completed_games how many microgames the player has completed so far
     * @param data shared information, such as a rng and number of frames left in the microgame
     */
    blo_SharkASnack::blo_SharkASnack([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data &data) : 
    mj::game("blo"),
    _player(player()),
    _shark(shark({0, 0}))
    {
    }

    /**
     * The instructions given to the player at the beginning of the microgame.
     *
     * Must be <= 16 characters long
     */
    bn::string<16> blo_SharkASnack::title() const
    {
        return "Guard your snack";
    };

    /**
     * How long the timer for the game should be set to in frames.
     *
     * 60 frames is approx 1 second
     */
    int blo_SharkASnack::total_frames() const
    {
        return 600;
    };

    /**
     * play is repeatedly called while the microgame is playing.
     *
     * @param data shared information, such as a rng and number of frames left in the microgame
     * @return the mj::game result indicating whether the game has finished and whether the title should be hidden
     */
    mj::game_result blo_SharkASnack::play([[maybe_unused]] const mj::game_data &data)
    {
        _player.update(_shark);
        _shark.update();

        mj::game_result result(victory(), false);
        return result;
    };

    /**
     * Returns whether the player has won the microgame.
     *
     */
    bool blo_SharkASnack::victory() const
    {
        return _shark.punched();
    };

    /**
     * Called repeatedly as the game fades into view.
     *
     * @param data shared information, such as a rng and number of frames left in the microgame
     */
    void blo_SharkASnack::fade_in([[maybe_unused]] const mj::game_data &data) {

    };

    /**
     * Called repeatedly as the game fades into view.
     *
     * @param data shared information, such as a rng and number of frames left in the microgame
     */
    void blo_SharkASnack::fade_out([[maybe_unused]] const mj::game_data &data) {

    };
}