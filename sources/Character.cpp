#include "Character.hpp"

using namespace ariel;
using namespace std;

Character::Character(string name, const Point& pos, char latter, int hit_point):


name(name), pos(pos), letter(latter), hit_points(hit_point) {}


string Character::print(){
    return "sd";
}

string Character::getName() {
    return this->name;
}

Point Character::getLocation() {
    return this->pos;
}

bool Character::isAlive(){
    return this->hit_points > 0;
}
double Character::distance(Character* other) {
    return this->pos.distance(other->pos);
}
void Character::hit(int damage){
    if(damage < 0) {
        throw invalid_argument("cant be negative");
    }
    if (this->hit_points - damage < 0) {
        this->hit_points = 0;
    } else {
        this->hit_points = this->hit_points - damage;
    }
}

char Character::type() {
    return this->letter;
}