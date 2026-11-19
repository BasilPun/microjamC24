#pragma once

#include "blo_shark.h"

namespace blo {

    class player {
        public:
            /**
             * player constructor
             */
            player();

            void update(shark& target);

            bool hasSnack() const;
        private:
            bool _has_snack = true;
    };

}
