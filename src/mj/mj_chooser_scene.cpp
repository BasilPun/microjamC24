#include "mj_chooser_scene.h"
#include "mj_scene_type.h"

#include "mj_core.h"
#include "mj_game_list.h"
#include "mj_game.h"

#include <bn_unique_ptr.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_fixed_point.h>
// Tutor debug
#include "bn_sprite_items_mj_small_astro.h"

namespace mj {

chooser_scene::chooser_scene(core& core) :
    game_chosen(false),
    _core(core),
    _cursor_idx(_core.sram_data().chosen_game()),
    _cursor(bn::sprite_items::mj_small_astro.create_sprite(12)) {
        bn::backdrop::set_color(bn::color(0, 0, 0));

        auto& text_generator = core.small_text_generator();

        game_data fake_game_data = {
            core.text_generator(),
            core.small_text_generator(),
            core.big_text_generator(),
            core.random(),
            300,
            true // Do not play any music/sounds from the game constructors on the menu screen
        };
        int y = Y_START;
        text_generator.generate({X_START, y}, "All Games", _game_name_sprites);
        y += LINE_HEIGHT;

        bn::unique_ptr<mj::game> game;
        bn::span<game_list::function_type> game_list_entries = game_list::get();

        // If we have an old save file and games have been removed so our saved idx is invalid,
        // default to all games
        if(_cursor_idx >= game_list_entries.size()) {
            _cursor_idx = -1;
        }

        update_cursor_position(game_chosen);

        for(int i = 0; i < game_list_entries.size(); i++) {
            game_list::function_type game_list_entry = game_list_entries[i];
            game.reset(game_list_entry(0, fake_game_data));
            auto title = game->title();
            _game_names.push_back(title);
            text_generator.generate({X_START, y}, title, _game_name_sprites);
            y += LINE_HEIGHT;
        }
        game.reset();
    }

[[nodiscard]] bn::optional<scene_type> chooser_scene::update() {
    bn::optional<scene_type> next_scene = {};

    if(bn::keypad::down_pressed() && !game_chosen) {
        _cursor_idx += 1;
        if(_cursor_idx >= _game_names.size()) {
            _cursor_idx = -1;
        }
    }
    if(bn::keypad::up_pressed() && !game_chosen) {
        _cursor_idx -= 1;
        if(_cursor_idx < -1) {
            _cursor_idx = _game_names.size() - 1;
        }
    }

    if(bn::keypad::down_pressed() && game_chosen) {
        _cursor_idx += 1;
        //stay between chosen game's (index + 1) - (index + 3) -> easy, medium, hard
        if(_cursor_idx > (game_chosen_index+3)) {
            _cursor_idx = (game_chosen_index+1);
        }
    }

    if(bn::keypad::up_pressed() && game_chosen) {
        _cursor_idx -= 1;
        if(_cursor_idx < (game_chosen_index+1)) {
            _cursor_idx = (game_chosen_index+3);
        }
    }

    if(bn::keypad::a_pressed() && !game_chosen) {
        game_chosen = true;
        // show difficulties

        // for each text sprite under chosen game, increase their
        // y val by 3 line heights and insert: easy, med, hard text
        // cursor index could be a good help here
        auto& text_generator = _core.small_text_generator();
        bn::fixed current_y_height = _cursor.y();
        for(bn::sprite_ptr& sprite : _game_name_sprites) {
            if(current_y_height < sprite.y()) {
                sprite.set_y(sprite.y() + LINE_HEIGHT * 3);
            }
        }
        game_chosen_index = _cursor_idx;

        //spawn difficulty text
        current_y_height += LINE_HEIGHT;
        text_generator.generate({X_START + x_tab, current_y_height}, "Easy", _game_difficulty_sprites);
        current_y_height += LINE_HEIGHT;
        text_generator.generate({X_START + x_tab, current_y_height}, "Medium", _game_difficulty_sprites);
        current_y_height += LINE_HEIGHT;
        text_generator.generate({X_START + x_tab, current_y_height}, "Hard", _game_difficulty_sprites);
        
        //tab into difficulties
        _cursor_idx++;
    }
    else if(bn::keypad::a_pressed() && game_chosen) {
        // will start the game. ADD INPUT FOR DIFFICULTY
        auto& sram_data = _core.sram_data();
        sram_data.set_chosen_game(game_chosen_index);
        sram_data.write();
        _core.set_chosen_game(game_chosen_index);
        next_scene.emplace(mj::scene_type::GAME);
    }

    if(bn::keypad::b_pressed() && !game_chosen) {
        next_scene.emplace(mj::scene_type::TITLE);
    }
    else if(bn::keypad::b_pressed() && game_chosen) {
        // get back from locked difficulty selecrtion
        _cursor_idx = game_chosen_index;
        game_chosen = false;
        update_cursor_position(game_chosen);

        //remove difficulty sprites
        _game_difficulty_sprites.clear();

        //move sprites back up
        bn::fixed current_y_height = _cursor.y();
        for(bn::sprite_ptr& sprite : _game_name_sprites) {
            if(current_y_height < sprite.y()) {
                sprite.set_y(sprite.y() - LINE_HEIGHT * 3);
            }
        }
    }

    update_cursor_position(game_chosen);

    return next_scene;
}

void chooser_scene::update_cursor_position(bool _game_chosen) {
    if (!_game_chosen){
        _cursor.set_x(X_START + CURSOR_OFFSET);
        _cursor.set_y(Y_START + ((_cursor_idx + 1) * LINE_HEIGHT));
    }
    else{
        _cursor.set_x(X_START + CURSOR_OFFSET + x_tab);
        _cursor.set_y(Y_START + ((_cursor_idx + 1) * LINE_HEIGHT));
    }
}

}