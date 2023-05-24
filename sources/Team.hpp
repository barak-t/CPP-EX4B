#pragma once

#include <vector>
#include <string>

#include "Point.hpp"

//#include "Character.hpp"

using namespace ariel;
using namespace std;

namespace ariel {

    class Character;

    class Team {

    private:
        vector<Character*> characters;

    public:
        Team(Character* character);
        void add(Character* character);
        int stillAlive() const;
        void attack(Team* other);
        void print() const;

        Team() = default;
        Team(const Team &) = default;
        Team &operator=(const Team &) = default;
        Team(Team &&) noexcept = default;
        Team &operator=(Team &&) noexcept = default;
        ~Team();
    };
//}
//
//
//#pragma once


//#include "Team.hpp"

//using namespace std;
//
//namespace ariel {

    class Character {


    public:
        Team* team = nullptr;
        Character();
        Character(string const &name, Point pos);
        void slash(Character* other);
        void shoot(Character* other);
        void move(Character* other);
        string print();

    };

    class Cowboy: public Character {
    public:
        Cowboy(string const &name, Point pos){

        }

    };

    class OldNinja: public Character {
    public:
        OldNinja(string const &name, Point pos){

        }

    };

    class YoungNinja: public Character {
    public:
        YoungNinja(string const &name, Point pos){

        }

    };

    class TrainedNinja: public Character {
    public:
        TrainedNinja(string const &name, Point pos){

        }

    };
}