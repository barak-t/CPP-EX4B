#pragma once


#include "Character.hpp"
#include <string>

using namespace std;

namespace ariel {

    class Ninja: public Character {
    private:
        int speed;

    public:
        Ninja(string name, const Point& pos, int speed, int hit_points);
        void slash(Character* other);
        void move(Character* other);
    };
}
