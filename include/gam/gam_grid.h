#pragma once
#include <bn_vector.h>
#include <bn_random.h>
#include "gam_ship.h"

namespace gam {

  const int MAX_SHIPS = 3;

  class gam_grid {
    public:
      /**
       * Grid for battleships game
       * 
       * @param columns number of grid columns
       * @param rows number of grid rows
       */
      gam_grid(int columns, int rows);

      /**
       * Creates a new ship with random placement and orientation
       * 
       * @param size number of grid areas ship occupies
       */
      void new_ship(int size, bn::random& rng);

      /**
       * @return number of ships that are not sunk
       */
      int ships_left() const;
      /**
       * @return number of grid columns
       */
      int columns();

      /**
       * @return number of grid rows
       */
      int rows();

      void fire(int column, int row);

    private:
      int _grid_columns;
      int _grid_rows;
      bn::vector<gam::gam_ship, MAX_SHIPS> _ships;
  };
}