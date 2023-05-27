#include "Cowboy.hpp"
#include <string>

using namespace std;
using namespace ariel;

namespace ariel {
    Cowboy::Cowboy(string const &name, Point pos): Character(name, pos, 'C', 110) {
        this->bullets = 6;
    }

    bool Cowboy::hasboolets() {
        return this->bullets > 0;
    }
    void Cowboy::reload() {
        if(!this->isAlive()) {
            throw runtime_error("is't alive..");
        }
        this->bullets = 6;
    }
    void Cowboy::shoot(Character* other) {
        if (other == nullptr || this == other || !this->isAlive() || !other->isAlive()) {
            throw std::runtime_error("can't shoot");
        }
        if (!this->hasboolets()) {
            return;
        }
        other->hit(10);
        this->bullets--;
    }
}
