#include "cia_oceandive.h"
#include "mj/mj_game_list.h"
#include "cia/cia_shark.h"

namespace
{
    constexpr bn::string_view code_credits[] = {"Ali", "Alex"};
    constexpr bn::string_view graphics_credits[] = {""};
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

MJ_GAME_LIST_ADD(cia::cia_oceandive)
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace cia
{
    cia_oceandive::cia_oceandive([[maybe_unused]] int completed_game, [[maybe_unused]] const mj::game_data &data) : mj::game("cia"),
                                                                                                                    _player(player({0, 20}, 1)),
                                                                                                                    _shark(shark({130, 20}, 1)),
                                                                                                                    _hit(false)
    {
    }

    bn::string<16> cia_oceandive::title() const
    {
        return "Avoid The Shark!";
    }

    int cia_oceandive::total_frames() const
    {
        return 300;
    }

    mj::game_result cia_oceandive::play(const mj::game_data &)
    {
        _player.update();
        _shark.update();

        // If the player intersects with the shark, the player loses.
        if (_player.rect().intersects(_shark.rect()))
        {
            _hit = true;
        }

        return mj::game_result(_hit, false);
    }

    bool cia_oceandive::victory() const
    {
        return !_hit;
    }

    void cia_oceandive::fade_in(const mj::game_data &)
    {
    }

    void cia_oceandive::fade_out(const mj::game_data &)
    {
    }
}