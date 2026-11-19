#include "nsj_hook_escape.h"
#include "mj/mj_game_list.h"
#include "nsj_Enemy.h"

namespace
{
   constexpr bn::string_view code_credits[] = {"Necobi Williams", "Samantha Jimenez"};
   constexpr bn::string_view graphics_credits[] = {""};
   constexpr bn::string_view sfx_credits[] = {""};
   constexpr bn::string_view music_credits[] = {""};
}

MJ_GAME_LIST_ADD(nsj::nsj_hook_escape)
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace nsj
{

   nsj_hook_escape::nsj_hook_escape([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data &data) : mj::game("nsj"),
                                                                                                                        _player({0, 0}, 2),
                                                                                                                        _enemy(30, -30, 1)
   {
   }

   bn::string<16> nsj_hook_escape::title() const
   {
      return "Avoid the Hook";
   }

   int nsj_hook_escape::total_frames() const
   {
      return 600;
   }

   mj::game_result nsj_hook_escape::play([[maybe_unused]] const mj::game_data &data)
   {

      _player.update();
      _enemy.update();

      // Creates a game result indicating whether the game is finished and whether the title should be hidden early
      // For this game the game should end early if the player has won (if victory returns true)
      // The title is not hidden early (false is passed), so the title disappears at the default time
      mj::game_result result(victory(), false);
      return result;
   }
   // for testing purposes only - changed in wave6
   bool nsj_hook_escape::victory() const
   {
      return _player.out_of_bounds();
   }

   void nsj_hook_escape::fade_in([[maybe_unused]] const mj::game_data &data)
   {
   }

   void nsj_hook_escape::fade_out([[maybe_unused]] const mj::game_data &data)
   {
   }

}