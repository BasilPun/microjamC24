#include "gam_selector.h"
#include <bn_keypad.h>
#include "bn_sprite_items_gam_player.h"
#include "gam_grid_layout.h"

namespace gam {
  /**
   * Constructor for a grid area selector
   * 
   * @param grid_column selector's column position on the grid
   * @param grid_row selector's row position on the grid
   */
  gam_selector::gam_selector(int start_column, int start_row) : 
  _grid_column(start_column), 
  _grid_row(start_row),
  _selector_sprite(bn::sprite_items::gam_player.create_sprite(
    First_Square_X + start_column * Square_Size, First_Square_Y + start_row * Square_Size))
  
  {
    _selector_sprite.set_scale(0.5);
  };

  /**
   * Checks player's input for movement and fire
   */
  void gam_selector::update(int columns, int rows) {
    if (bn::keypad::left_pressed() && _grid_column > 0) {
      _grid_column--;
    }
    if (bn::keypad::right_pressed() && _grid_column < (columns -1)) {
      _grid_column++;
    }
    if (bn::keypad::up_pressed() && _grid_row > 0) {
      _grid_row--;
    }
    if (bn::keypad::down_pressed() && _grid_row < rows - 1) {
      _grid_row++;
    }

    _selector_sprite.set_position(First_Square_X + _grid_column * Square_Size, First_Square_Y + _grid_row * Square_Size);

  }

  /**
   * @return selector's column position on the grid
   */
  int gam_selector::column() {
    return _grid_column;
  }

  /**
   * @return selector's row position on the grid
   */
  int gam_selector::row() {
    return _grid_row;
  }
}