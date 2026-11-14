#ifndef MJ_CHOOSER_SCENE_H
#define MJ_CHOOSER_SCENE_H

#include <bn_string.h>
#include <bn_vector.h>
#include <bn_sprite_ptr.h>

#include "mj_scene.h"

namespace mj
{

class core;

class chooser_scene final : public scene
{

public:
    explicit chooser_scene(core& core);

    [[nodiscard]] bn::optional<scene_type> update() final;

private:
    core& _core;
    int _cursor_idx;
    bool game_chosen;
    int game_chosen_index;
    bn::sprite_ptr _cursor;
    bn::vector<bn::sprite_ptr, 16*64> _game_name_sprites;
    bn::vector<bn::string<16>, 64> _game_names;
    bn::vector<bn::sprite_ptr, 16*64> _game_difficulty_sprites;

    void update_cursor_position(bool _game_chosen);

    static constexpr int CURSOR_OFFSET = -6;
    static constexpr int X_START = -90;
    static constexpr int Y_START = -70;
    static constexpr int LINE_HEIGHT = 10;
    static constexpr int x_tab = 30;
};

}

#endif