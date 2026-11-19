#pragma once

#include <bn_display.h>

namespace ugb {

    namespace constants {

        static constexpr int MAX_ENTITIES = 15;
        static constexpr int MAX_SCORE_CHARS = 24;
        static constexpr int MAX_CHARS = 24;

        static constexpr int MIN_Y = -bn::display::height() / 2;
        static constexpr int MAX_Y = bn::display::height() / 2;
        static constexpr int MIN_X = -bn::display::width() / 2;
        static constexpr int MAX_X = bn::display::width() / 2;

        namespace spawn {
            static constexpr int MAX_ATTEMPTS = 10;
            static constexpr int MIN_DISTANCE = 10;
            static constexpr int PADDING = 8;

            static constexpr int MIN_Y = constants::MIN_Y + PADDING;
            static constexpr int MAX_Y = constants::MAX_Y - PADDING;
            static constexpr int MIN_X = constants::MIN_X + PADDING;
            static constexpr int MAX_X = constants::MAX_X - PADDING;

            static constexpr int HOOKS = 2;
            static constexpr int FOOD = 3;
        }

        namespace score {
            // Score location
            static constexpr int SCORE_X = 70;
            static constexpr int SCORE_Y = -70;
        }

        namespace player {
            static constexpr int INITIAL_X = 40;
            static constexpr int INITIAL_Y = 40;
            static constexpr int SPEED = 1;
        }
    }

}