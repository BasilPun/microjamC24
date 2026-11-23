#include "aab_game.h"

#include "mj/mj_game_list.h"
#include "bn_regular_bg_items_aab_oceanbg.h"
#include "bn_sprite_items_aab_log.h"
#include "bn_sprite_items_aab_rock.h"

// String arrays for the credits can go in an anonymous namespace
namespace
{
    constexpr bn::string_view code_credits[] = {"Basil Paija Pun", "Arshdeep Singh"};
    constexpr bn::string_view graphics_credits[] = {"Basil Paija Pun", "Arshdeep Singh"};
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};

    constexpr bn::fixed_point dolphin_start_pos = {-100, -20};
    constexpr bn::fixed_point swimmer_start_pos = {-120, 30};
    constexpr bn::fixed_point obstacle_start_pos = {0, 35};
    
}

// Macros used to add game to game list
MJ_GAME_LIST_ADD(aab::aab_game) // The class of the game is used here
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

// All game functions/classes/variables/constants scoped to the namespace
namespace aab
{
    /**
     * Constructor for an instance of an aab_game
     *
     * First item in the initializer list MUST be a call to the superclass, mj::game with the identifier for the microgame.
     *
     * @param completed_games how many microgames the player has completed so far
     * @param data shared information, such as a rng and number of frames left in the microgame
     */
    aab_game::aab_game([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data &data) : mj::game("aab"),
                                                                                                           _dolphin(Dolphin({dolphin_start_pos}, recommended_dolphin_speed(recommended_difficulty_level(completed_games, data)))),
                                                                                                           _swimmer(Swimmer({swimmer_start_pos})),
                                                                                                           _obstacle(Obstacle(bn::sprite_items::aab_log, bn::sprite_items::aab_rock, obstacle_amount(recommended_difficulty_level(completed_games, data)), data.random)),
                                                                                                           _button(Button({-120,-50})),
                                                                                                           _background(bn::regular_bg_items::aab_oceanbg.create_bg()),
                                                                                                           _camera(bn::camera_ptr::create(0, 0)),
                                                                                                           _slow_timer(0)
    {
        //Attach camera to spites once upon creation
        _dolphin.set_camera(_camera);
        _swimmer.set_camera(_camera);
        _swimmer.arrows_set_camera(_camera);
        _background.set_camera(_camera);
        _obstacle.set_camera(_camera);
        _button.set_camera(_camera);
    }
    /**
     * The instructions given to the player at the beginning of the microgame.
     *
     * Must be <= 16 characters long
     * TODO: POSSIBLY ADDING NEW SPRITES FROM WAVE 7
     */
    bn::string<16> aab_game::title() const
    {
        return "Mash A to Swim!";
    }

    //the more games the player has completed, the more obstacles that will spawn.
    int aab_game::obstacle_amount(mj::difficulty_level difficulty) 
    {
        if(difficulty == mj::difficulty_level::EASY) {
        return 1;
    } else if (difficulty == mj::difficulty_level::NORMAL) {
        return 3;
    } 
    return 4;
    }

    bn::fixed aab_game::recommended_dolphin_speed(mj::difficulty_level difficulty) {
    if(difficulty == mj::difficulty_level::EASY) {
        return easy_dolphin_speed;
    } else if (difficulty == mj::difficulty_level::NORMAL) {
        return normal_dolphin_speed;
    } 
    return hard_dolphin_speed;
    }

    /**
     * How long the timer for the game should be set to in frames.
     *
     * GBA runs at approx 60 frames per second.
     */
    int aab_game::total_frames() const
    {
        return 360; // 360 frames at 60fps = 6 seconds
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
    mj::game_result aab_game::play([[maybe_unused]] const mj::game_data &data)
    {

        // add in dolphin
        _dolphin.update();
        _swimmer.update();
        _button.update(_swimmer.x());
        _obstacle.update(_swimmer, _slow_timer);

        // updating camera
        _camera.set_position(_swimmer.x(), 0);

        // Creates a game result indicating whether the game is finished and whether the title should be hidden early
        mj::game_result result(victory(), false);
        return result;
    }
    

    /**
     * Returns whether the player has won the microgame.
     *
     * In this particular microgame the player wins if they cross the finishing line before the dolphin.
     */
    bool aab_game::victory() const
    {
        return _swimmer.x() > _dolphin.x() && (_swimmer.x() > finish_line_x);
    }

    /**
     * Called repeatedly as the game fades into view. Unused for this particular microgame.
     *
     * @param data shared information, such as a rng and number of frames left in the microgame
     */
    void aab_game::fade_in([[maybe_unused]] const mj::game_data &data)
    {
    }

    /**
     * Called repeatedly as the game fades into view. Unused for this particular microgame.
     *
     * @param data shared information, such as a rng and number of frames left in the microgame
     */
    void aab_game::fade_out([[maybe_unused]] const mj::game_data &data)
    {
    }
}
