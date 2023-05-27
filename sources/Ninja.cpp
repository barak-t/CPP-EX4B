#include "Ninja.hpp"

using namespace std;
using namespace ariel;

Ninja::Ninja(string name, const Point& pos, int speed, int hit_points): Character(name, pos, 'N', hit_points) {
    this->speed = speed;
}
void Ninja::slash(Character* other){
    if (other == nullptr) {
        throw invalid_argument("Cant be null");
    }
    if (other == this){
        throw runtime_error("no self harm");
    }
    if (!this->isAlive() || !other->isAlive()) {
        throw runtime_error("is dead");
    }
    if (this->distance(other) < 1) {
        other->hit(40);
    }
}
void Ninja::move(Character* other){
    if (other == nullptr) {
        throw invalid_argument("Cant be null");
    }
    if (!this->isAlive()) {
        throw runtime_error("is dead");
    }
    this->set_pos(Point::moveTowards(this->getLocation(),other->getLocation(), this->speed));
}
