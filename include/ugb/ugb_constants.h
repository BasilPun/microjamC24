#pragma once

#include <bn_display.h>
#include <bn_fixed.h>

namespace ugb {

    namespace constants {

        static constexpr int MAX_ENTITIES = 15;
        static constexpr int MAX_SCORE_CHARS = 24;
        static constexpr int MAX_CHARS = 24;

        static constexpr int MIN_Y = -bn::display::height() / 2;
        static constexpr int MAX_Y = bn::display::height() / 2;
        static constexpr int MIN_X = -bn::display::width() / 2;
        static constexpr int MAX_X = bn::display::width() / 2;
        
        // Things that can change with difficulty
        // Array values are in the order [easy, normal, hard]
        namespace difficulty {
            static constexpr int REQUIRED_SCORE[3] = {3, 5, 5};
            static constexpr int HOOK_SPAWNS[3] = {2, 4, 6};
            static constexpr bn::fixed HOOK_SPEED[3] = {1, 1.5, 2};
        }

        namespace spawn {
            static constexpr int MAX_ATTEMPTS = 10;
            static constexpr int MIN_DISTANCE = 10;
            static constexpr int PADDING = 8;

            static constexpr int MIN_Y = constants::MIN_Y + PADDING;
            static constexpr int MAX_Y = constants::MAX_Y - PADDING;
            static constexpr int MIN_X = constants::MIN_X + PADDING;
            static constexpr int MAX_X = constants::MAX_X - PADDING;
        }

        namespace score {
            // Score location
            static constexpr int SCORE_X = 70;
            static constexpr int SCORE_Y = -70;
        }

        namespace player {
            static constexpr int INITIAL_X = 0;
            static constexpr int INITIAL_Y = 0;
            static constexpr int SPEED = 2;
        }

        namespace hook {
            static constexpr int MIN_Y = -64;
            static constexpr int MAX_Y = 64;
            static constexpr int X_POSITIONS[] = {-72, 72, -100, 100, -44, 44};
        }
        
    }

}