#include "Team.hpp"

namespace ariel {
    class Team2: public Team {
    public:
        Team2(Character* character): Team(character) {
            this->set_is_cowboy_first(false);
        }
    };

}
