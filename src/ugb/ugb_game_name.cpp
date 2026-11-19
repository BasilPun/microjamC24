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
        // Initialize score
        update_score(data.text_generator);
        bn::fixed_point spawn_location;
        // Spawn food
        for (int i = 0; i < constants::spawn::FOOD; i++) {
            spawn_location = get_safe_spawn_loc(data.random, _state);
            if (spawn_location.x() == constants::MAX_X) {
                continue; // Couldn't find a safe location
            }
            _state.food.emplace_back(spawn_location);
        }
        // Spawn hooks
        for (int i = 0; i < constants::spawn::HOOKS; i++) {
            spawn_location = get_safe_spawn_loc(data.random, _state);
            if (spawn_location.x() == constants::MAX_X) {
                continue; // Couldn't find a safe location
            }
            _state.hooks.emplace_back(spawn_location);
        }
    }

    void ugb_game_name::update_score(const bn::sprite_text_generator& text_generator) {
        _state.score_sprites.clear();
        bn::string<constants::MAX_SCORE_CHARS> score_string = bn::to_string<constants::MAX_SCORE_CHARS>(_state.score);
        text_generator.generate(constants::score::SCORE_X, constants::score::SCORE_Y, score_string, _state.score_sprites);
    }

    bn::string<16> ugb_game_name::title() const {
        return "Eat the food";
    }

    int ugb_game_name::total_frames() const {
        return 600; // 10 seconds
    }

    bool ugb_game_name::victory() const {
        return _state.score == 3;
    }

    mj::game_result ugb_game_name::play([[maybe_unused]] const mj::game_data& data) {

        //GAME LOOP STUFF
        _player.update();
        
        bn::rect player_bounding_box = _player.bounding_box();
        int food_ind = 0;
        for (Food& food : _state.food) {
            bn::rect food_bounding_box = food.bounding_box();
            if (player_bounding_box.intersects(food_bounding_box)) {
                _state.score += 1;
                update_score(data.text_generator);
                // Remove food from vector
                _state.food.erase(_state.food.begin() + food_ind);
                break;
            }
            food_ind++;
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