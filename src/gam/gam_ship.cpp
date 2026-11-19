#include "gam_ship.h"
#include "bn_sprite_items_gam_ship.h"
#include "gam_grid_layout.h"

namespace gam {

    /**
     * Creates ship with input size, orientation and coords
     * @param size how many gridd squares the ship occupies
     * @param horizontal true if the ship is horizontal
     * @param start_x the first x coordinate of this ship
     * @param start_y the first y coordinate of this ship
    */
    gam_ship::gam_ship(int size, bool horizontal, int start_x, int start_y) :
    _ship_horizontal(horizontal) {
        if(size > MAX_SIZE) {
            _ship_size = MAX_SIZE;
        }
        else {
            _ship_size = size;
        }

        if(horizontal) {
            for(int i = 0; i < _ship_size; i++) {
                _ship_x_coords.push_back(start_x + i);

                _ship_sprites.push_back(bn::sprite_items::gam_ship.create_sprite(
                  First_Square_X + (start_x + i) * Square_Size, First_Square_Y + start_y * Square_Size));
            }
            _ship_y_coords.push_back(start_y);
        }
        else {
            for(int i = 0; i < _ship_size; i++) {
                _ship_y_coords.push_back(start_y + i);

                _ship_sprites.push_back(bn::sprite_items::gam_ship.create_sprite(
                    First_Square_X + start_x * Square_Size, First_Square_Y + (start_y + i) * Square_Size));
            }
            _ship_x_coords.push_back(start_x);
        }



    }
    
    /**
     * @return the number of grid squares the ship occupies
    */
    int gam_ship::size() {
        return _ship_size;
    }

    /**
     * @return true if the ship is horizontal. False if vertical
    */
    bool gam_ship::horizontal() {
        return _ship_horizontal;
    }

    /**
     * @return the x coords the ship is located at
    */
    bn::vector<int, MAX_SIZE> gam_ship::x_coords() {
        return _ship_x_coords;
    }
    
    /**
     * @return the y coords the ship is located at
    */
    bn::vector<int, MAX_SIZE> gam_ship::y_coords() {
        return _ship_y_coords;
    }
    
    /**
     * @return true if the ship has been hit. False if not
    */
    bool gam_ship::is_hit() const {
        return _ship_hit; 
    }

    bool gam_ship::try_to_hit(int column, int row) {
        if(_ship_hit) {
            return false;
        }

        for (int i = 0; i < _ship_size; i++) {

            int filled_column;
            int filled_row;

            if(_ship_horizontal) {
                // Row stays the same and column changes
                filled_column = _ship_x_coords[i]; 
                filled_row = _ship_y_coords[0];
            }
            else {
                // Column stays the same while row changes (vertical)
                filled_column = _ship_x_coords[0];
                filled_row = _ship_y_coords[i]; 
            }

            if(column == filled_column && row == filled_row) { // If the ship is hit ..
                _ship_hit = true;

                for (bn::sprite_ptr& sprite : _ship_sprites) {
                    sprite.set_visible(false); // Hides the current square
                }

                return true; // Ship was hit so return true
            }
        }

        return false; // Missed so return false
    }
}