#ifndef MJ_CORE_H
#define MJ_CORE_H

#include "bn_random.h"
#include "bn_sprite_text_generator.h"

#include "mj_sram_data.h"

namespace mj
{

class core
{

public:
    core();

    [[nodiscard]] bn::sprite_text_generator& text_generator()
    {
        return _text_generator;
    }

    [[nodiscard]] bn::sprite_text_generator& small_text_generator()
    {
        return _small_text_generator;
    }

    [[nodiscard]] bn::sprite_text_generator& big_text_generator()
    {
        return _big_text_generator;
    }

    [[nodiscard]] bn::random& random()
    {
        return _random;
    }

    [[nodiscard]] mj::sram_data& sram_data()
    {
        return _sram_data;
    }

    void set_chosen_game(int chosen_game) {
        _chosen_game = chosen_game;
    }

    void set_initial_amount_of_games(int amount){
        //set games completed to this amount. games completed in game_scene
    }

    [[nodiscard]] int chosen_game() {
        return _chosen_game;
    }

    void update();

    //setters and getters for completed games.
    void core::set_amount_of_games(int custom_amount_of_games);
    int core::get_amount_of_games();
    //edge cases reset
private:
    bn::sprite_text_generator _text_generator;
    bn::sprite_text_generator _small_text_generator;
    bn::sprite_text_generator _big_text_generator;
    bn::random _random;
    mj::sram_data _sram_data;
    bool _reset_ready = false;
    int _chosen_game = -1;
    int _amount_of_games;

    void _update_keypad();
};

}

#endif
