#pragma once

#include "Character.hpp"
#include <string>

using namespace std;

namespace ariel {

    class Cowboy: public Character {
    private:
        int bullets;

    public:
        Cowboy(string const &name, Point pos);
        bool hasboolets();
        void reload();
        void shoot(Character* other);

    };
}
