#include <iostream>

#include "Team.hpp"
#include "limits"
#include <iostream>

using namespace ariel;
using namespace std;

Team::Team(Character* leader){
    if(leader == nullptr) {
        throw runtime_error("Cant be null");
    }
    if(leader->get_team() != nullptr) {
        throw runtime_error("Already have a team");
    }
    this->leader = leader;
    this->characters.push_back(leader);
    leader->set_team(this);
    this->is_cowboy_first = true;
}
void Team::add(Character* character){
    if(character == nullptr) {
        throw runtime_error("Cant be null");
    }
    if(character->get_team() != nullptr) {
        throw runtime_error("Already have a team");
    }
    if(find(this->characters.begin(), this->characters.end(), character) != this->characters.end()) {
        throw runtime_error("Already exist");
    }
    if(this->characters.size() == 10) {
        throw runtime_error("Max 10 characters in team");
    }
    this->characters.push_back(character);
    character->set_team(this);
}
int Team::stillAlive() const{
    int counter = 0;
    for(size_t i=0; i<this->characters.size(); i++){
        if(this->characters.at(i)->isAlive()){
            counter++;
        }
    }
    return counter;
}
void Team::attack(Team* other){
    if(other == nullptr || other == this) {
        throw invalid_argument("can't be null or self");
    }
    if (this->stillAlive() == 0 || other->stillAlive() == 0) {
        throw runtime_error("nobody alive");
    }
    if(!this->leader->isAlive()){
        this->replace_leader();
    }

    Character* victem = this->get_closest_alive(other);
    if(victem == nullptr) {
        return;
    }

    vector<char> types = {'C', 'N'};
    if(!is_cowboy_first){
        types.pop_back();
    }
    for(char type: types) {
        for (Character *attacker: this->characters) {
            if (!attacker->isAlive() || (attacker->type() != type && this->is_cowboy_first)) {
                continue;
            }

            if (attacker->type() == 'C') {
                Cowboy *cboy = dynamic_cast<Cowboy *>(attacker);
                if (cboy->hasboolets()) {
                    cboy->shoot(victem);
                } else {
                    cboy->reload();
                }
            } else if (attacker->type() == 'N') {
                Ninja *nja = dynamic_cast<Ninja *>(attacker);
                if (nja->distance(victem) < 1) {
                    nja->slash(victem);
                } else {
                    nja->move(victem);
                }
            }
            if (!victem->isAlive()) {
                victem = this->get_closest_alive(other);
                if (victem == nullptr) {
                    return;
                }
            }
        }
    }
}

Character* Team::get_closest_alive(Team *team) {
    double min_d = std::numeric_limits<double>::max();
    Character* closest = nullptr;
    for(size_t i=0; i < team->characters.size(); i++){
        double tmp_d = team->characters.at(i)->distance(this->leader);
        if(!team->characters.at(i)->isAlive() || team->characters.at(i) == this->leader){
            continue;
        }
        if(tmp_d < min_d) {
            min_d = tmp_d;
            closest = team->characters.at(i);
        }
    }
    return closest;
}

void Team::replace_leader() {
    Character* closest = this->get_closest_alive(this);

    if(closest == nullptr) {
        throw runtime_error("not replacement leader");
    }
    this->leader = closest;
}
void Team::print() const{

}

Team::~Team() {
    while (this->characters.size() > 0) {
        delete this->characters.back();
        this->characters.pop_back();
    }
}
