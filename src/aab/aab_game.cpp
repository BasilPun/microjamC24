#include "aab_game.h"

#include "mj/mj_game_list.h"
#include "bn_regular_bg_items_aab_oceanbg.h"
#include "bn_sprite_items_aab_log.h"
#include "bn_sprite_items_aab_rock.h"

#include "bn_camera_ptr.h"

// String arrays for the credits can go in an anonymous namespace
namespace
{
    constexpr bn::string_view code_credits[] = {"Basil Paija Pun & Arshdeep Singh"};
    constexpr bn::string_view graphics_credits[] = {""};
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
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
                                                                                                           dolphin(Dolphin({-100, -20})), // dolphin racing right ward
                                                                                                           swimmer(Swimmer({-120, 30})),
                                                                                                           log_obstacle(Obstacle(bn::sprite_items::aab_log,{10,35})),
                                                                                                           rock_obstacle(Obstacle(bn::sprite_items::aab_rock,{70,25})),
                                                                                                           background(bn::regular_bg_items::aab_oceanbg.create_bg()),
                                                                                                           slow_timer(0)
    {
        // play_sound(bn::sound_items::aub_tower, completed_games, data);
    }

    /**
     * The instructions given to the player at the beginning of the microgame.
     *
     * Must be <= 16 characters long
     */
    bn::string<16> aab_game::title() const
    {
        return "Race the Dolphin";
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
        // testing camera
        bn::camera_ptr camera = bn::camera_ptr::create(0, 0);
        swimmer.sprite.set_camera(camera);
        background.set_camera(camera);
        log_obstacle.sprite.set_camera(camera);
        rock_obstacle.sprite.set_camera(camera);

        // add in dolphin
        dolphin.update();
        swimmer.update();
        log_obstacle.update();
        rock_obstacle.update();

        // updating camera
        camera.set_position(swimmer.sprite.x(), 0);

        // Log Obstacle Collion Check
        if (slow_timer == 0 &&
            swimmer.sprite.x() > log_obstacle.sprite.x() - 12 && swimmer.sprite.x() < log_obstacle.sprite.x() + 12 &&
            swimmer.sprite.y() > log_obstacle.sprite.y() - 12 && swimmer.sprite.y() < log_obstacle.sprite.y() + 12)
        {
            // Knock back swimmer slightly if they hit an obstacle
            swimmer.sprite.set_x(log_obstacle.sprite.x() - 16);

            // trigger slow effect for 45 frames (0.75 secs),overpowering the boost button
            slow_timer = 45;
        }
        //Rock obstacle collision check
        if(slow_timer == 0 &&
           swimmer.sprite.x() > rock_obstacle.sprite.x() - 12 && swimmer.sprite.x() < rock_obstacle.sprite.x() + 12 &&
           swimmer.sprite.y() > rock_obstacle.sprite.y() - 12 && swimmer.sprite.y() < rock_obstacle.sprite.y() + 12)
        {
            swimmer.sprite.set_x(rock_obstacle.sprite.x() - 16);
            slow_timer = 45;
        }
        // apply slow-down drag if timer is active
        if (slow_timer > 0)
        {
            slow_timer--;

            // counter forward movement so swimmer crawls forward even if boosting
            swimmer.sprite.set_x(swimmer.sprite.x() - 0.7);
        }
        // Creates a game result indicating whether the game is finished and whether the title should be hidden early
        // For this game the game should end early if the player has won (if victory returns true)
        // The title is not hidden early (false is passed), so the title disappears at the default time
        mj::game_result result(victory(), false);
        return result;
    }

    /**
     * Returns whether the player has won the microgame.
     *
     * In this particular microgame the player wins if they make the ball leave the screen.
     */
    bool aab_game::victory() const
    {
        return swimmer.sprite.x() > dolphin.sprite.x() && (swimmer.sprite.x() > 150);
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
