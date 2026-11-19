#include <bn_string_view.h>
#include <bn_string.h>

#include "ugb/ugb_entity_manager.h"
#include "ugb/ugb_game_name.h"

#include "mj/mj_game_list.h"
#include "mj/mj_game.h"

// String arrays for the credits can go in an anonymous namespace
namespace
{
    constexpr bn::string_view code_credits[] = { "Nick B and Colin R" };
    constexpr bn::string_view graphics_credits[] = { "Nick B and Colin R" };
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

    // Macros used to add game to game list
    MJ_GAME_LIST_ADD(ugb::ugb_game_name)
    MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
    MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
    MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
    MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace ugb {
    ugb_game_name::ugb_game_name([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) : 
    mj::game("ugb"), _player(constants::player::INITIAL_X, constants::player::INITIAL_Y, constants::player::SPEED) 
    {
        // Get recommended difficulty level
        mj::difficulty_level difficulty = recommended_difficulty_level(completed_games, data);
        // Convert it to an int for array indexing
        int difficulty_ind = static_cast<int>(difficulty);
        // Tune some things for this difficulty level
        _state.required_score = constants::difficulty::REQUIRED_SCORE[difficulty_ind];
        _state.hook_count = constants::difficulty::HOOK_SPAWNS[difficulty_ind];

        // Initialize score
        update_score(data.text_generator);

        // Spawn food
        bn::fixed_point spawn_location;
        for (int i = 0; i < _state.required_score; i++) {
            spawn_location = get_safe_spawn_loc(data.random, _state);
            if (spawn_location.x() == constants::MAX_X) {
                continue; // Couldn't find a safe location
            }
            _state.food.emplace_back(spawn_location);
        }
        // Spawn hooks
        // Add one hook on each side before adding the next pair

        for (int i = 0; i < _state.hook_count; i++) {
            bn::fixed start_y = data.random.get_unbiased_int(constants::hook::MIN_Y, constants::hook::MAX_Y);

            bn::fixed_point hook_position(constants::hook::X_POSITIONS[i], start_y);
            _state.hooks.emplace_back(hook_position, constants::difficulty::HOOK_SPEED[difficulty_ind]);
        }
    }

    void ugb_game_name::update_score(const bn::sprite_text_generator& text_generator) {
        _state.score_sprites.clear();
        bn::string<constants::MAX_SCORE_CHARS> score_string = bn::to_string<constants::MAX_SCORE_CHARS>(_state.score);
        text_generator.generate(constants::score::SCORE_X, constants::score::SCORE_Y, score_string, _state.score_sprites);
    }

    bn::string<16> ugb_game_name::title() const {
        return "Eat little fish";
    }

    int ugb_game_name::total_frames() const {
        return 600; // 10 seconds
    }

    bool ugb_game_name::victory() const {
        if (_state.hit_hook) {
            return false;
        }
        if (_state.score >= _state.required_score) {
            return true;
        }
        return false;
    }

    mj::game_result ugb_game_name::play([[maybe_unused]] const mj::game_data& data) {

        //GAME LOOP STUFF
        _player.update();
        
        bn::rect player_bounding_box = _player.bounding_box();

        for (Hook& hook : _state.hooks) {
            hook.update();

            if (player_bounding_box.intersects(hook.bounding_box())) {
                _state.hit_hook = true;
                return mj::game_result(true, false);
            }
        }

        int points = _state.food_manager.collect_food(_state.food, player_bounding_box);

        if (points > 0) {
            _state.score += points;
            update_score(data.text_generator);
        }
        
        //end
        mj::game_result result(victory(), false);
        return result;
    }

    void ugb_game_name::fade_in([[maybe_unused]] const mj::game_data &data) {

    }

    void ugb_game_name::fade_out([[maybe_unused]] const mj::game_data &data) {

    }

}