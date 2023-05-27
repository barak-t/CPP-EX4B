#pragma once

#include <vector>
#include <string>

#include "Point.hpp"

#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Ninja.hpp"

#include "Character.hpp"

using namespace ariel;
using namespace std;

namespace ariel {

//    class Character;


    class Team {

    private:
        Character* leader = nullptr;
        vector<Character*> characters;
        void replace_leader();
        Character* get_closest_alive(Team* other);
        bool is_cowboy_first = true;

    protected:
        void set_is_cowboy_first(bool is_c_first){
            this->is_cowboy_first = is_c_first;
        }

    public:
        Team(Character* leader);

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


}