#pragma once

#include "Point.hpp"
#include <string>

using namespace std;

namespace ariel {
    class Team;

    class Character {
    private:
        Team* team = nullptr;
        string name;
        char letter;
        int hit_points;
        Point pos;

    protected:
        void set_pos(Point pos) {
            this->pos = pos;
        }

    public:
        Character();
        Character(string name, const Point& pos, char latter, int hit_point);
        Character (Character&);
        Character(Character&& ) noexcept;
        Character& operator = (const Character&);
        Character& operator = (Character&&) noexcept;
        virtual ~Character() = default;


        virtual string print();
        string getName();
        Point getLocation();
        bool isAlive();
        double distance(Character* other);
        void hit(int damage);
        char type();

        void set_team(Team* team) {
            this->team = team;
        }
        Team* get_team(){
            return this->team;
        }
    };
}
