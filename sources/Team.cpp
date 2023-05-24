#include <iostream>

#include "Team.hpp"

using namespace ariel;
using namespace std;

Team::Team(Character* character){
    if(character == nullptr) {
        throw runtime_error("Cant be null");
    }

    if(character->team != nullptr) {
        throw runtime_error("Already have a team");
    }
    this->characters.push_back(character);
    character->team = this;
}
void Team::add(Character* character){
    if(character == nullptr) {
        throw runtime_error("Cant be null");
    }
    if(character->team != nullptr) {
        throw runtime_error("Already have a team");
    }
    if(find(this->characters.begin(), this->characters.end(), character) != this->characters.end()) {
        throw runtime_error("Already exist");
    }
    this->characters.push_back(character);
    character->team = this;
}
int Team::stillAlive() const{
    return 0;
}
void Team::attack(Team* other){

}
void Team::print() const{

}

Team::~Team() {
    while (this->characters.size() > 0) {
        cout << this->characters.size() << endl;
        delete this->characters.back();
        this->characters.pop_back();
    }
}
